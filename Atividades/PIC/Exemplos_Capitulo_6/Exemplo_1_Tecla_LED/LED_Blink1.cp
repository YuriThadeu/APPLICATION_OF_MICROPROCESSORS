#line 1 "G:/Meu Drive/Pasta dinamica/Profissional/Atua��o/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplica��o de Microprocessadores/Aulas/v2/exemplos/Exemplo_1_Tecla_LED/LED_Blink1.c"
#line 30 "G:/Meu Drive/Pasta dinamica/Profissional/Atua��o/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplica��o de Microprocessadores/Aulas/v2/exemplos/Exemplo_1_Tecla_LED/LED_Blink1.c"
void main() {
#line 45 "G:/Meu Drive/Pasta dinamica/Profissional/Atua��o/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplica��o de Microprocessadores/Aulas/v2/exemplos/Exemplo_1_Tecla_LED/LED_Blink1.c"
 ADCON1 |= 0x0F;







 TRISB.RB0 = 1;
 PORTB.RB0=1;



 TRISD.RD0=0;
 PORTD.RD0 = 0;
#line 120 "G:/Meu Drive/Pasta dinamica/Profissional/Atua��o/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplica��o de Microprocessadores/Aulas/v2/exemplos/Exemplo_1_Tecla_LED/LED_Blink1.c"
while(1)
{
 if(PORTB.RB0 ==0)

 {
 PORTD.RD0 =~LATD.RD0;


 Delay_ms(300);


 }
#line 141 "G:/Meu Drive/Pasta dinamica/Profissional/Atua��o/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplica��o de Microprocessadores/Aulas/v2/exemplos/Exemplo_1_Tecla_LED/LED_Blink1.c"
}

}
