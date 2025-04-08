 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 4 - Introdução à Programação para Microcontroladores

###  Atividade Semanal – Aula 4

 - NOME: Yuri Thadeu Oliveira Costa
    - N° USP: 14754821
 - NOME: Heloisa Oliveira de Carvalho
    - N° USP: 13833960

***


### 1 Atividade

O roteiro dos códigos do programa será apresentado abaixo, seguido pelo código gerado e as respostas para algumas perguntas relacionadas à atividade.


### 1.1 Roteiro da atividade

**Criação e Inicialização do Programa**

- Criar um novo programa clicando em "New". 
- Colocar a origem no endereço 0000h. 
- Inicializar o programa com a label main.

**Transferência de Dados**
- Mover de forma imediata o valor 12 em hexadecimental (formato default – quando não for especificado qual formato, sempre usar este) para o acumulador (A). 
- Mover de forma imediata o valor zero para A. 
- Mover de forma imediata o valor 34 em hexadecimental para o registrador R2 no banco 0. 
- Mover de forma imediata o valor 56 em decimal para o registrador B. 
- Mover a porta P1 para o endereço de memória 0x40. 
- Mover de forma direta o conteúdo da posição de memória 0x40 para o registrador R4 do banco 1. 
- Mover o conteúdo de R4 para o endereço de memória 0x50. 
- Mover de forma imediata o valor 0x50 em binário para R1. 
- Mover R1 de forma indireta para o acumulador (usar @R1). 
- Mover de forma imediata o valor 0x9A5B para o registrador DPTR.
  
**Instruções Aritméticas**
- Mover de forma imediata o valor 2 para o ACC. 
- Mover de forma imediata o valor 3 para B. 
- Mover de forma imediata o valor 7 para R4 
- Somar o conteúdo de R4 com o ACC. 
- Decrementar 3 unidades do ACC. 
- Incrementar 1 unidade em B. 
- Subtrair A por B. 
- Multiplicar A por B. 
- Incrementar 2 unidades em B. 
- Dividir A por B. 
- Armazenar os conteúdos de A e B nos endereços de memória 0x70 e 0x71.

**Instruções Lógicas e Booleanas**
- Mover de forma imediata os valores 0b11001100 e 0b10101010 para A e B, respectivamente. 
- Realizar AND lógico entre A e B. 
- Rotacionar A à direita em 2 bits. 
- Realizar o complemento de A. 
- Rotacionar A à esquerda em 2 bits. 
- Realizar OR lógico entre A e B. 
- Realizar XOR entre A e B. 
- Realizar SWAP de A. 
- Em “bit field information” no simulador EdSim51 (onde geralmente é exibido PSW no formato binário), colocar ACC no lugar de PSW e observar os valores binários resultantes das operações neste registrador.

**Instruções de Desvio Condicional e Incondicional**
- Criar uma label de referência para início 
- Limpar o ACC. 
- Mover de forma imediata o valor 0x10 para R0. 
- Saltar SE A = 0 para o bloco2 (label). 
- Saltar SE A ≠ 0 para o bloco3. 
- Consumir tempo de 1 μs sem nenhuma operação. 
- Inicializar bloco2:
        ▪ Mover R0 para A.
        ▪ Saltar de forma incondicional para bloco1. 
- Inicializar bloco3:
        ▪ Decrementar e Saltar SE R0 ≠ 0 para bloco3.
        ▪ Saltar de forma incondicional para inicio

**Encerramento do Programa**
- Segurar o programa na última linha. 
- Encerrar o programa. 
- Todos os programas podem ser estruturados em um único código e pode-se usar instruções de salto ou sub-rotinas para navegar entre eles (caso preferir, escrever os programas dos 5 itens anteriores em scripts separados).

#### Depuração:

Montar e Executar o Programa: 
- Clique em "Assm" para montar o código. 
- Execute cada linha clicando em "Step" e observe os resultados na memória RAM e nos registradores. 
- Salve o programa.

***

### 1.2 Código gerado seguindo roteiro

A partir desse roteiro, foi montato o seguinte codigo em Assembly para o 8051 usando o EdSim51:


