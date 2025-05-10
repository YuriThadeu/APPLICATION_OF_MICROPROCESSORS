
_main:

;LED_Blink1.c,30 :: 		void main() {
;LED_Blink1.c,45 :: 		ADCON1 |= 0x0F;  // outros MCUs da s�rie PIC18F, como PIC18F4550 e derivados,
	MOVLW       15
	IORWF       ADCON1+0, 1 
;LED_Blink1.c,53 :: 		TRISB.RB0 = 1;  // configura pino RB0 como entrada no PORTB
	BSF         TRISB+0, 0 
;LED_Blink1.c,54 :: 		PORTB.RB0=1; //valor de leitura da entrada em pull-up, ao colocar TRISX.RX0 =1,...
	BSF         PORTB+0, 0 
;LED_Blink1.c,58 :: 		TRISD.RD0=0; // output - configura o pino como sa�da (=0) (consome corrente)
	BCF         TRISD+0, 0 
;LED_Blink1.c,59 :: 		PORTD.RD0 = 0; // sa�da inicialmente desligada   (LED apagado)
	BCF         PORTD+0, 0 
;LED_Blink1.c,120 :: 		while(1) // True
L_main0:
;LED_Blink1.c,122 :: 		if(PORTB.RB0 ==0)   // Tecla ativada em n�vel l�gico 0 (SE o pino estiver ..
	BTFSC       PORTB+0, 0 
	GOTO        L_main2
;LED_Blink1.c,125 :: 		PORTD.RD0 =~LATD.RD0; // Inverte o n�vel l�gico do LED em LATD
	BTFSC       LATD+0, 0 
	GOTO        L__main5
	BSF         PORTD+0, 0 
	GOTO        L__main6
L__main5:
	BCF         PORTD+0, 0 
L__main6:
;LED_Blink1.c,128 :: 		Delay_ms(300);     // retarda a CPU de forma que ao pressionar a tecla..
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;LED_Blink1.c,131 :: 		}  //fim do bloco IF, o qual em caso de falso (a tecla n�o for pressionada)
L_main2:
;LED_Blink1.c,141 :: 		} //while
	GOTO        L_main0
;LED_Blink1.c,143 :: 		} // main
L_end_main:
	GOTO        $+0
; end of _main
