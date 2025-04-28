; Aplic. de Microprocessadores
;----------------------------------
; Display de 7 segmentos
;     ___a___
;   ||-------||
;  f||       ||b
;   ||___g___||
;   ||-------||
;  e||       ||c
;   ||___d___||
;     --------   + DP
; Segmentos conectados aos LEDs da
; PORTA P1
;      DP g f e d c b a
; P1 = 7  6 5 4 3 2 1 0  
; bit = 1(apagado); bit = 0(acende)

; Contagem de 0 a 9
;0= C0h= 11000000b = a,b, c, d, f
;1= F9h= 11111001b = b,c
;2= A4h= 10100100b = a,b, d, e, g
;3= B0h= 10110000b = a,b, c, d, g
;4= 99h= 10011001b = b,c, f, g 
;5= 92h= 10010010b = a,c, d, f, g
;6= 82h= 10000010b = a,c, d, e, f,g
;7= F8h= 11111000b = a, b, c
;8= 80h= 10000000b = a,b,c,d,e,f,g
;9= 90h= 10010000b = a,b,c, d, f, g
;----------------------------------

; Ativação: decoder
; CS (chip selector) => P0.7
; P0.7= 1(ativado) = 0(desativado)

; 4 displays:

; A1 (P3.4)  A0(P3.3)
;    0          0      Q0 (DISP0)
;    0          1      Q1 (DISP1)
;    1          0      Q2 (DISP2)
;    1          1      Q0 (DISP3)
; CLR P3.4 = 0
; SETB P3.3 = 1
;----------------------------------
org 0000h
JMP main

;----------------------------------
; Tratamento de interrupção

;----------------------------------
org 0033h
main:
MOV DPTR, #display ; endereça
; a tabela de segmentos para DPTR
; Usa-se DPTR (16 bits) em função
; do display possuir 10 valores

MOV R2, #01
MOV A, R2
MOVC A, @A+DPTR ; move o conteúdo
; presente no endereço A+DPTR,onde
; A é um ponteiro - aponta o end.
; em DPTR que contém um valor da
; tabela de segmentos (byte)

MOV P1, A ; Move para P1 o conteúdo
; para acender o display no valor
; apontado em DPTR

; DB = data byte - diretiva para
; armazenar bytes em posições de 
; memória reservadas

;----------------------------------
; Delay, timer e interrupção aqui
;----------------------------------
display:
db 0C0h
db 0F9h
db 0A4h
db 0B0h
db 99h
db 92h
db 82h
db 0F8h
db 80h
db 90h

end
