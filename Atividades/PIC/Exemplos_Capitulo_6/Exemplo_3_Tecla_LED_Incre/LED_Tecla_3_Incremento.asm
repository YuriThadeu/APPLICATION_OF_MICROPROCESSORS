
_Incremento:

;LED_Tecla_3_Incremento.c,45 :: 		void Incremento(unsigned char Contador)   // Bloco de incremento
;LED_Tecla_3_Incremento.c,47 :: 		switch (Contador)
	GOTO        L_Incremento0
;LED_Tecla_3_Incremento.c,57 :: 		case 0:{ latd = 0b00111111; break;}   //  0 no display de 7seg.
L_Incremento2:
	MOVLW       63
	MOVWF       LATD+0 
	GOTO        L_Incremento1
;LED_Tecla_3_Incremento.c,58 :: 		case 1:{ latd = 0b00000110; break;}   //  1 no display de 7seg.
L_Incremento3:
	MOVLW       6
	MOVWF       LATD+0 
	GOTO        L_Incremento1
;LED_Tecla_3_Incremento.c,59 :: 		case 2:{ latd = 0b01011011; break;}   // 2 no display de 7seg.
L_Incremento4:
	MOVLW       91
	MOVWF       LATD+0 
	GOTO        L_Incremento1
;LED_Tecla_3_Incremento.c,60 :: 		default:{ PORTD =0; ucContador = -1; break;} // zera todo o PORTD e
L_Incremento5:
	CLRF        PORTD+0 
	MOVLW       255
	MOVWF       _ucContador+0 
	GOTO        L_Incremento1
;LED_Tecla_3_Incremento.c,62 :: 		}
L_Incremento0:
	MOVF        FARG_Incremento_Contador+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_Incremento2
	MOVF        FARG_Incremento_Contador+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_Incremento3
	MOVF        FARG_Incremento_Contador+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_Incremento4
	GOTO        L_Incremento5
L_Incremento1:
;LED_Tecla_3_Incremento.c,64 :: 		}
L_end_Incremento:
	RETURN      0
; end of _Incremento

_main:

;LED_Tecla_3_Incremento.c,70 :: 		void main() {
;LED_Tecla_3_Incremento.c,76 :: 		unsigned char FlagAux = 0; // variável aux. do tipo char que irá permitir
	CLRF        main_FlagAux_L0+0 
;LED_Tecla_3_Incremento.c,84 :: 		ADCON1 |= 0XF;   // configuração dos pinos como digital
	MOVLW       15
	IORWF       ADCON1+0, 1 
;LED_Tecla_3_Incremento.c,88 :: 		TRISA =0;
	CLRF        TRISA+0 
;LED_Tecla_3_Incremento.c,89 :: 		PORTA =0b00000111;
	MOVLW       7
	MOVWF       PORTA+0 
;LED_Tecla_3_Incremento.c,91 :: 		TRISB.RB0 = 1;  // configura pino RB0 como entrada
	BSF         TRISB+0, 0 
;LED_Tecla_3_Incremento.c,92 :: 		PORTB.RB0=1; //seria opcional pois internamente, ao colcoar TRISX.RX0 =1,...
	BSF         PORTB+0, 0 
;LED_Tecla_3_Incremento.c,100 :: 		TRISD=0;
	CLRF        TRISD+0 
;LED_Tecla_3_Incremento.c,101 :: 		PORTD = 0;
	CLRF        PORTD+0 
;LED_Tecla_3_Incremento.c,108 :: 		while(1) // True
L_main6:
;LED_Tecla_3_Incremento.c,110 :: 		if(PORTB.RB0 ==0 && FlagAux==0)   // AND lógico (expressão)
	BTFSC       PORTB+0, 0 
	GOTO        L_main10
	MOVF        main_FlagAux_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main10
L__main17:
;LED_Tecla_3_Incremento.c,114 :: 		Incremento(++ucContador);  // recebe o Incremento do contador p/ o display de 7 segmentos
	INCF        _ucContador+0, 1 
	MOVF        _ucContador+0, 0 
	MOVWF       FARG_Incremento_Contador+0 
	CALL        _Incremento+0, 0
;LED_Tecla_3_Incremento.c,118 :: 		FlagAux=1;        //  A condição acima não será mais verdadeira
	MOVLW       1
	MOVWF       main_FlagAux_L0+0 
;LED_Tecla_3_Incremento.c,119 :: 		Delay_ms(40);     // tratar efeito bounce
	MOVLW       104
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_main11:
	DECFSZ      R13, 1, 1
	BRA         L_main11
	DECFSZ      R12, 1, 1
	BRA         L_main11
	NOP
;LED_Tecla_3_Incremento.c,121 :: 		}
L_main10:
;LED_Tecla_3_Incremento.c,124 :: 		if(PORTB.RB0 ==1 && FlagAux==1)// Se a tecla não estiver press. e flag = 1
	BTFSS       PORTB+0, 0 
	GOTO        L_main14
	MOVF        main_FlagAux_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
L__main16:
;LED_Tecla_3_Incremento.c,126 :: 		FlagAux=0;     // condição para voltar ao bloco IF anterior
	CLRF        main_FlagAux_L0+0 
;LED_Tecla_3_Incremento.c,127 :: 		Delay_ms(40);    // tratar efeito bounce
	MOVLW       104
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_main15:
	DECFSZ      R13, 1, 1
	BRA         L_main15
	DECFSZ      R12, 1, 1
	BRA         L_main15
	NOP
;LED_Tecla_3_Incremento.c,128 :: 		}
L_main14:
;LED_Tecla_3_Incremento.c,130 :: 		} //while
	GOTO        L_main6
;LED_Tecla_3_Incremento.c,132 :: 		} // main
L_end_main:
	GOTO        $+0
; end of _main