```asm
ORG  0000h ; Define a origem do programa no endereço 0000h

MAIN:
    JMP TRANSF_DADOS

FIM: ; Label referente ao Encerramento do Programa 
    SJMP FIM ;Loop infinito pra manter o programa no fim

;---------------------

TRANSF_DADOS: ; Label referente a Transferência de Dados 
    MOV A, #12h ;1 -> move 12h pra acumulador A
    MOV A, #0h ;2 -> Zera o acumulador A
    MOV R2,#34h ;3 -> Move 0x34 para R2
    MOV B, #56 ;4 ->  Move o valor decimal 56 para o registrador B
    MOV 40h, P1 ;5 -> Move o conteúdo da porta P1 para o endereço 0x40
    SETB RS0 ;6 -> Seta o bit RS0 para 1
    CLR RS1 ;6 -> Seta o bit RS1 para 0
    MOV R4, 40h ;6 ->Move diretamente o conteúdo de 0x40 para R4 dado que agora ele está no bando 1 porque RS1=0 e RS0=1(01b = 1 decimal)
    MOV 50h, R4 ; 7 -> Move o conteúdo de R4 para o endereço 0x50
    MOV R1, #01010000b ; 8 -> Move valor binário 50 para R1
    MOV A, @R1 ; 9 -> Move para A o valor do endereço apontado por R1 indiretamente
    MOV DPTR, #9A5BH ; 10 ->Move 0x9A5B para o registrador DPTR, ou Data Pointer

JMP INSTR_ARIT;---------------------

INSTR_ARIT: ; Label referente a Instruções Aritméticas 
    MOV ACC, #02h ;1 -> o MOV com o # antes do valor faz endereçamenteo imediato, nesse caso está endereçando o valor 12 hexadecimal ao endereço de memória do acumulador, no caso ACC
    MOV B, #03h ;2 -> endereçamento imediato de 03h
    MOV R4, #07h ;3 -> endereçamento imediato de 07h
    ADD A, R4 ;4 -> Soma o conteúdo de R4 com o acumulador
    SUBB A, #03h ;5 -> Subtrai 3 do acumulador
    INC B ;6 -> Incrementa 1 unidade em B
    SUBB A, B ;7 -> Subtrai B de A com
    MUL AB ;8 ->  Multiplica A por B
    INC B ;9 -> Incrementa B em 1
    INC B ;9 -> Incrementa B em 1 (segunda vez)
    DIV AB ;10 -> Divide A por B
    MOV 0x70, A  ;11 -> Armazena A em 0x70
    MOV 0x71, B  ;11 -> Armazena B em 0x71

JMP INSTR_LBOL;------------------------

INSTR_LBOL: ; Label referente a Instruções Lógicas e Booleanas 
    MOV A, #0CCh    ; Move 0b11001100 para A-> 1
    MOV B, #0AAh    ; Move 0b10101010 para B-> 1
    ANL A, B        ; A = A AND B => A = 10001000 -> 2
    RR A ;3 -> Rotaciona A 1 bit à direita
    RR A ;3 -> Rotaciona A mais 1 bit à direita
    CPL A ;4 -> faz o complemento de A, ou seja, inverte todos os bits
    RL A ;5 -> Rotaciona A 1 bit à esquerda
    RL A ;5 -> Rotaciona A 1 bit à esquerda denovo
    ORL A, B ;6 -> A = A OR B
    XRL A, B ;7 -> A = A XOR B
    SWAP A ;8 -> troca os 4 bits superiores pelos inferiores
    ;9

JMP INSTR_DCONDeINCOND;------------------------

INSTR_DCONDeINCOND: ; Label referente a Instruções de Desvio Condicional e Incondicional 
    CLR A ;2 -> Zera o acumulador
    MOV R0, #10h ;3 -> Move 0x10 para R0
    JZ bloco2 ;4 -> Salta para bloco2 se A igual a 0 depois do bloco2 para sair do loop
    bloco1: ;1  -> Label de inicial do loop que inicia depois do bloco3 para sair do loop
    JNZ bloco3 ;5 -> Salta para bloco3 se A diferente de 0
    INICIO: ;1  -> Label de inicial do loop que inicia 
    NOP ;6 -> consome 1 micro segundo sem operação
    JMP FIM ; 9 -> salto para a label FIM onde vai segurar o programa na ultima linha

    bloco2: ;7 -> 
        MOV A, R0 ;7 -> Move valor de R0 para A
        SJMP bloco1 ;7 -> volta para o bloco1

    bloco3: ;8 -> 
        DJNZ R0, bloco3 ;8 -> Decrementa R0 e salta de volta para bloco3 se R0 for difernete de 0
        SJMP INICIO ;8 -> volta para o INICIO

;------------------------
END ; Fim do programa
;------------------------
```


