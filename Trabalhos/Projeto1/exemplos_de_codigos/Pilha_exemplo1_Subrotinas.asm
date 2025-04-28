; Aplic. de Microprocessadores
;--------------------------------------------------
; Exemplo 1 de uso de pilha e subrotinas em Assembly
; Stack Pointer register - SP
; Registrador especial de 8 bits
; do 8051 para pilha de dados
; usado para armazenar dados para 
; chamada e retorno de subrotinas

; Por padrão SP aponta para endereço 7

;---------------------------------------------------
org 0000h; origem

main:     ; label - função principal

	MOV A, #10h ; Valor 10 em ACC
	MOV B, #02h ; Valor 2 em B
	ACALL OP_MULT ;chama subrotina de multiplicação
	ACALL OP_DIVI ;chama subrotina de divisão
	JMP $ ; segura o programa nesta linha
;----------------------------------
; Sub-rotinas
OP_MULT:
; Empilhar: ACC e depois B
; SP aponta para um endereço e...
; incrementa o valor empilhado
; que resulta no seu armazenamento
; no próximo endereço.

	PUSH ACC ; salva valor de ACC na pilha
; PUSH = "empilhar"
	PUSH B ; salva valor de B na pilha
	MUL AB ; multiplica A por B, 
; salva o Byte H em B e o byte L em ACC

	MOV 53h, A ; move conteúdo de A para o endereço na RAM
	MOV 54h, B ; move conteúdo de B para o endereço na RAM
;----------------------------------
; Desempilhar: LIFO - ultimo a 
;.. entrar (B no caso) é o 
; primeiro a sair
	POP B ; recupera o valor anterior de B na pilha
; POP = "desempilhar"
	POP ACC ; recupera ACC anterior da pilha
	RET ; retorna para main
; Retorno da subrotina para a próxima
;linha de código em "main"

OP_DIVI:
	PUSH ACC ; salva valor de ACC na pilha
; PUSH = "empilhar"
	PUSH B ; salva valor de B na pilha
	DIV AB ; divide A por B, 
; salva em ACC e o resto em B

	MOV 63h, A ; move conteúdo de A para o endereço na RAM
	MOV 64h, B ; move conteúdo de B para o endereço na RAM
;Idem:
	POP B ; recupera o valor anterior de B na pilha
; POP = "desempilhar"
	POP ACC ; recupera ACC anterior da pilha
	RET ; retorna para main

end



