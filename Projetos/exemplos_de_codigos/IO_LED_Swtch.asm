; Entradas e saídas - I/O
; LED e chave - Exemplo 1

; Ao press uma chave, acender um LED
; Ao desligar a chave, apagar o LED 
;8 x Switchs = Porta P2 (pull-up)
;8 x LEDs = Porta P1 (pull-up)
;**********************************
; Ver diagrama LD
; Contantes - declar com EQU
LED EQU P1.0
Chave EQU P2.0
;-----------------------------------
	org		0000h
	jmp		main
	org		0033h

main:
; Liga o LED
	JB			Chave, $ ;monitora chave 0 (bit 1)
	CLR		LED ; Acende o LED se a chave = 0 acionada (bit 0) Desliga o LED
	JNB		P2.0, $ ; monitora chave 0 (bit 0)
	SETB		P1.0 ; Desliga o LED se chave = 1
	JMP 		main    ; loop

end

; Desafio:
; acender o LED somente após ligar
; e desligar a chave;
; apagar o LED somente após ligar e desligar
; a chave
