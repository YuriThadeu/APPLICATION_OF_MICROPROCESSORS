 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 5 (Parte 2) - Microcontroladores PIC e Programação em Linguagem C

###  Atividade Semanal – Aula 7

 - NOME: Yuri Thadeu Oliveira Costa
 - N° USP: 14754821
  
***
***

### OBJETIVOS

### Durante a aula


- Fazer o download da pasta com exemplos de códigos em linguagem C;

- Abrir o software MikroC PRO for PIC por meio do atalho na área de trabalho no PC do laboratório;

- Verificar se existem projetos abertos em “Project” no menu principal do software (se a opção “Close Project” estiver habilitada, clique sobre ela para fechar projetos abertos);

- Na opção “Open Project”, abrir o [Exemplo_1_tecla_LED](Atividades/PIC/Exemplos_Capitulo_6/Exemplo_1_Tecla_LED/LED_Blink1.mcppi) (arquivo na extensão “.mcppi”)

- Conectar o KitEasyPIC ao PC por meio do cabo USB e ligar a placa (verificar se os jumpers de alimentação estão conectados à USB e ao 5V na placa).


- Compilar e gravar o programa do [Exemplo_1_tecla_LED](Atividades/PIC/Exemplos_Capitulo_6/Exemplo_1_Tecla_LED/LED_Blink1.mcppi) no kit e verificar seu funcionamento (pressionar botão RB0 e verificar LED RD0). Se atentar as configurações: manter RB0 em Pull-Up e o jumper J17 em GND, verificar se o PORTD está habilitado por meio dos DIP switches SW3. Para mais detalhes sobre as ligações consultar o Manual do Kit EasyPICv7 e seu diagrama esquemático.

- Revisar conceitos por meio dos códigos disponibilizados para download na pasta “Baseline” no que se refere à protótipo de funções, arquivo header “.h”, arquivo source “.c”, arquivo “hex”, arquivo “asm”, biblioteca padrão C, “linkagem”, compilação, diretivas do compilador, encapsulamento de funções para evitar duplicação de variáveis, escopo de variáveis (local/global), tipo de dados e suas implicações (char, int, float).

- Explorar a criação e configuração de um novo projeto no MikroC PRO for PIC, com especial atenção voltada para: seleção do “device”, configuração do clock, configuration bits (tipo de cristal, fonte de clock, resets, desabilita comparadores, watchdog timer). Digitar um programa para realizar alguns testes.

- Explorar recursos do MikroC PRO for PIC: Tools – Start Debugger (inicia depuração de um programa compilado) – verificar depuração em Watch Values – add variáveis de interesse, executar linha por linha com F7, inserir breakpoints com duplo clique na linha. Explorar os exemplos 1, 2 e 3.

- Ilustrar no SimulIDE (para executá-lo no PC do laboratório: “C – Arquivos de Programas – SimulIDE – Bin – Simulide.exe”) a conexão de um botão no pino B0 do microcontrolador PIC18F4550 na configuração Pull-dowm (externo), o qual ao ser pressionado deverá mudar o estado de um LED conectado ao pino D0 (não esquecer do resistor limitador para o LED). Simule o circuito carregando o firmware (arquivo hex) gerado na compilação do programa em Linguagem C que atende essa lógica, a qual foi realizada anteriormente no software no software MikroC PRO for PIC. Configurar o valor do resistor e a frequência do clock do microcontrolador.

### Pós-aula

1º - Altere a lógica do programa do Exemplo 1 para piscar o LED a cada 500 ms (usando a função delay) enquanto o botão se manter pressionado. Ao soltar o botão, o LED deve ser desligado. Realize a simulação no SimulIDE e utilize um osciloscópio digital (recurso disponível no simulador) para verificar o sinal de saída. Conectar o osciloscópio no pino correspondente ao LED no microcontrolador PIC.

2º - Conforme exemplo demonstrado em aula (Exemplo 2), implementar o algoritmo utilizado para tratar o efeito bounce presente no programa do Exemplo 1. Compilar o programa no MikroC PRO for PIC e implementar o circuito no Simul IDE carregando o firmware (arquivo hex gerado na compilação). Ajustar o clock do microcontrolador PIC18F4550 para 8 MHz e o montar o botão na configuração pull-up (ajustar o valor do resistor de pull-up para 10 kΩ) no SimulIDE.

3º - Implemente no SimulIDE o programa no Exemplo 3 – Display de 7 Segmentos. Para tanto, realize as ligações de um display de 7 segmentos disponível no simulador no PORTD do microcontrolador. Ajustar o clock do microcontrolador PIC18F4550 para 8 MHz e o ligar o botão na configuração pull-up (ajustar o valor do resistor de pull-up para 10 kΩ) no SimulIDE.

***
***

### RESULTADOS

##### Questão 1

```c
void main(){
    #ifdef P18F45K22
        ANSELB = 0;
        ANSELD = 0;
    #else
        ADCON1 |= 0x0F;
    #endif

    TRISB.RB0 = 1;
    PORTB.RB0 = 1;
    TRISD.RD0 = 0;
    PORTD.RD0 = 0;

    while(1){
        if(PORTB.RB0 == 0){
            while (PORTB.RB0 == 0 ){
                PORTD.RD0 =~ LATD.RD0;
                Delay_ms(500); //em nanossegundos
            }
        }
        PORTD.RDO = 0; 
    } //while
} // main
```

##### Questão 2

```c
void main(){
    #ifdef P18F45K22
        ANSELB = 0;
        ANSELD =0;
    #else
        ADCON1 |= 0x0F;
    #endif

    TRISB.RB0 = 1;
    PORTB.RB0 = 1;
    TRISD.RD0 = 0;
    PORTD.RD0 = 0;

    while(1){
        //  
        if(PORTB.RB0 == 0 && FlagAux == 0){
            FlagAux = 1;
            Delay_ms(40);
            // 
            while (PORTB.RB0 == 0){
                PORTD.RD0 =~ LATD.RD0;
                Delay_ms(500);
            }
        }
        // 
        if(PORTB.RB0 == 1 && FlagAux == 1){
            FlagAux = 0;
            Delay_ms(40);
            PORTD.RDO = 0;
        } 
    } //while
} // main
```

##### Questão 3