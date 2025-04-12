 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 3 - Análise de set de instruções, pinout e recursos de microcontroladores

###  Atividade Semanal – Aula 3

 - NOME: Yuri Thadeu Oliveira Costa   
 - N° USP: 14754821

***
***

1 - No simulador EdSim51, digite e execute (clicando em “Assm”) as instruções abaixo:

<div style="text-align: center;">
    <strong>
        MOV R0, #22h<br>
        MOV 00h, #22h
    </strong>
</div><br>

Qual a diferença entre as duas instruções acima? Tente refletir porque possuem ciclos de máquina diferentes se a operação é realizada na mesma posição de memória RAM (00h ou R0 usa o mesmo espaço).

    A instrução "MOV A, #22h" move o valor imediato 22h R0, já a instrução "MOV 00h, #22h" move o valor imediato 22h para o endereço/posição de memoria 00h. Mesmo indicando o mesmo lugar, acessar a memória demanda mais tempo do que um registrador, então a primeira instrução seria mais rápida. 

<div style="text-align: center;">
    <strong>
        MOV A, #22h<br>
        MOV ACC, #22h
    </strong>
</div><br>

Qual a diferença entre as duas instruções acima? Tente refletir sobre a diferença de usar A ou ACC e sobre porque possuem ciclos de máquina diferentes se a operação realizada é a mesma.

    Assim como no primeiro exemplo, os dois comandaos fazem essencialmente a mesma coisa. Entretanto nesse caso, A é o nome direto de um registrador e ACC é o nome do endereço na memoria do registrador, como comentei anteriormente, acessar a memória diretamente demanda mais tempo, ou ciclos de maquina, que acessar o registrador.

***

2 - A Figura abaixo mostra um microcontrolador genérico de 8 bits com 4 registradores internos à CPU, os quais são: Instruction Register (IR), Program Counter (PC), Accumulator (ACC) e Data Pointer (DPTR). Baseado na Figura abaixo, responda às questões com verdadeiro (V) ou Falso (F):

<div style="text-align: center;">
    <img src="./img_atv3.jpg" alt="Microcontrolador Genérico">
</div><br>

    (F) Trata-se de um microcontrolador de arquitetura Harvard.
    (V) A memória EEPROM é de 4Kbytes e armazena as instruções que comandam o microcontrolador.
    (F) A memória SRAM é de 512 bytes e armazena dados voláteis
    (F) O registrador IR tem a função de armazenar a instrução lida da memória SRAM.
    (V) Para esse microcontrolador, o registrador IR deve ser de 8 bits
    (V) O registrador PC armazena o endereço da instrução lida da memória EEPROM.
    (F) Para esse microcontrolador, o registrador PC deve ser de 10 bits.
    (V) Para esse microcontrolador, o registrador ACC deve ser de 8 bits.
    (F) O registrador DPTR é um ponteiro que aponta para a última instrução lida da memória.
    (F) Para esse microcontrolador, o registrador DPTR deve ser de 10 bits.

***

3 - Quanto às portas paralelas de um microcontrolador:

    (F) São somente de entrada.
    (F) São somente de saída.
    (V) Cada palavra (A, B, C, P1, P2, P3…) pode ser configurada como entrada ou saída.
    (V) Cada bit pode ser configurado como entrada ou saída.
    (V) Cada palavra (A, B, C... P1, P2, P3…) pode ser configurada como entrada, saída ou bidirecional.
    (V) Cada bit pode ser configurado como entrada, saída ou bidirecional.