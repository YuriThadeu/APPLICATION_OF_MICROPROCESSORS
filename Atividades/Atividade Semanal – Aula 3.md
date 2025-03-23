 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 3 - Análise de set de instruções, pinout e recursos de microcontroladores

###  Atividade Semanal – Aula 3

 - NOME: Yuri Thadeu Oliveira Costa   
 - N° USP: 14754821

***

1 - No simulador EdSim51, digite e execute (clicando em “Assm”) as instruções abaixo:

<div style="text-align: center;">
    <strong>
        MOV R0, #22h<br>
        MOV 00h, #22h
    </strong>
</div><br>

Qual a diferença entre as duas instruções acima? Tente refletir porque possuem ciclos de máquina diferentes se a operação é realizada na mesma posição de memória RAM (00h ou R0 usa o mesmo espaço).

<div style="text-align: center;">
    <strong>
        MOV A, #22h<br>
        MOV ACC, #22h
    </strong>
</div><br>

Qual a diferença entre as duas instruções acima? Tente refletir sobre a diferença de usar A ou ACC e sobre porque possuem ciclos de máquina diferentes se a operação realizada é a mesma.

2 - A Figura abaixo mostra um microcontrolador genérico de 8 bits com 4 registradores internos à CPU, os quais são: Instruction Register (IR), Program Counter (PC), Accumulator (ACC) e Data Pointer (DPTR). Baseado na Figura abaixo, responda às questões com verdadeiro (V) ou Falso (F):

<div style="text-align: center;">
    <img src="C:\Users\yurit\Desktop\USP\VSCode\APPLICATION_OF_MICROPROCESSORS\APPLICATION_OF_MICROPROCESSORS\Atividades\img_atv3.png" alt=" ">
</div><br>

    ( ) Trata-se de um microcontrolador de arquitetura Harvard.
    ( ) A memória EEPROM é de 4Kbytes e armazena as instruções que comandam o microcontrolador.
    ( ) A memória SRAM é de 512 bytes e armazena dados voláteis
    ( ) O registrador IR tem a função de armazenar a instrução lida da memória SRAM.
    ( ) Para esse microcontrolador, o registrador IR deve ser de 8 bits
    ( ) O registrador PC armazena o endereço da instrução lida da memória EEPROM.
    ( ) Para esse microcontrolador, o registrador PC deve ser de 10 bits.
    ( ) Para esse microcontrolador, o registrador ACC deve ser de 8 bits.
    ( ) O registrador DPTR é um ponteiro que aponta para a última instrução lida da memória.
    ( ) Para esse microcontrolador, o registrador DPTR deve ser de 10 bits.


3 - Quanto às portas paralelas de um microcontrolador:

    ( ) São somente de entrada.
    ( ) São somente de saída.
    ( ) Cada palavra (A, B, C, P1, P2, P3…) pode ser configurada como entrada ou saída.
    ( ) Cada bit pode ser configurado como entrada ou saída.
    ( ) Cada palavra (A, B, C... P1, P2, P3…) pode ser configurada como entrada, saída ou bidirecional.
    ( ) Cada bit pode ser configurado como entrada, saída ou bidirecional.