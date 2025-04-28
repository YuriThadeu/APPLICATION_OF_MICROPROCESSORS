; DAC encontra-se conectado a porta P1
; habilitado em P0.7


WR EQU P0.7 ; habilita a escrita

org 000h

CLR WR


main:
; escreve 3 valores
	MOV P1, #0FFh
	CALL delay
	MOV P1, #7Fh
  CALL delay
	MOV P1, #3Fh
	CALL delay
	JMP main
; ex: controle de velocidade de motores
delay:
	MOV R1, #100
	loop:
	MOV R0, #250
	DJNZ R0, $
	DJNZ R1, loop
RET