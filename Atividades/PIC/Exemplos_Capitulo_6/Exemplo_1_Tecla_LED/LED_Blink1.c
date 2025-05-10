 /* SEL0433/SEL0336/SEL0614 Aplic. de Microprocessadores
 ===============================================================================
 Introdu��o � Programa��o em C para Microcontroladores PIC18F usando o kit
 EasyPic v7 Mikroe.   
 
 Uso dos registradores TRISX (dire��o - define como entrada: bit 1; ou sa�da:
 bit 0), PORTX(leitura/escrita de dados I/O - acionar/desligar) e LATX (modifica
 /e escreve dados na sa�da) - em que X s�o os ports A, B, C, D, ou E
 
 Conhecendo os PORTs (I/O) do PIC18F - uso de entradas e sa�das

Exemplo 1: Ao pressionar uma tecla/bot�o (entrada digital), o n�vel l�gico de um LED
deve mudar (sa�da digital)
 - RB0 = TECLA/bot�o (PORTB)
 - RD0 = LED  (PORTD)

 MCU: PIC18F4550 - alimenta��o 5V - Cristal externo de 8 MHz
 Data Sheet: https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/39632e.pdf

Liga��es no kit EasyPIC:
   > Habilitar a chave 4 do DIP Swit3  (manter desligado todos os outros)
   > Em PORTB habilitar chave RN2 em Pull-UP apenas na chave RB0
   > No circuito "Button Press Level" colocar J17 no "Com" (aterrado)
   > Na alimenta��o, via USB, manter 5 V (padr�o do PIC18F4550)

================================================================================
  */

// In�cio - fun��o principal
void main() {
// Considera��es iniciais:

 // Diretivas de pr�-configura��o - depende de qual PIC ser� usado
 // No caso do PIC18F45k22 (outro modelo), todos os pinos I/O vem pr�-config. 
 //como anal�gicos.
 // Portanto, caso estivesse usando esse modelo:
#ifdef P18F45K22
       ANSELB = 0;  // registrador do PIC18F45K22 - configura todos os pinos...
       //...de PORTB como digital  (lembrando que o 18F45K22 possui uma chave...
       //individual para cada um dos bits, separados por PORTs
       ANSELD=0; // idem - pinos do PORTD como digital
       
#else  // no entanto, vamos trabalhar com PIC18F4550, que usa o registrador ADCON1:

    ADCON1 |= 0x0F;  // outros MCUs da s�rie PIC18F, como PIC18F4550 e derivados,
    // possuem ADCON1, e a configura��o deve ser dessa forma, que j� configura
    // todos como digital
#endif

// Programa

    // Configura��o da entrada digital, usando um bot�o/swtich do kit como exemplo
    TRISB.RB0 = 1;  // configura pino RB0 como entrada no PORTB
    PORTB.RB0=1; //valor de leitura da entrada em pull-up, ao colocar TRISX.RX0 =1,...
    // MCU j� coloca n�vel 1 nesta porta X
    
    // COnfig. Sa�da Digital (usando um LED do kit): configura��o do estado inicial
    TRISD.RD0=0; // output - configura o pino como sa�da (=0) (consome corrente)
    PORTD.RD0 = 0; // sa�da inicialmente desligada   (LED apagado)
//===================================================================================
// Outras formas de configurar os registradores por bit e por byte:
   // Lembrando que o compilador n�o � "case sensitive" com letras maiusculas ou
   // minusculas - portanto, tanto faz usar: TRISA, Trisa, portb, PORTC.rc0 etc

// Registradores das portas (bidirecionais - pode ser config. como entrada ou sa�da):
/*
   PORTA = 8 bits relativos � 8 pinos do MCU de RA0 � RA7 (RA0=bit0;RA1=bit1;RA2=bit2.... ....RA7=bit7)
   PORTB  = 8 bits/pinos de RB0 � RB7
   PORTC = 8bits/pinos de   RC0 � RC7
   PORTD =8bits/pinos de RD0 � RD7
   PORTE = 4bits/pinos de RE0 � RE3 * (dos quais, somente 3 ficam disponv. no kit
   pois RE3 � usado como reset (MCRL))
   
                   F7 F6 F5 F4 F3 F2 F1 F0
    registrador = |__|__|__|__|__|__|__|__|

*/

/* Config. por byte :
    TRISA = 0xFF; // todos 8 bits do portA como entrada; em hexa 0xFF = 11111111
    PORTB = 0 ; // todos 8 bits do PORTB com leitura em 0; em decimal 0 = 00000000
    LATD =255; // todos 8 bits  do PORTD com sa�da 1; em decimal 255 = 111111111
    TRISC=0b00110111;// alguns bits do PORTC como sa�da outros como entrada em bin�rio
    
    TRISB = 1; //Aten��o: aqui, 1 em decimal, significa 00000001 em bin. POrtanto,
    ...estar� config. apenas o bit0 do PORTB como entrada, n�o todos!
    
    
  Config. por bit: nomebyte.nomebit
  
  Identifica��o de bits pode ser: RX0 a RX7 em X = A, B, C, D, ou E (PORTs
    TRISA.RA0 = 1;      bit0 como entrada
    PORT.RB5 =0;       bit5 leitura em 0
  
  Ou pode ser de F0 a F7 (posi��o):
    TRISC.F0 = 1;   bit0 como entrada
    PORTD.F2 =1;    bit2 leitura em 1
   
  Ou pode ser nome do bit por extenso:
    PORTA.PORTA0 =1 ; bit0
    TRISA.TRISA7 = 0; bit7
   
  Ou pode ser s� o nome do bit + "_bit":
   PORTA0_bit= 1;
   TRISC6_bit=0;
   LATD4_bit = 1;
  

  Config. de registradores especiais
  TMR0 = 0;    // coloca 0 no reg. TIMER0 (temporizador 0)
  TMR2=0xB4    // carrega valor inicial em hexa no TIMER0
  
  INTCON.f2=0;    // bit 2 do reg. INTCON chama-se "TMR0IF", que � a flag de overflow
  INTCON.TMR0IF = 0;    // faz o mesmo, endere�ando pelo nome do bit
  TMR0IF_bit= 0;      // faz o mesmo, endere�ando somente o bit
*/

//=============================================================================
// condi��es e loop para piscar o LED:
while(1) // True
{
    if(PORTB.RB0 ==0)   // Tecla ativada em n�vel l�gico 0 (SE o pino estiver ..
    // aterrado..)
    {
       PORTD.RD0 =~LATD.RD0; // Inverte o n�vel l�gico do LED em LATD
       // "~ "  invers�o bit a bit  - SE incialmente RD0 = 0, receber� 1 quando
       // a teclada for pressionada; SE 1, receber� o valor 0
       Delay_ms(300);     // retarda a CPU de forma que ao pressionar a tecla..
       // a a��o de fato aconte�a (as intru��es s�o executadas em nanosegundos)

     }  //fim do bloco IF, o qual em caso de falso (a tecla n�o for pressionada)
     //...ser� pulado.
     
     /*  Abaixo um exemplo de loop simples, somente para piscar LED independente
     da tecla:
        PORTD.RD0= 1;   // acende o LED
        Delay_ms(300);  // delay de 300 ms  aceso
        PORTD.RD0=0;    // apaga o LED
        Delay_ms(300);  // delay de 300 ms apagado
        */
} //while

} // main