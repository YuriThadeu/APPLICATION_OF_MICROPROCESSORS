; Aplic. de Microprocessadores
;--------------------------------------------------
; Exemplo 1 de uso de pilha e subrotinas em Assembly
; Stack Pointer register - SP
; Registrador especial de 8 bits
; do 8051 para pilha de dados
; usado para armazenar dados para 
; chamada e retorno de subrotinas

; Por padr�o SP aponta para endere�o 7

;---------------------------------------------------
org 0000h; origem

main:     ; label - fun��o principal

	MOV A, #10h ; Valor 10 em ACC
	MOV B, #02h ; Valor 2 em B
	ACALL OP_MULT ;chama subrotina de multiplica��o
	ACALL OP_DIVI ;chama subrotina de divis�o
	JMP $ ; segura o programa nesta linha
;----------------------------------
; Sub-rotinas
OP_MULT:
; Empilhar: ACC e depois B
; SP aponta para um endere�o e...
; incrementa o valor empilhado
; que resulta no seu armazenamento
; no pr�ximo endere�o.

	PUSH ACC ; salva valor de ACC na pilha
; PUSH = "empilhar"
	PUSH B ; salva valor de B na pilha
	MUL AB ; multiplica A por B, 
; salva o Byte H em B e o byte L em ACC

	MOV 53h, A ; move conte�do de A para o endere�o na RAM
	MOV 54h, B ; move conte�do de B para o endere�o na RAM
;----------------------------------
; Desempilhar: LIFO - ultimo a 
;.. entrar (B no caso) � o 
; primeiro a sair
	POP B ; recupera o valor anterior de B na pilha
; POP = "desempilhar"
	POP ACC ; recupera ACC anterior da pilha
	RET ; retorna para main
; Retorno da subrotina para a pr�xima
;linha de c�digo em "main"

OP_DIVI:
	PUSH ACC ; salva valor de ACC na pilha
; PUSH = "empilhar"
	PUSH B ; salva valor de B na pilha
	DIV AB ; divide A por B, 
; salva em ACC e o resto em B

	MOV 63h, A ; move conte�do de A para o endere�o na RAM
	MOV 64h, B ; move conte�do de B para o endere�o na RAM
;Idem:
	POP B ; recupera o valor anterior de B na pilha
; POP = "desempilhar"
	POP ACC ; recupera ACC anterior da pilha
	RET ; retorna para main

end