**OBS: Os valores numéricos comentados ao lado dos codigos é a ordem proporcional a posição da pergunta no roteiro.**

***
### 1.3 Questões e Respostas

Sobre Transferência de Dados:

(a) Qual foi o tempo gasto em cada linha de instrução e quantos ciclos de máquina esse programa contém? Justifique sua resposta.

    RESPOSTA: Cada ciclo de máquina dura aproximadamente 1 μs (1 ciclo de clock), que é o tempo para a maioria das intruções no microcrontrolador 8051 quando está operando com um clock de 12MHz. As intruções MOV, INC e DEC consomem 1 ciclo de clock, enquanto MUL AB (4 ciclos), DIV AB (4 ciclos), e DJNZ (2 ciclos) consomem mais ciclos. No caso do programa contruido, foram gastos 107μs ou 107 ciclos de clock, até que o programa entrasse no loop infinito que mantem o programa no fim.

(b) O que aconteceu ao mover uma porta inteira de 8 registradores (ex.: MOV A, P1) para um destino e por que seu valor é FF?

    RESPOSTA: Quanto movemos uma porta inteira de 8 registradores, A recebe o valor atual presente na porta. No simulador EdSim51, quando nenhum dispositivo externo está conectado à porta P1, todos os seus pinos são interpretados como estando em nível lógico alto (1). Isso faz com que o valor lido seja FFh (ou 11111111 em binário). Isso acontece porque, sem conexão, os pinos da porta ficam em estado flutuante e assumem por padrão o valor alto.

(c) Qual valor apareceu no acumulador após ter movido R1 de forma indireta para ele?

    RESPOSTA: Na parte do codigo: 

    MOV R1, #50h  
    MOV A, @R1

    R1 aponta para o endereço 0x50 da RAM. Como esse endereço havia recebido anteriormente o valor da porta P1 (que era FFh), o acumulador também passa a conter FFh após a instrução.


(d) Por que foi possível mover um valor de 4 dígitos para DPTR? Em quais registradores especiais do simulador foi possível verificar mudanças quando essa operação foi realizada? Qual o maior valor que pode ser movido para DPTR em hexadecimal?

    RESPOSTA: O registrador DPTR (Data Pointer) do 8051 é um registrador de 16 bits, formado pelos registradores especiais DPH (parte alta) e DPL (parte baixa), ambos de 8 bits. Por isso, é possível mover valores de até 4 dígitos hexadecimais para ele.
    
    No simulador EdSim51, ao executar a instrução:

    MOV DPTR, #9A5Bh

    o valor 9A5Bh é armazenado com DPH = 9Ah e DPL = 5Bh. Essas alterações podem ser observadas na área de registradores especiais do simulador. O maior valor que pode ser movido para o DPTR é FFFFh (65535 em decimal).

Sobre Instruções Aritméticas:

(e) Faça os seguintes testes em um programa a parte:
    
1. Por que ao mover o valor 4 para ACC, o bit menos significativo de PSW resulta em 1; e ao mover o valor 3, esse bit resulta em 0?
    
        RESPOSTA: O bit menos significativo do registrador PSW indica a paridade do acumulador (ACC). Ele é automaticamente atualizado com base na quantidade de bits 1 presentes em ACC: se o número for ímpar, PSW.0 é 1; se for par, PSW.0 é 0. Ao mover o valor 4 para ACC (que possui um único bit 1), a paridade é ímpar e PSW.0 resulta em 1. Já ao mover o valor 3 (que possui dois bits 1), a paridade é par e PSW.0 resulta em 0.

