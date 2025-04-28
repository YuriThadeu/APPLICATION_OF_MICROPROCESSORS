
org 0000h
JMP inicio

delay:
MOV R1, #100

loop:
	MOV R0, #250
	DJNZ R0, $
	DJNZ R1, loop

RET

LED EQU P1.0
SW EQU P2.0


inicio:

JB SW,desliga
CLR LED
ACALL delay
SETB LED
ACALL delay
JMP inicio

desliga:

SETB LED
JMP inicio
end

