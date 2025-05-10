/* SEL0614/SEL0433/SEL0336 Aplic. de Microprocessadores
 ===============================================================================
 Introdu��o � Programa��o em C para Microcontroladores PIC18F usando o kit
 EasyPic v7 Mikroe.

Exemplo 3: Continua��o do Exemplo 2 - Incrementar LEDs ao pressionar a tecla
- RB0 = TECLA (PORTB)
- RD0 = LED  (PORTD)
- Acionamento de display de 7 seg. (PORT D)

 MCU: PIC18F4550 - alimenta��o de 5V - Cristal de 8 MHz

Liga��es no kit EasyPIC:
   /* Habilitar a chave 4 do DIP Swit 3  (manter desligado todos os outros)
      Em PORTB habilitar Pull-UP apenas na chave RB0 (Pull-Up  externo)
      No circuito "Button Press Level" colocar J17 no "Com" (aterrado)
      Na alimenta��o, via USB, manter 3.3 V (padr�o do PIC18F45K22)

// No Software: em <Project> - Edit Project - desabilitar PORT A/D (disable)
================================================================================
 */
 
// Considera��es iniciais
signed char ucContador = -1;        // var global  para incremento
// outra op��o:
//unsigned char ucContador = 0;     // caso inciar em zero, mudar os �ndices do
// No bloco switch abaixo, seria: case 1;case 2;case 3; e default ucContador = 0

void Incremento(unsigned char Contador)   // Bloco de incremento
{
     switch (Contador)
    /* {
            case 0:{ PORTD.RD0=1; break;}   // acende LED 0 (PORTD)
            case 1:{ PORTD.RD1=1; break;}   // acende LED 1
            case 2:{ PORTD.RD2=1; break;}   // acende LED 2
            default:{ PORTD =0; ucContador = -1; break;} // zera todo o PORTD e 
            //reincia o contador
     }  */
     
     {      // acionamento do display de 7 segmentos do kit EasyPIC (PORTD)
            case 0:{ latd = 0b00111111; break;}   //  0 no display de 7seg.
            case 1:{ latd = 0b00000110; break;}   //  1 no display de 7seg.
            case 2:{ latd = 0b01011011; break;}   // 2 no display de 7seg.
            default:{ PORTD =0; ucContador = -1; break;} // zera todo o PORTD e
            //reincia o contador
     }

}

void main() {
// inser��o de uma vari�vel auxiliar (local ou global) para resolver o problema
//do exemplo 1!
// Uma vari�vel pode ser criada dentro ou fora do "main". Uma vari�vel local,...
//entretanto, deve estar dentro de uma fun��o.

unsigned char FlagAux = 0; // vari�vel aux. do tipo char que ir� permitir
   // encontrar o estando anterior da tecla para acionar ou n�o o LED (selo).
   // Essa vari�vel � importante para fazer com que o LED seja acionado somente
//quando ocorra uma mudan�a real, evitando acionar mais de uma vez se o estado
//ainda estiver no mesmo n�vel que provocou o acionamento.

    ADCON1 |= 0XF;   // configura��o dos pinos como digital

// Programa

// Configurar os pinos de acionamento de cada display de 7 segmento:
   TRISA =0;      // define o PORTA
   PORTA =0b00001111; //RA0, RA1, RA2, RA3  - liga o display de 7 seg. do kit
   
// Tecla  - configura��o da entrada
    TRISB.RB0 = 1;  // configura pino RB0 como entrada
    PORTB.RB0=1; //seria opcional pois internamente, ao colcoar TRISX.RX0 =1,...
    /* MCU j� coloca n�vel 1 nesta porta X (O MCU possui resistores Pull-up e
    pull-down externos -ver circuitos do kit EasyPIC).Por�m, existe uma excess�o
    que � o PORTB: ao colocar TRISB.RB0 = 1; os resistores PUll-Up desligam-se
    automaticamente */


    //TRISD.RD0=0; // output - configura o pino como sa�da (=0) (consome corrente)
    //PORTD.RD0 = 0; // LED OFF


    // condi��es e loop para piscar o LED:
while(1) // True
{
    if(PORTB.RB0 ==0 && FlagAux==0)   // AND l�gico (express�o)
    // SE tecla � pressiona: true; e Flag = 0 (valor incial j� � 0): true.
    // Resultado: condi��o verdadeira e o bloco segue sendo executado
    {
       Incremento(++ucContador);  // recebe o Incremento do contador p/ o display de 7 segmentos
       // Outra op��o: Incremento(ucContador++) //caso usar "unsiged char
       // ucContador = 0"
      
       FlagAux=1;        //  A condi��o acima n�o ser� mais verdadeira
       Delay_ms(40);     // tratar efeito bounce

     }

    // Condi��o oposta para repetir o loop = tecla � liberada
     if(PORTB.RB0 ==1 && FlagAux==1)// Se a tecla n�o estiver press. e flag = 1
        {
          FlagAux=0;     // condi��o para voltar ao bloco IF anterior
          Delay_ms(40);    // tratar efeito bounce
        }

} //while

} // main