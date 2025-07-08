#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// 🔷 Saídas
#define LED_PIN       16
#define BUZZER_PIN    17

// 🔷 Botões
#define BTN_QUEDA     25
#define BTN_GAS       26
#define BTN_REMEDIO   27
#define BTN_DESLIGAR  14

// 🔷 Servos
#define SERVO_JANELA_PIN 18  // Servo da janela no GPIO18
#define NUM_CAIXAS 8         // Número de compartimentos/caixas

// 🔷 LCD I2C
// SDA: GPIO21, SCL: GPIO22

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servosCaixa[NUM_CAIXAS];
Servo servoJanela;

int pinosCaixas[NUM_CAIXAS] = {
  4, 5, 12, 13, 19, 23, 32, 33
};

enum Alerta {
  NENHUM = 0,
  REMEDIO = 1,
  GAS = 2,
  QUEDA = 3
};

Alerta alertaAtivo = NENHUM;
String end_caixa = "01101001";  // exemplo inicial

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(BTN_QUEDA, INPUT_PULLUP);
  pinMode(BTN_GAS, INPUT_PULLUP);
  pinMode(BTN_REMEDIO, INPUT_PULLUP);
  pinMode(BTN_DESLIGAR, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  for (int i = 0; i < NUM_CAIXAS; i++) {
    servosCaixa[i].attach(pinosCaixas[i]);
  }

  servoJanela.attach(SERVO_JANELA_PIN);

  Serial.println("Sistema Ativo.");
  lcd.setCursor(0, 0);
  lcd.print("Sistema Ativo");
}

void loop() {
  // Gás: abre janela sempre
  if (digitalRead(BTN_GAS) == LOW) {
    abrirJanela();  // sempre abre
    if (alertaAtivo < GAS) {
      iniciarAlerta(GAS);
    }
  }

  // Verifica botões para maiores prioridades
  if (digitalRead(BTN_QUEDA) == LOW) {
    if (alertaAtivo < QUEDA) {
      iniciarAlerta(QUEDA);
    }
  } else if (digitalRead(BTN_REMEDIO) == LOW) {
    if (alertaAtivo < REMEDIO) {
      iniciarAlerta(REMEDIO);
    }
  }

  // Executa o alerta ativo em loop
  if (alertaAtivo != NENHUM) {
    executarAlerta(alertaAtivo);

    // Verifica botão de desligar
    if (digitalRead(BTN_DESLIGAR) == LOW) {
      pararAlerta();
    }
  }
}

// ----------------------------------------------------------

void iniciarAlerta(Alerta tipo) {
  alertaAtivo = tipo;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alerta: ");
  lcd.setCursor(0, 1);
  lcd.print(alertaToString(tipo));

  Serial.print("Alerta iniciado: ");
  Serial.println(alertaToString(tipo));
}

// ----------------------------------------------------------

void executarAlerta(Alerta tipo) {
  switch (tipo) {
    case QUEDA:
      tone(BUZZER_PIN, 1000);
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(LED_PIN, LOW);
      delay(500);
      break;

    case GAS:
      tone(BUZZER_PIN, 2000);
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      noTone(BUZZER_PIN);
      digitalWrite(LED_PIN, LOW);
      delay(100);
      break;

    case REMEDIO:
      for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 3; i++) {
          tone(BUZZER_PIN, 1500);
          digitalWrite(LED_PIN, HIGH);
          delay(200);
          noTone(BUZZER_PIN);
          digitalWrite(LED_PIN, LOW);
          delay(200);
        }
        delay(1000);
      }
      break;

    default:
      break;
  }
}

// ----------------------------------------------------------

void pararAlerta() {
  Serial.println("Alerta encerrado.");
  lcd.clear();
  lcd.print("Alerta parado");

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  if (alertaAtivo == REMEDIO) {
    abrirCaixasSelecionadas();
  }

  alertaAtivo = NENHUM;

  delay(2000);
  lcd.clear();
  lcd.print("Sistema ativado");
}

// ----------------------------------------------------------

void abrirCaixasSelecionadas() {
  Serial.print("Abrindo caixas: ");
  for (int i = 0; i < NUM_CAIXAS; i++) {
    int bitPos = NUM_CAIXAS - 1 - i;  // MSB à esquerda
    if (end_caixa.charAt(bitPos) == '1') {
      Serial.print(i);
      Serial.print(" ");
      servosCaixa[i].write(90);
      delay(1000);
      servosCaixa[i].write(0);
    }
  }
  Serial.println();
}

// ----------------------------------------------------------

void abrirJanela() {
  Serial.println("Abrindo janela (5 voltas).");
  for (int i = 0; i < 5; i++) {
    servoJanela.write(180);
    delay(500);
    servoJanela.write(0);
    delay(500);
  }
}

// ----------------------------------------------------------

String alertaToString(Alerta tipo) {
  switch (tipo) {
    case QUEDA: return "Queda Relatada";
    case GAS: return "Vazamento de Gas";
    case REMEDIO: return "Hora do Remedio";
    default: return "Nenhum";
  }
}
