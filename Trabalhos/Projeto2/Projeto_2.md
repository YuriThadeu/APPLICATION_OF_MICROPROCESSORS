 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Microcontroladores PIC e Programação em Linguagem C

### Projeto 2: Cronômetro Digital com Timer e Interrupções

 - NOME: Yuri Thadeu Oliveira Costa
    - N° USP: 14754821
 - NOME: Heloisa Oliveira de Carvalho
    - N° USP: 13833960

***
***

### Informações Gerais

Esta atividade prática versa sobre o desenvolvimento do mesmo projeto do cronômetro digital (Projeto 1). A diferença é que agora o projeto deverá ser desenvolvido em Linguagem C, utilizando o microcontrolador PIC18F4550. É importante também destacar que, ao contrário do projeto anterior, temporizadores e interrupções serão utilizados para contagem de tempo e mudança das bases de contagem a partir do botão pressionado. As semelhanças que se mantiveram são o uso de display de 7 segmentos, a contagem de 0 a 9 em loop, uso de duas bases de tempo, e a mudança de bases de tempo por meio de botões. O projeto proposto permitirá comparações entre as características de microcontroladores de 8 bits CISC vs. RISC, linguagem de baixo nível Assembly com programas em linguagem C, e implementação prática vs. simulador.


### Objetivos

- Explorar conceitos relacionados aos microcontroladores de 8 bits de arquitetura Harvard e set de instruções RISC.
- Exercitar o uso do software compilador e a programação básica de registradores SFR, I/O, e periféricos dos microcontroladores PIC18F em linguagem C.
- Desenvolver um projeto prático implementando funcionalidades de microcontroladores em linguagem C, tais como timers, interrupções, I/O e interface com display de 7 segmentos, utilizando o PIC18F4550.
- Implementar o projeto no kit EasyPIC v7 e realizar simulações por meio do software SimulIDE.

### Requisitos do projeto

Criar um projeto no compilador MikroC PRO for PIC e escrever um programa em linguagem C que implemente os requisitos a seguir:
- Quando um botão conectado na porta RB0 for pressionado, um display de 7 segmentos ligado na Porta D deve contar (de 0 a 9 em loop) com período de 1s.
- Quando um segundo botão, conectado na porta RB1, for pressionado, o mesmo display de 7 segmentos deve contar com período de 0,25s.
- O display se inicia desligado e a contagem começa somente quando qualquer um dos botões é pressionado.
- Utilizar o temporizador TMR0 com Interrupção externa (nos botões) para gerar as bases de tempo da contagem e provocar suas mudanças. Importa destacar que os botões (chaves) considerados agora são aqueles do tipo momentâneo, ou seja, deve-se pressionar e soltar logo em seguida pois o que conta para acionamento da interrupção é a mudança de borda.
- A frequência do clock do PIC deve ser de 8 MHz (cristal externo HS).



***
***