2. Tente decrementar 1 unidade de algum registrador ou endereço de memória cujo valor é igual a zero (ex.: DEC A, DEC Rn, ou DEC 60h, sendo A, Rn, ou 60h iguais a zero). Por que a operação resulta em FF?
   
        RESPOSTA: Quando decrementamos um registrador ou endereço de memória que contém o valor zero, o resultado é FFh (255 em decimal) porque o 8051 trabalha com aritmética de 8 bits sem sinal. Nesse tipo de operação, os valores vão de 00h a FFh, e não existe valor negativo. Assim, ao fazer DEC em 00h, o valor subtrai 1 e "dá a volta", indo para o maior valor possível de 8 bits, que é FFh — esse comportamento é chamado de "estouro (underflow)".



***

### 2 Atividade

O roteiro dos códigos do programa será apresentado abaixo, seguido pelo código gerado e comentado.

### 2.1 Roteiro da atividade

Verificar sequencialmente o conteúdo das posições de memória de 20h até 23h (por exemplo) e incrementar um registrador com a quantidade de valores menores do que #45h (por exemplo) contidos nestas posições de memória.


 - Criar um novo programa

 - Colocar a origem no endereço 00h

 - Saltar para a label do programa principal (main)

 - Colocar a origem em 33h

 - Na label principal, inicializar R0 com valor #20h; e R1 com #0;

 - Criar uma label chamada LOOP (ou com qualquer outro nome – será um ponto de retorno)

 - Mover R0 de forma indireta para A;

 - Subtrair #45h de A

 - Saltar de forma condicional, se não houver carry, para uma terceira label (operação com bit - verificar o bit de flag carry de PSW e salta se = 0)

 - Incrementar 1 unidade em R1 (ou seja, se #45h for maior do que A, o resultado da subtração é negativo e carry será = 1, portanto o salto da linha anterior não irá acontecer e o programa executará essa linha, sinalizando a quantidade de valores maiores do que #45h)

 - Atribuir a terceira label, para onde o programa irá saltar segundo a condição atribuída anteriormente

 - Incrementar 1 unidade em R0 (incrementa o ponteiro para próxima posição de memória)

 - Compara R0 com #24h e salta para LOOP se não forem iguais (verificar se chegou na última posição de memória, 23h +1, a ser testada)

 - Nenhuma operação

 - Segurar o programa nesta linha

 - Depurar o programa e descrever seu comportamento (atribua manualmente valores aleatórios, maiores e menores do que #45h, nas posições de memória de 20h à 23h para testar o programa no simulador EdSim51, verificando ao final se a quantidade em R1 está correta)

 - Salvar o programa

 - Formato de resposta: apresentar as linhas de código comentadas.

### 2.2 Código gerado seguindo roteiro

A partir desse roteiro, foi montato o seguinte codigo em Assembly para o 8051 usando o EdSim51:

```asm
;Verificação sequencial de posições de memória.

ORG 0000h ; Colocando a origem no endereço 00h
SJMP main; Saltando para a main
ORG 33h; Redefinindo a origem 33h

MAIN:
MOV R0, #20h; R0 recebe o valor 20h é o ponteiro para acessar a memória indiretamente
MOV R1, #00h; R1 inicia com 0 e contar quantos valores são maiores que 45h

LOOP:
MOV  A, @R0; Movendo de forma indireta o Registrador 0
SUBB A, #45h; Subtraindo 45h de A
JNC sem_carry ; Se NÃO houver carry “A” maior ou igual a  45h, salta para  sem_carry
INC R1 ; Se houve carry “A” menor que 45h, incrementa o contador R1

SEM_CARRY:
INC R0; Vai para a próxima posição de memória
SJMP loop; Salto incondicional para o início do loop
CJNE R0, #24h, loop ; Se ainda não chegou na posição final 24h, volta pro loop

FIM:
    SJMP FIM; Trava o programa

END
```
***