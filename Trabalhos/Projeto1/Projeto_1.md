 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Revisão de Organização de Computadores e Introdução aos microcontroladores

### Projeto Preliminar 1: Cronômetro Digital com Assembly e 8051

 - NOME: Yuri Thadeu Oliveira Costa
    - N° USP: 14754821
 - NOME: Heloisa Oliveira de Carvalho
    - N° USP: 13833960

***
***

### Informações Gerais


### Objetivos

- Compreender a interação entre os elementos e circuitos internos dos microcontroladores, a disposição de sua arquitetura e sua programação, por meio do estudo em "baixo-nível", o qual envolve a manipulação direta de dados bit a bit em registradores e endereços de memória. A família de microcontroladores MCS-51 é usada como exemplo por sua aderência a essa abordagem. Os recursos abordados incluem a manipulação básica de dados, operações com instruções, utilização de pilha e sub-rotinas, manipulação de portas paralelas de entrada e saída, uso de ferramenta de simulação computacional e o desenvolvimento de um projeto prático que explore esses recursos.
- Desenvolvimento de um projeto em linguagem Assembly para 8051 que explore os seguintes recursos no simulador EdSim51: registradores GPR e SFR, contagem de tempo, detecção de eventos, pilha, sub-rotinas, portas de entradas e saídas, e interfaces externas (botões, LEDs e displays de 7 segmentos).

### Requisitos do projeto

Escrever um programa em Assembly para 8051 no simulador EdSim51 que atenda os seguintes requisitos:
 - Ao pressionar um botão/chave, um Display de 7 segmentos deve mostrar a contagem de números na sequência de 0 a 9 em loop (ao chegar em 9, a contagem é reiniciada automaticamente), com intervalo de tempo de 0,25 s.
 - Quando um segundo botão/chave for pressionado, tal ação deve alterar o intervalo de tempo da contagem deste mesmo display para 1s, isto é, a contagem de 0 a 9 em loop continuará, porém, o display passará a contar em um período de tempo mais lento.
 - Os botões usados foram o SW0, para a contagem de 0,25s e o botão SW1 para a contagem de 1s
 - Caso SW0 seja pressionado novamente, a contagem de números retorna ao intervalo de tempo de 0,25s e vice-versa, mantendo a execução do programa em loop.
 - Ao executar o programa pela primeira vez (após clicar em “Run”), a contagem não se inicia automaticamente e o display estará desligado. Somente quando uma das chaves SW0 ou SW1 for pressionada é que a contagem se inicia e o display passa a mostrar os valores de 0 a 9 nos intervalos de tempo mencionados anteriormente atribuídos para cada chave.
 - Usar sub-rotinas de delay para gerar as bases de tempo do cronômetro e promover a mudança de período de tempo solicitada, bem como instruções condicionais de verificação de acionamento das chaves.
 - Usar um dos displays de 7 segmentos e dois switches disponíveis no EdSim51.

***
***
### Informações úteis

Utilizaremos o display número 3, configurado a partir da porta P3, disponível no simulador EdSim51DI. Para isso, é importante compreender alguns aspectos sobre o funcionamento do display de 7 segmentos configurado a partir da porta P1. Primeiramente, ele possui um comportamento do tipo PULL-UP, o que significa que seus LEDs permanecem apagados quando o valor lógico é 1. Além disso, é essencial entender a distribuição dos LEDs, conforme mostrado abaixo. Outras informações detalhadas sobre o display podem ser encontradas no arquivo [Informações de Atividades](.\Atividades\Info_atv.md), disponível no tópico da Atividade 5.



``` 
                 Display de 7 segmentos
                       ___a___  
                     ||-------||  
                    f||       ||b  
                     ||___g___||  
                     ||-------||  
                    e||       ||c  
                     ||___d___||  
                       -------   + DP  

Segmentos conectados aos LEDs da PORTA P1  
      DP g f e d c b a  
 P1 = 7  6 5 4 3 2 1 0  
 bit = 1 (apagado) e bit = 0 (acende)

             TABELA DO DISPLAY 7 SEGMENTOS

| DIG | DP  | G   | F   | E   | D   | C   | B   | A   | HEX |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 1   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | C0  |
| 1   | 1   | 1   | 1   | 1   | 1   | 0   | 0   | 1   | F9  |
| 2   | 1   | 0   | 1   | 0   | 0   | 1   | 0   | 0   | A4  |
| 3   | 1   | 0   | 1   | 1   | 0   | 0   | 0   | 0   | B0  |
| 4   | 1   | 0   | 0   | 1   | 1   | 0   | 0   | 1   | 99  |
| 5   | 1   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 92  |
| 6   | 1   | 0   | 0   | 0   | 0   | 0   | 1   | 0   | 82  |
| 7   | 1   | 1   | 1   | 1   | 1   | 0   | 0   | 0   | F8  |
| 8   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 80  |
| 9   | 1   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 90  |

```

### Código construido para o trabalho

