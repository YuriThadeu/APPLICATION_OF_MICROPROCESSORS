
_main:

;LED_Tecla_2.c,36 :: 		void main() {
;LED_Tecla_2.c,44 :: 		unsigned char FlagAux = 0; // vari�vel aux. do tipo char que ir� permitir
	CLRF        main_FlagAux_L0+0 
;LED_Tecla_2.c,53 :: 		ADCON1 |= 0XF;  // registrador presente no modelo PIC18F4550 e derivados
	MOVLW       15
	IORWF       ADCON1+0, 1 
;LED_Tecla_2.c,59 :: 		trisb.rb0 = 1;  // configura pino RB0 como entrada
	BSF         TRISB+0, 0 
;LED_Tecla_2.c,60 :: 		PORTB.RB0=1; // coloca em n�vel 1 (pull-up)
	BSF         PORTB+0, 0 
;LED_Tecla_2.c,63 :: 		TRISD.RD0=0; //  configura o pino como sa�da (=0) (consome corrente)
	BCF         TRISD+0, 0 
;LED_Tecla_2.c,64 :: 		PORTD.RD0 = 0; // sa�da incialmente em 0 (LED OFF)
	BCF         PORTD+0, 0 
;LED_Tecla_2.c,70 :: 		while(1) // True
L_main0:
;LED_Tecla_2.c,73 :: 		if(PORTB.RB0 ==0 && FlagAux==0)   // AND l�gico (express�o)
	BTFSC       PORTB+0, 0 
	GOTO        L_main4
	MOVF        main_FlagAux_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
L__main11:
;LED_Tecla_2.c,77 :: 		PORTD.RD0 =~LATD.RD0; // (TOOGGLE) Inverte o n�vel l�gico do LED em LATD
	BTFSC       LATD+0, 0 
	GOTO        L__main13
	BSF         PORTD+0, 0 
	GOTO        L__main14
L__main13:
	BCF         PORTD+0, 0 
L__main14:
;LED_Tecla_2.c,81 :: 		FlagAux=1;        //  A condi��o acima n�o ser� mais verdadeira - (aqui
	MOVLW       1
	MOVWF       main_FlagAux_L0+0 
;LED_Tecla_2.c,84 :: 		Delay_ms(40);     // trata efeito bouncing (repique mec�nico do bot�o,
	MOVLW       104
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	NOP
;LED_Tecla_2.c,88 :: 		} //fim do bloco IF, o qual em caso de falso (a tecla n�o for pressionada
L_main4:
;LED_Tecla_2.c,93 :: 		if(PORTB.RB0 ==1 && FlagAux==1)// Se a tecla n�o estiver press. E flag = 1
	BTFSS       PORTB+0, 0 
	GOTO        L_main8
	MOVF        main_FlagAux_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main8
L__main10:
;LED_Tecla_2.c,95 :: 		FlagAux=0;     // condi��o para voltar ao bloco IF anterior
	CLRF        main_FlagAux_L0+0 
;LED_Tecla_2.c,96 :: 		Delay_ms(40);  // trata efeito bouncing
	MOVLW       104
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_main9:
	DECFSZ      R13, 1, 1
	BRA         L_main9
	DECFSZ      R12, 1, 1
	BRA         L_main9
	NOP
;LED_Tecla_2.c,97 :: 		}
L_main8:
;LED_Tecla_2.c,99 :: 		} //while
	GOTO        L_main0
;LED_Tecla_2.c,101 :: 		} // main
L_end_main:
	GOTO        $+0
; end of _main
