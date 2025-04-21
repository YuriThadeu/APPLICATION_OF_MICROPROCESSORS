;ADC

;WR - borda - pulso de 0/1 para iniciar leitura
;INTR - vai p/ 0 quando termina conversão
; pino de interrupção
;__
;RD - leitura do valor convertido(ativa em 0
; i/p = sinal de tensão no pino

;ADC - dados na porta P2
INTR EQU P3.2 ; pino INTR
WR EQU P3.6   ; pino WR
RD EQU P3.7   ; pino RD

org 000h

main:
	CLR WR ; pulso 0...
	SETB WR; para 1 (boarda)

	JB INTR, $
	; INTR = 0 (converteu)
	CLR RD; ativa leitura do valor convertido
	MOV R3, P2; guarda a leitura em R3
	SETB RD; desativa leitura em RD (somente após guardar valor)
JMP main