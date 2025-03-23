 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 2 - Microcontoladores e Revisão de Org. de Computadores

###  Atividade Semanal – Aula 2

 - NOME: Yuri Thadeu Oliveira Costa   
 - N° USP: 14754821

***

1 - Assinale V para verdadeiro e F para falso nas afirmações abaixo:

    (F) No modelo de Von Neumann, o microprocessador segue as instruções armazenadas na memória ROM (programas), lê as entradas e envia comandos sobre os canais de saída, alterando as informações contidas na memória RAM.
<!--
No modelo de Von Neumann, tanto as instruções quanto os dados são armazenados na mesma memória, geralmente RAM, e o microprocessador lê as instruções e dados dessa memória. Memoriam ROM geralmente é usada para o firmware.
-->
    (F) Os registradores Special Function Registers localizam-se sempre internos à CPU.
<!--
FAlso, podem ser encontrados na memoriam RAM também 
-->
    (F) O ciclo de máquina é composto pelo ciclo de busca mais o ciclo de execução cada qual demorando um pulso de clock.
<!--
O ciclo de máquina é composto pelo ciclo de busca (fetch) e o ciclo de execução (execute), mas cada um desses ciclos pode demorar mais de um pulso de clock, dependendo da complexidade da instrução e da arquitetura do processador. Portanto, a ideia de que cada um desses ciclos demora exatamente um pulso de clock não é correta.
-->
    (V) A instrução “CLR A” não possui operando e gasta apenas 1 ciclo de máquina
<!--
Verdadeiro, Vide slide 17
-->
    (V) A arquitetura Von Neumann é considerada uma arquitetura mais simples do que a arquitetura Harvard porque utiliza o mesmo barramento para o tráfego de dados e de instruções.
<!--
Verdadeiro, Vide slide 24
-->
    (V) A técnica de pipeline é impossível de ser utilizada em computadores de arquitetura Von Neumann.
<!--
Verdadeiro, Vide slide 26
-->

***

2 - Indique quais afirmativas se aplicam a uma instrução CISC e quais a uma instrução
RISC:
- Os programas são mais complexos - **(CISC)**
- A maioria das instruções tem a mesma duração - **(RISC)**
- Mais instruções disponíveis - **(CISC)**
- Programas menores - **(CISC)**
- Utiliza menos espaço na memória de programa - **(RISC)**
- Processamento de cada instrução é mais lento - **(CISC)**
- Microcontroladores PIC, AVR, ARM - **(RISC)**
- Tempo de execução das instruções depende da frequência do clock. - **(CISC)**
***

<!--
COMENTÁRIOS E NOTAS IMPORTANTES SOBRE O CAPITULO

PORTA PARALELA: recebe somente zeros e uns (entrada binária) e é usada para controlar coisas que que recebem ou devolvem valores binários. Um exemplo seria um motor, que pode estar (1) ou não(0) ligado.

PORTA DIGITAL: Recebe valores variáveis no tempo, podendo ser do tipo inteiro ou de ponto flutuante. Um exemplo seria a analise de peso/temperatura em um elevador, esses valores variam de acordo com a quantidade de passageiros.

PORTA SERIAL: Manda/Recebe uma quantidade de bits de uma só vez, usando somente um pino. Um exemplo seria um teclado, quando digitamos uma tecla, cada uma delas manda um codigo binário para a porta, que pode ter uma quantidade de bits que depende dar arquitetura do microcontrolador, mas que será interpretado pelo Microprocessador.


-->