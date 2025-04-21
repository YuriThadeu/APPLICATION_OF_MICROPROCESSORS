; Timers - Exemplo 2

;---------------------------------- 
; registradores de configuração:

; TCON (nible mais sig.) - ativa quais timers serão usados: C/T0 ou C/T1, e suas flags de overflow
;(estouro da contagem)

; Bits do TCON:
;          T/C    INT
;         C/T1 C/T0
;          FR   FR
; TCON, #  00   01  0000b ; rodar 
; C/T0
; TRx =1; run (habilita contagem)
; TFx inicia em 0 e, quando ocorre
; o estouro da contagem, vai p/ 1


; TMOD - confira modos de temporização: M0, M1, M2 e M3
; Bits do TMOD:

;           C/T1       C/T0
;         G C/T! M
; TMOD, # 0  0   00  0000b; 
; Exemplo acima: config. Modo 1 T0
;----------------------------------
; Exemplo:
; Configurar C/0 no Modo 1 - para contagem de 20 ms usando interrupção externa
;Usar um LED para verificar 
; a contagem

org 0000h
JMP main
;----------------------------------
; Interrupção
org 000Bh ; endereço da int. T0
; Tratamento da interrupção T0
; Recarrega o temporizador
	MOV TH0, #0B1h
	MOV TL0, #0E0h
	CPL P1.0 ; inverte o bit para
; reiniciar
RETI; Retorna ao programa
;----------------------------------
org 0033h
main:
CLR P1.0 ; liga o LSB da PORTA 1
; alvo neste exemplo (LED)
;-----------------------------------
; Configurações:
MOV TCON, #00010000b; Ativa C/T0
; SETB TR0
MOV TMOD, #00000001b ; configura
; timer 0 para incrementar contagem
; com ciclo de máquina no modo 1
; 16 bits
;----------------------------------
; Parâmetros de contagem:
; Clock 8051 => 1 ciclo = 1 MHz = 1us

;            Hbyte     Lbyte
; C/T 0 = TH0(8bits)+TL0(8bits)
; Portanto 16 bits=65536 (0 a 65535)
; = 0000h a FFFFh
; 65536 x 1us = 65,536 ms
;Para contagem de 20ms:
; 65536-20000 = 45536 = B1E0h
; Hbyte (TH0) = B1h
; Lbyte (TL0) = E0h
; Portanto a contagem será:
MOV TH0, #0B1h
MOV TL0, #0E0h
;----------------------------------
; Config. de interrupção

;Habilita a interrup. T0
MOV IE, #10000010b
; Prioriza a interrup. T0
MOV IP, #00000010b

JMP $ ; aguardando a interrupção
; que irá ocorrer quando estourar a
;contagem de 20 ms, automaticamente
; pois trata-se de uma interrp. interna T0 (ET0)

end
; Colocar breakpoint em 	CPL P1.0
; para verificar a contagem
