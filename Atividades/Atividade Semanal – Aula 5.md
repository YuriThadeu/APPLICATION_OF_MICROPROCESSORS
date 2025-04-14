 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 3 - Análise de set de instruções, pinout e recursos de microcontroladores

## Capitulo 4 - Introdução à Programação para Microcontroladores


###  Atividade Semanal – Aula 5

 - NOME: Yuri Thadeu Oliveira Costa   
 - N° USP: 14754821
  
***
***

#### Questão 1

Responder com verdadeiro (V) ou falso (F) às seguintes afirmações sobre a Pilha (Stack).

	(F) A pilha é uma memória RAM sequencial do tipo FIFO.
	(V) A pilha geralmente é utilizada para armazenar endereço de retorno de sub-rotinas e também de interrupções.
	(F) O ponteiro de pilha (Stack Pointer) é um registrador que aponta para um endereço da memória ROM, que é o endereço de retorno do programa após o atendimento a uma interrupção ou sub-rotina.
	(V) As instruções PUSH e POP são exclusivas para operações com pilha.
	(F) A instrução CALL <endereço> deve ser usada para indicar qual endereço o programa deve desviar no caso de um atendimento à interrupção ou chamada de sub-rotina.
	(V) A instrução RET, colocada no final de uma sub-rotina, faz com que o último endereço armazenado na pilha seja carregado no registrador PC (program counter).
	(F) A área da RAM interna dedicada à pilha é determinada pelo ponteiro SP, um dos SFRs, que possui tamanho 8 bits, mesmo tamanho do barramento de endereço da CPU.
	(F) Geralmente são baseadas em flip-flops tipo D

<!--
	– Pilha é memória tipo LIFO (Last In First Out) ou FILO (First In Last Out), não FIFO.

	– A pilha guarda endereços de retorno de sub-rotinas e interrupções.

	– Stack Pointer aponta para endereço na RAM, não ROM.

	– As instruções PUSH e POP são exclusivas para pilha.

	– A instrução CALL não é usada para indicar desvio de interrupções. Para interrupções usa-se um vetor pré-definido específico (endereços fixos). CALL é usado apenas para chamar sub-rotinas diretamente.

	– RET carrega endereço da pilha no registrador PC, retomando a execução anterior.

	– O ponteiro SP é normalmente menor que o barramento de endereço da CPU. Por exemplo, em microcontroladores típicos como o 8051, SP é de 8 bits, mas o barramento de endereços pode ser maior (por exemplo, 16 bits). Além disso, SP não define a área da pilha, mas aponta a posição atual dela.

	– Memória da pilha é RAM, não composta diretamente por flip-flops tipo D. Flip-flops tipo D são usados diretamente em registradores internos, não na memória RAM da pilha.


-->

#### Questão 2
Refletir se existe diferença entre o endereço armazenado em um espaço de pilha e o endereço armazenado no Stack Pointer (SP)?

    REPOSTA: Sim, existe uma diferença, O SP é um registrador especial que por analogia se parece com um endereçamento indireto, onde ele não salva o proprio valor, mas sim aponta para onde estão armazenados os dados da pilha. Em resumo O SP aponta para o topo atual da oilha que contem o endereço da memoria RAM, mas ele não armazena diretamtne um endereço, mas sim um endereço que indica onde os dados estarão na armazenados na pilha. Já a um endereço armazenado em um espaço da pilha é salvo na memoriam RAM diretamente.

#### Questão 3
Supondo que um banco de 8 LEDs foi conectado à Porta P1 e um banco de 8 Switches conectado à P2 (EdSim51). Acender o LED 0 (pode ser qualquer outro) ao acionar o Switch 7 (pode ser qualquer outro). Apagar o LED ao desligar o Switch.

    REPOSTA: No codigo desse programa foi usado como exemplo o slide 37 do capitulo 4.


```asm
;Fiz o codigo Assembly para o 8051 de forma que o SW_0 ative o LED_0
;----------------------------------------

MAIN:
	MOV P1, #0FFh ; Apaga todos os LEDs (nível alto = apagado)
	MOV P2, #0FFh ; Configura todos os switches como entrada

LOOP:
	JB P2.0, APAGA ; Se P2.0 = 1 (switch solto), vai apagar o LED
	CLR P1.0 ; Acende o LED 0 (coloca 0 no bit correspondente)
	SJMP LOOP

APAGA:
	SETB P1.0 ; Apaga o LED 0 (coloca 1 no bit correspondente)
	SJMP LOOP
```

<!--
Codigo de acordo com o exemplo da pagina slide 37 do Capitulo 4. Usei a logica de subrotinas para organizar melhor o codigo.

Tive alguns problemas com a não incialização de algumas variáveis a um tempo, então preferi setar os valores padrão dos leds e dos switchs mesmo que não seja necessário nesse caso de simulação.

-->