Os comentários no código fornecem explicações detalhadas sobre cada seção e instrução, facilitando o entendimento da lógica implementada. Eles ajudam a acompanhar o fluxo do programa, desde a inicialização até a execução das sub-rotinas de delay e a manipulação dos botões e do display de 7 segmentos. Certifique-se de lê-los com atenção para compreender como cada parte do código contribui para o funcionamento do cronômetro digital.


```asm
ORG 00h

MAIN:
   SETB P0.7             ; CHIP SELECT habilita o display para comunicação
   SETB P3.3
   SETB P3.4             ; SELECIONA O DISPLAY 3 (11)
   MOV P2, #0FFh         ; Desliga SW0 e SW1 no início do programa (seta tudo em 1)

; Aguarda botão ser pressionado
ESPERA_INICIO:
   MOV A, P2
   JB ACC.0, TESTA_SW1   ; Se o 
   MOV 50h, #0           ; SW0 -> rápido (0,25s)
   JMP INICIO

TESTA_SW1:
   JB ACC.1, ESPERA_INICIO
   MOV 50h, #1           ; SW1 -> lento (1s)

ORG 33h
INICIO:
   CALL CHECK_BOTOES     ; Verifica os botões e ajusta o tempo
   OBS: Certifique-se de prefixar os valores hexadecimais que começam com letras (como "A4h" ou "F9h") com "0" (por exemplo, "0A4h" ou "0F9h") para evitar problemas de interpretação no simulador EdSim51DI.

   MOV A, #0C0h          ; INICIA EM ZERO 
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #0F9h          ; VAI PARA 1
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #0A4h          ; VAI PARA 2
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #0B0h          ; VAI PARA 3
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #99h           ; VAI PARA 4
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #92h           ; VAI PARA 5
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #82h           ; VAI PARA 6
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #0F8h          ; VAI PARA 7
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #80h           ; VAI PARA 8
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   MOV A, #90h           ; VAI PARA 9
   MOV P1, A             ; MANDA O VALOR DE A PARA P1
   CALL DELAY            ; Chama a função de delay (dinâmico)

   JMP INICIO            ; Repete a contagem de 0 a 9

; -----------------------------------------------
; Verifica SW0 ou SW1
; -----------------------------------------------
CHECK_BOTOES:
   PUSH ACC
   MOV A, P2
   JNB ACC.0, SET_RAPIDO
   JNB ACC.1, SET_LENTO
   POP ACC
   RET

;OBS: Vou usar 50h (SFRs) como variável de controle porque vi em um exemplo usando ele em vez de R0 (GPRs), dado que pediu pra usar um SFRs

SET_RAPIDO:
   MOV 50h, #0           ; SW0 -> rápido
   POP ACC
   RET

SET_LENTO:
   MOV 50h, #1           ; SW1 -> lento
   POP ACC
   RET

; -----------------------------------------------
; Módulo de delay com controle de tempo (curto e longo)
; -----------------------------------------------

DELAY:
   CALL CHECK_BOTOES     ; Verifica qual botão foi pressionado
   MOV A, 50h            ; Verifica o valor em 50h para determinar o delay
   JB ACC.0, DELAY_LONGO ; Se SW0 foi pressionado (modo lento)
   CALL DELAY_CURTO      ; Caso contrário, chama o delay rapido
   RET                   ; Retorna para a execução do programa

; -----------------------------------------------
; Delay curto (2 * 5 * 100 * 250 = 250.000 us ou 0,25 segundos)
; -----------------------------------------------
DELAY_CURTO:
   MOV R2, #5               ; Número de repetições para loop curto (5)
   LOOP_10:
      MOV R3, #100          ; Número de repetições para loop intermediário (100)
   LOOP_100:
      MOV R4, #250          ; Número de repetições para loop interno (250)
   LOOP_250:
      DJNZ R4, LOOP_250     ; Decrementa R4 e repete até R4 chegar a 0
      DJNZ R3, LOOP_100     ; Decrementa R3 e repete até R3 chegar a 0
      DJNZ R2, LOOP_10      ; Decrementa R2 e repete até R2 chegar a 0
      RET                   ; Retorna para O DELAY

; -----------------------------------------------
; Delay longo (2 * 20 * 100 * 250 = 1.000.000 us ou 1 segundo)
; -----------------------------------------------
DELAY_LONGO:
   MOV R2, #20               ; Número de repetições para loop longo (20)
   LOOP_40:
      MOV R3, #100           ; Número de repetições para loop intermediário (100)
   LOOP_100_long:
      MOV R4, #250           ; Número de repetições para loop interno (250)
   LOOP_250_long:
      DJNZ R4, LOOP_250_long ; Decrementa R4 e repete até R4 chegar a 0
      DJNZ R3, LOOP_100_long ; Decrementa R3 e repete até R3 chegar a 0
      DJNZ R2, LOOP_40       ; Decrementa R2 e repete até R2 chegar a 0
      RET                    ; Retorna para O DELAY

END
```
