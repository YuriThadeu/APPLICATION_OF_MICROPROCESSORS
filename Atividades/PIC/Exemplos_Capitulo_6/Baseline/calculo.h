// arquivo cabe�alho .h (header): defini��es  e prot�tipo de fun��es


 // Encapsulamento do arq. header - evita duplica��o de vari�veis caso este
 // mesmoa arquivo .h for incluido em v�rias folhas de projeto. Por exemplo, se
 // aqui neste arquivo uma variav. "char a1" for declarada ela ser� duplicada,
 // no padr�o ANSI uma vari�vel global n�o deve ser duplicada.
 // Para tanto, usa-se a diretiva abaixo #ifndef (s� define a fun��o calculo se
 // ainda n�o foi definida). Caso uma folha j� tenha incluido o arquivo .h ela
 // n�o ser� redefinida
 
#ifndef __calculo__
#define __calculo__

 unsigned char soma(char _b, char _c);// prot�tipo da fun��o soma

#endif
 