#### Questão 4
Supondo que foram conectados um banco de 8 switches na Porta P2 (EdSim51). Escrever um programa em Assembly para monitorar, quando uma das chaves for pressionada, e indicar o número da chave pressionada em R0 (Se SW3 foi pressionada, então R0 = 3).

    REPOSTA: No codigo desse programa foi usado como exemplo o slide 36 do capitulo 4.

```asm
ORG 0000h

;Loop para monitorar a porta P2
waiting:
	MOV A, #0FFh	; Configura a porta P2 como entrada com pull-up (todos os bits em 1)
	CLR C			; Limpa o carry (C)
	SUBB A, P2     	; Subtrai o valor atual de P2 (switches) do acumulador
	JZ waiting 		; Se resultado for zero (nenhum switch pressionado), continua esperando; enquanto não apertar não vai para o a proxima linha.

;Se alguma chave foi pressionada
	MOV R0, #0		; Inicializa R0 com 0 (contador)
	MOV A, P2		; Lê o estado dos switches

;Loop para verificar qual chave foi pressionada
sw_num:
	RRC A			; Rotaciona o acumulador para a direita via carry
					; (bit que saiu vai pro carry)
	JNC done		; Se carry for 0 (bit baixo), encontrou o switch pressionado
	INC R0			; Incrementa contador (número da chave)
	SJMP sw_num 	; Continua verificando o próximo bit

;Final do programa
done:
	NOP				; Nenhuma operação (ponto de parada)
	SJMP done		; Loop infinito

END
```

<!--
Codigo de acordo com o exemplo da pagina slide 36 do Capitulo 4. mudei algumas coisas nos comentários e nomes mas está igual.
-->


#### Questão 5
Criar uma subrotina de delay de 50 milissegundos a partir da contagem de ciclos de instruções e intervalo de tempo. Essa estrutura poderá servir para piscar um LED a cada 50 ms (ver exemplo na aula correspondente).

    REPOSTA: O codigo da subrotinha usou como exemplo o slide 38 do capitulo 4.

```asm
DELAY_50MS:
	MOV R0, #250         ; Loop interno — 250 iterações
	MOV R1, #100         ; Loop externo — 100 iterações

LOOP1:
	DJNZ R0, LOOP1       ; Decrementa R0 até 0 (cada DJNZ = 2 μs)
	DJNZ R1, DELAY_50MS  ; Decrementa R1 e repete R0 mais uma vez
	RET                  ; Fim do delay de 50 ms
```


<!--Codigo de acordo com o exemplo da pagina slide 38 do Capitulo 4. mudei algumas coisas nos comentários e nomes mas também está igual.
-->

#### Questão 6
Colocou-se 3 LEDs nos endereços P1.0, P1.1 e P1.2 no microcontrolador e 3 chaves nos endereços P2.0, P2.1 e P2.2. Considerando que os LEDs acendem quando é colocado nível baixo na saída e as chaves, quando pressionadas, colocam nível baixo na porta, explique o funcionamento do programa a seguir quando cada chave é pressionada.


```asm
ORG 0000H

Leitura:
	JNB P2.0, PX
	JNB P2.1, PY
	JNB P2.2, PZ
	LCALL Leitura

PX:
	MOV P1, #0
	RET

PY:
	MOV P1, #00000101b
	RET

PZ:
	MOV A, P1
	CPL A
	MOV P1, A
	RET
	
FIM:
	SJMP FIM
```
<br>
<br>

		RESPOSTA: Se os Led's acendem quando o nível logico é baixo, o circuito está usando um resitor Pull-Up. Agora vou explicar comentando em cada linha do programa.


```asm
ORG 0000h	;Define o inicio do codigo do programa

Leitura: 
	;Essa label faz uma verificação se uma das 3 chaves foi pressionada, de forma que: 
	JNB P2.0, PX	; Se P2.0 = 0 (chave 0 pressionada), vai para PX
	JNB P2.1, PY	; Se P2.1 = 0 (chave 1 pressionada), vai para PY
	JNB P2.2, PZ	; Se P2.2 = 0 (chave 2 pressionada), vai para PZ
	LCALL Leitura	; Enquanto uma tecla não for pressionada o progrmaa vai continuar voltando para a label Leitura (loop)

PX:
	MOV P1, #0 	; Seta em zero (apaga), todos os bits d P1
	RET			; Volta para a label Leitura

PY:
	MOV P1, #00000101b; Liga o LED_0 e o LED_2, o restante continua apagado
	RET			; Volta para a label Leitura

PZ:
	MOV A, P1	; Salva os valores de P1 (Valores dos Led's)
	CPL A		; Faz o complemento de A (inverte os valores do registrador A)
	MOV P1, A	; Salva os valores invertidos do registrador A na porta P1, o que deve inverter o estado de todos os LED's ligados nessas portas.
	RET			; Volta para a label Leitura
	
FIM: 		;Essa parte é um loop para encerramento do programa, mas como em nenhuma das sub-rotinas ele foi chamado então o programa não tem FIM.
	SJMP FIM 
```