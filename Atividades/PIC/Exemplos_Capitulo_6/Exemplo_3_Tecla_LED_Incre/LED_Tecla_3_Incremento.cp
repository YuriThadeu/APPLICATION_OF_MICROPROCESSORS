#line 1 "G:/Meu Drive/Pasta dinamica/Profissional/Atuação/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplicação de Microprocessadores/Monitoria/Materiais/Projetos PIC18F com MIkroC/Exemplo_3_Tecla_LED_Incre/LED_Tecla_3_Incremento.c"
#line 40 "G:/Meu Drive/Pasta dinamica/Profissional/Atuação/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplicação de Microprocessadores/Monitoria/Materiais/Projetos PIC18F com MIkroC/Exemplo_3_Tecla_LED_Incre/LED_Tecla_3_Incremento.c"
signed char ucContador = -1;




void Incremento(unsigned char Contador)
{
 switch (Contador)
#line 56 "G:/Meu Drive/Pasta dinamica/Profissional/Atuação/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplicação de Microprocessadores/Monitoria/Materiais/Projetos PIC18F com MIkroC/Exemplo_3_Tecla_LED_Incre/LED_Tecla_3_Incremento.c"
 {
 case 0:{ latd = 0b00111111; break;}
 case 1:{ latd = 0b00000110; break;}
 case 2:{ latd = 0b01011011; break;}
 default:{ PORTD =0; ucContador = -1; break;}

 }

}





void main() {





unsigned char FlagAux = 0;







 ADCON1 |= 0XF;



 TRISA =0;
 PORTA =0b00000111;

 TRISB.RB0 = 1;
 PORTB.RB0=1;
#line 100 "G:/Meu Drive/Pasta dinamica/Profissional/Atuação/Docencia/USP/EESC-SEL/SEL0433  0336 0614 Aplicação de Microprocessadores/Monitoria/Materiais/Projetos PIC18F com MIkroC/Exemplo_3_Tecla_LED_Incre/LED_Tecla_3_Incremento.c"
 TRISD=0;
 PORTD = 0;






while(1)
{
 if(PORTB.RB0 ==0 && FlagAux==0)


 {
 Incremento(++ucContador);



 FlagAux=1;
 Delay_ms(40);

 }


 if(PORTB.RB0 ==1 && FlagAux==1)
 {
 FlagAux=0;
 Delay_ms(40);
 }

}

}
