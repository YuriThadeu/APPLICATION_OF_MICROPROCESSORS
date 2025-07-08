#include <Wire.h>                 // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>   // Biblioteca para controlar o LCD via I2C
#include <ESP32Servo.h>          // Biblioteca para controle de servos no ESP32

// 🔷 Definições de pinos de saída
#define LED_PIN       16          // Pino do LED indicador
#define BUZZER_PIN    17          // Pino do buzzer sonoro

// 🔷 Definições de botões de entrada
#define BTN_QUEDA     25          // Botão para simular queda
#define BTN_GAS       26          // Botão para simular vazamento de gás
#define BTN_REMEDIO   27          // Botão para hora do remédio
#define BTN_DESLIGAR  14          // Botão para desligar o alarme

// 🔷 Definições de pinos dos servos
#define SERVO_JANELA_PIN 18       // Servo para abertura da janela
#define NUM_CAIXAS 8              // Quantidade de compartimentos de remédios

// 🔷 Inicialização do LCD no endereço I2C padrão
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 🔷 Vetor para os 8 servos das caixas
Servo servosCaixa[NUM_CAIXAS];
Servo servoJanela;                // Servo da janela

// 🔷 Mapeamento dos pinos dos servos das caixas
int pinosCaixas[NUM_CAIXAS] = {
  4, 5, 12, 13, 19, 23, 32, 33
};

// 🔷 Enumeração para os tipos de alerta possíveis
enum Alerta {
  NENHUM = 0,
  REMEDIO = 1,
  GAS = 2,
  QUEDA = 3
};

Alerta alertaAtivo = NENHUM;      // Variável que indica qual alerta está ativo
String end_caixa = "01101001";    // Bitmap indicando quais caixas abrir

void setup() {
  Serial.begin(115200);           // Inicializa a comunicação serial

  pinMode(LED_PIN, OUTPUT);       // Configura pinos como saída
  pinMode(BUZZER_PIN, OUTPUT);

  // Configura botões como entradas com pull-up interno
  pinMode(BTN_QUEDA, INPUT_PULLUP);
  pinMode(BTN_GAS, INPUT_PULLUP);
  pinMode(BTN_REMEDIO, INPUT_PULLUP);
  pinMode(BTN_DESLIGAR, INPUT_PULLUP);

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Inicializa os 8 servos das caixas
  for (int i = 0; i < NUM_CAIXAS; i++) {
    servosCaixa[i].attach(pinosCaixas[i]);
  }

  servoJanela.attach(SERVO_JANELA_PIN);  // Inicializa o servo da janela

  Serial.println("Sistema Ativo.");
  lcd.setCursor(0, 0);
  lcd.print("Sistema Ativo");
}

void loop() {
  // Checa botão de gás; abre a janela imediatamente
  if (digitalRead(BTN_GAS) == LOW) {
    abrirJanela();                // abre sempre, mesmo que outro alerta esteja ativo
    if (alertaAtivo < GAS) {      // prioriza caso seja mais importante
      iniciarAlerta(GAS);
    }
  }

  // Checa botão de queda
  if (digitalRead(BTN_QUEDA) == LOW) {
    if (alertaAtivo < QUEDA) {    // prioriza caso seja mais importante
      iniciarAlerta(QUEDA);
    }
  }
  // Checa botão de remédio
  else if (digitalRead(BTN_REMEDIO) == LOW) {
    if (alertaAtivo < REMEDIO) {
      iniciarAlerta(REMEDIO);
    }
  }

  // Se algum alerta está ativo, executa o som/luz correspondente
  if (alertaAtivo != NENHUM) {
    executarAlerta(alertaAtivo);

    // Verifica botão de desligar para encerrar o alerta
    if (digitalRead(BTN_DESLIGAR) == LOW) {
      pararAlerta();
    }
  }
}

// ----------------------------------------------------------

// Inicializa o alerta com mensagens no LCD e Serial
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

// Executa sons e luzes de acordo com o tipo de alerta
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

// Para o alerta ativo e abre as caixas caso seja de remédio
void pararAlerta() {
  Serial.println("Alerta encerrado.");
  lcd.clear();
  lcd.print("Alerta parado");

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  if (alertaAtivo == REMEDIO) {
    abrirCaixasSelecionadas();   // abre as caixas conforme end_caixa
  }

  alertaAtivo = NENHUM;

  delay(2000);
  lcd.clear();
  lcd.print("Sistema ativado");
}

// Percorre a string end_caixa e aciona os servos das caixas indicadas
void abrirCaixasSelecionadas() {
  Serial.print("Abrindo caixas: ");
  for (int i = 0; i < NUM_CAIXAS; i++) {
    int bitPos = NUM_CAIXAS - 1 - i;  // bits mais significativos à esquerda
    if (end_caixa.charAt(bitPos) == '1') {
      Serial.print(i);
      Serial.print(" ");
      servosCaixa[i].write(90);       // gira 90°
      delay(1000);
      servosCaixa[i].write(0);        // volta à posição inicial
    }
  }
  Serial.println();
}

// Abre a janela girando o servo da cortina 5 vezes
void abrirJanela() {
  Serial.println("Abrindo janela (5 voltas).");
  for (int i = 0; i < 5; i++) {
    servoJanela.write(180);
    delay(500);
    servoJanela.write(0);
    delay(500);
  }
}

// Retorna o texto correspondente ao alerta ativo
String alertaToString(Alerta tipo) {
  switch (tipo) {
    case QUEDA: return "Queda Relatada";
    case GAS: return "Vazamento de Gas";
    case REMEDIO: return "Hora do Remedio";
    default: return "Nenhum";
  }
}
