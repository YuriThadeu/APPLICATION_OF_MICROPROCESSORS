 /* SEL0614/SEL0433/SEL0336 Aplic. de Microprocessadores
 ===============================================================================

Exemplo 2: Continua��o do Exemplo 1 - Ao pressionar uma tecla, o n�vel l�gico
de um LED deve mudar
- RB0 = TECLA (PORTB)
- RD0 = LED  (PORTD)
Problema do Exemplo 1: N�o possui controle sobre a a��o i.e., ao manter a
tecla pressionada, o LED fica piscando (mudando continuamente o estado)  - falta
tratamento do efeito bouncing (trepida��o mec�nica do bot�o ao press. e soltar)

Efeito bouncing:  Quando pressionamos o bot�o, for�amos o contato entre dois
condutores, imprimindo for�a no bot�o que � (energia) transferida para os contatos,
que, por sua vez, levam tempo para se estabilizarem em uma posi��o de "repouso"
(contato pleno). Enquanto esse repouso n�o � atingido, ocorrem microoscila��es
entre as posi��es aberto e fechado, com dura��o de milissegundos. O tratamento
(debouncing) pode ser feito com rotinas de delay da ordem de dezenas de ms, o que
� suficiente para ignorar a oscila��o do bot�o (bouncing) e relativamente curto
para atrasar a l�gica do programa (acender o LED ao press. o bot�o). Ao soltar o
bot�o, tamb�m existe um efeito similar, em raz�o da estabiliza��o dos contatos,
que estavam sob press�o, a voltar no estado de repouso aberto (sem contato).



MCU: PIC18F4550 - alimenta��o de 5V - Cristal de 8 MHz
// Liga��es no kit EasyPIC
   /* Habilitar a chave 4 do DIP Swit 3  (manter desligado todos os outros)
      Em PORTB habilitar RN2 em Pull-UP apenas na chave RB0 (Pull-Up  externo)
      No circuito "Button Press Level" colocar J17 no "Com" (aterrado)
      Na alimenta��o, via USB, manter 5 V (padr�o do PIC18F45550)

//
================================================================================
*/
// In�cio
void main() {
// Considera��es iniciais

// A novidade aqui � a inser��o de uma vari�vel auxiliar (local ou global) para 
//resolver o problema do exemplo 1!
// Uma vari�vel pode ser criada dentro ou fora do "main". Uma vari�vel local,...
//entretanto, deve estar dentro de uma fun��o.

unsigned char FlagAux = 0; // vari�vel aux. do tipo char que ir� permitir
// encontrar o estado anterior do bot�o, para acionar ou n�o o LED (selo).
// Essa vari�vel � importante para fazer com que o LED seja acionado somente
//quando ocorra uma mudan�a real, evitando acionar mais de uma vez se o estado
//ainda estiver no mesmo n�vel que provocou o acionamento.


 // Config. dos pinos como digitais

    ADCON1 |= 0XF;  // registrador presente no modelo PIC18F4550 e derivados
    // outros modelos, como PIC18F45k22, usam registradores ANSEL

// Programa

    // Tecla  - configura��o da entrada
    trisb.rb0 = 1;  // configura pino RB0 como entrada
    PORTB.RB0=1; // coloca em n�vel 1 (pull-up)

    // LED  - sa�da: configura��o do estado inicial
    TRISD.RD0=0; //  configura o pino como sa�da (=0) (consome corrente)
    PORTD.RD0 = 0; // sa�da incialmente em 0 (LED OFF)
    
    // TRISD = 0; // todos os pinos como sa�da
    // PORTD =0; //todos os pinos = 0

    // condi��es e loop para piscar o LED:
while(1) // True
{

   if(PORTB.RB0 ==0 && FlagAux==0)   // AND l�gico (express�o)
    // SE tecla � pressiona: true; E Flag = 0 (lembrando que valor incial j� �
    //= 0): true. Resultado: condi��o verdadeira e o bloco segue sendo executado
    {
       PORTD.RD0 =~LATD.RD0; // (TOOGGLE) Inverte o n�vel l�gico do LED em LATD
       // "~ "  invers�o bit a bit  - SE incialmente RD0 = 0, receber� 1 quando
       // a teclada for pressionada; SE 1, receber� o valor 0
       
       FlagAux=1;        //  A condi��o acima n�o ser� mais verdadeira - (aqui
       // certamente o bot�o ainda estar� pressionado - pois � execu��o � muito r�pida)
       
       Delay_ms(40);     // trata efeito bouncing (repique mec�nico do bot�o,
       //dentro deste intervalo de tempo n�o ser� considerado)
       

     } //fim do bloco IF, o qual em caso de falso (a tecla n�o for pressionada
     //ou continua pressiona (devido a velocidade do MCU - nanosegundos) mas a
     // Flag = 1), ser� pulado.

    // Condi��o oposta para repetir o loop = tecla � liberada
     if(PORTB.RB0 ==1 && FlagAux==1)// Se a tecla n�o estiver press. E flag = 1
       {
          FlagAux=0;     // condi��o para voltar ao bloco IF anterior
          Delay_ms(40);  // trata efeito bouncing
        }
     
} //while

} // main