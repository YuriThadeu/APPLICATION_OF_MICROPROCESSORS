; Interrupção - Exemplo 2
; Uso da INT1 - externa 1 com teclado

; Teclado conectado a PORTA P0
; vide LD (diagrama) 

;  +----+----+----+
;  | 11 | 10 |  9 |  row 3 (P0.3)
;  +----+----+----+
;  | 8  | 7  |  6 |  row 2 (P0.2)
;  +----+----+----+
;  | 5  | 4  |  3 |  row 1 (P0.1)
;  +----+----+----+
;  | 2  | 1  |  0 |  row 0 (P0.0)
;  +----+----+----+
;   Col2 col 1 col0
;   P0.6 P0.5  P0.4

; Usar a tecla "#" para ligar/desligar
; um LED usando interrupções
; Note que o teclado esta conectado
; em uma INT1 (interrp externa 1)
;**********************************

	org		0000h
	JMP		main
	
	org		0013h; interrupção INT1
	JB			P0.4, wrong_key; monitora
;o bit (caso a tecla não for "#", 
;retorna (loop))
	CPL 		P1.0 ; Liga o LED 
;(caso a tecla # pressionada)

	wrong_key:
	RETI
; fim da área de interrupção
;-----------------------------------
	org		0033h

main:
	MOV 	SP, #04Fh; topo da pilha
	MOV 	PSW, #00h; zera flags
	MOV 	IE, #10000100b; enable INT1
	MOV 	IP, #00000100b;prioriza INT1
	MOV 	TCON, #00000100b;ativa INT1
; por borda
	CLR  P0.0; liga teclado na tecla
; 0 "#", condição para disparo da
; interrupção (coluna P0.4)
	JMP		 $
end
; observar resultado em P3.3 e P0.4
; colocar breakpoint na linha 13
