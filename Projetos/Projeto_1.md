 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Revisão de Organização de Computadores e Introdução aos microcontroladores

### Projeto Preliminar 1: Cronômetro Digital

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
 - Ao pressionar um botão/chave (por ex.: SW0), um Display de 7 segmentos deve mostrar a contagem de números na sequência de 0 a 9 em loop (ao chegar em 9, a contagem é reiniciada automaticamente), com intervalo de tempo de 0,25 s.
 - Quando um segundo botão/chave (por ex. SW1) for pressionado, tal ação deve alterar o intervalo de tempo da contagem deste mesmo display para 1s, isto é, a contagem de 0 a 9 em loop continuará, porém, o display passará a contar em um período de tempo mais lento.
 - Caso SW0 seja pressionado novamente, a contagem de números retorna ao intervalo de tempo de 0,25s e vice-versa, mantendo a execução do programa em loop.
 - Ao executar o programa pela primeira vez (após clicar em “Run”), a contagem não se inicia automaticamente e o display estará desligado. Somente quando uma das chaves SW0 ou SW1 for pressionada é que a contagem se inicia e o display passa a mostrar os valores de 0 a 9 nos intervalos de tempo mencionados anteriormente atribuídos para cada chave.
 - Usar sub-rotinas de delay para gerar as bases de tempo do cronômetro e promover a mudança de período de tempo solicitada, bem como instruções condicionais de verificação de acionamento das chaves.
 - Usar um dos displays de 7 segmentos e dois switches disponíveis no EdSim51.

***
***

