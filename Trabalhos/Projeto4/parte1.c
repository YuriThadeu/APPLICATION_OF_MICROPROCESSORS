// Projeto 04 - Parte 01 - Controle PWM de LED RGB
// Este código demonstra o controle de brilho de um LED RGB usando a função analogWrite no ESP32.

#include <Arduino.h> // Inclui a biblioteca padrão do Arduino, essencial para funções básicas do ESP32.

// Definição dos pinos GPIO conectados a cada cor do LED RGB.
// Um LED RGB comum possui terminais para Vermelho (R), Verde (G), Azul (B) e um Cátodo Comum (GND).
const int ledR = 27; // Pino GPIO para o LED Vermelho.
const int ledG = 26; // Pino GPIO para o LED Verde.
const int ledB = 25; // Pino GPIO para o LED Azul.

// Variável para o valor de incremento fixo.
// Este valor define o passo de aumento do brilho a cada iteração do loop.
const int incr = 5;

// Variáveis para armazenar o valor atual de brilho (duty cycle) de cada cor.
// O valor varia de 0 (desligado) a 255 (brilho máximo), correspondendo a uma resolução de 8 bits.
int atualR = 0; // Brilho atual do LED Vermelho.
int atualG = 0; // Brilho atual do LED Verde.
int atualB = 0; // Brilho atual do LED Azul.

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial a uma taxa de 115200 bps.
                       // Usada para depuração e para exibir os valores de brilho no Monitor Serial.

  // Configura os pinos do LED como saída.
  // pinMode(pino, MODO) define a função de um pino (INPUT, OUTPUT, INPUT_PULLUP).
  pinMode(ledR, OUTPUT); // Define o pino do LED Vermelho como saída.
  pinMode(ledG, OUTPUT); // Define o pino do LED Verde como saída.
  pinMode(ledB, OUTPUT); // Define o pino do LED Azul como saída.

  Serial.println("Controle PWM RGB alternativo iniciado."); // Mensagem de inicialização no Monitor Serial.
}

void loop() {
  // Atualiza o valor de brilho para cada cor com incrementos distintos.
  // Isso cria um padrão de variação de brilho independente para cada cor.
  atualR += incr * 7; // Incrementa o brilho do LED Vermelho com um passo maior.
  atualG += incr * 5; // Incrementa o brilho do LED Verde com um passo intermediário.
  atualB += incr * 3; // Incrementa o brilho do LED Azul com um passo menor.

  // Verifica se o valor de brilho ultrapassou o máximo (255) e o reinicia para 0 se necessário.
  // Isso garante que o brilho varie em um ciclo contínuo (0-255-0).
  if (atualR > 255) atualR = 0;
  if (atualG > 255) atualG = 0;
  if (atualB > 255) atualB = 0;

  // Usa analogWrite para aplicar o valor de brilho (simulando PWM) nos pinos do LED.
  // analogWrite(pino, valor) define o duty cycle (0-255) para o pino especificado.
  // No ESP32, analogWrite é implementado usando o módulo LEDC, mas com uma interface mais simples.
  analogWrite(ledR, atualR); // Aplica o brilho atual ao LED Vermelho.
  analogWrite(ledG, atualG); // Aplica o brilho atual ao LED Verde.
  analogWrite(ledB, atualB); // Aplica o brilho atual ao LED Azul.

  // Exibe os valores de brilho (em porcentagem) e o incremento aplicado no Monitor Serial.
  Serial.print("Vermelho: ");
  Serial.print(atualR * 100 / 255); // Converte o valor de 0-255 para uma porcentagem de 0-100%.
  Serial.print(" | Incremento: ");
  Serial.println(incr * 7); // Exibe o incremento específico para o LED Vermelho.

  Serial.print("Verde: ");
  Serial.print(atualG * 100 / 255);
  Serial.print(" | Incremento: ");
  Serial.println(incr * 5); // Exibe o incremento específico para o LED Verde.

  Serial.print("Azul: ");
  Serial.print(atualB * 100 / 255);
  Serial.print(" | Incremento: ");
  Serial.println(incr * 3); // Exibe o incremento específico para o LED Azul.

  delay(100); // Pequeno atraso em milissegundos para controlar a velocidade das transições de brilho.
              // Um atraso menor resulta em transições mais rápidas, e vice-versa.
}