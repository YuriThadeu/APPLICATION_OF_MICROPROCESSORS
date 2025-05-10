#include "calculo.h"    // #include "nome.h" - arquivo no diret�rio do projeto
                       // #include <nome.h> - arquivo no diret�rio do compilador

// inclui o prot�tipo da fun��o soma exatamente aqui nesta �rea do c�digo
// unsigned char soma(char _b, char _c);

// #include <stdio.h>    - standard input-output header - cabe�alho padr�o de
// entrada e sa�da - possui defini��es de leitura de dados no teclado, exibi��o
// de informa��es na tela, constantes, var. e tipos. 
// Exemplo: fun��es stdio.h: printf(); scanf(); fprintf(); fscanf();

//------------------------------------------------------------------------------

  /* Uma fun��o que deve ser definida antes da sua chamada no c�digo
   (ordem do compilador � de cima para baixo), definindo os par�metros e o
   retorno. Por essa raz�o se faz necess�rio o prot�tipo da fun��o:
  
   unsigned char soma(char _b, char _c);  // exemplo de prot�tipo de fun��o
  
   Ao inv�s de inserir o prot�tipo neste c�digo, o arquivo .h pode ser incluido
  
  A gera��o do arquivo objeto depende das folhas associadas ao projeto. Assim,
  neste arquivo � necess�rio incluir as fun��es, diretivas e cabe�alhos que
  far�o parte deste projeto.
  */
 
 // outro exemplo:
 /*
      unsigned char soma2(unsigned char t1, unsigned int t2)
{
     return(t1+t2);
}
 */
 
 // vari�vel global: fora do main (usada em todas fun��es)- endere�o de mem�ria
 // reservado e n�o pode ser realocado
 
 
void main() {   // a fun��o main � void (n�o retorna valor) pois � a...
// � a fun��o principal e n�o retorna valores para outras fun��es. Outro exemplo
//: fun��o Delay - n�o retorna valor, apenas realiza o atraso

// vari�vel local - dentro de uma fun��o e s� existe quando for executada, a
// vari�vel ser� criada em mem�ria, por�m, depois o endere�o � liberado, ap�s a
// execu��o deste bloco, poupando mem�ria

     PORTB = soma(240,20);     // PORTB = 30;
     
    
     // Outro exemplo:
    // unsigned char x1 = 0;        // unsigned 0 a 255
     //x1 = soma2(56,200);   // x1 = 0 (n�o suporta valor maior do que 255)
     
     // solu��o: unsinged int x1 =0;
     // prot�tipo: unsigned int soma2(unsigned char t1, unsigned int t2)
     
     // Se o retorno da fun��o for 12.5f = float x1; float soma2(...);
}