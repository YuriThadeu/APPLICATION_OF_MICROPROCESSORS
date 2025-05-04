 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES

## Capitulo 5 - Microcontroladores PIC e Kit EasyPICs

###  Atividade Semanal – Aula 6

 - NOME: Yuri Thadeu Oliveira Costa   
 - N° USP: 14754821
  
***
***

#### Questão 1

Após analisar a plataforma EasyPIC v7 fisicamente durante a aula correspondente e com base no material relacionado, faça um breve resumo sobre os principais recursos, compatibilidade paran microcontroladores PIC, gravação e periféricos disponíveis nesta placa, listando suas principais funcionalidades para prototipagem em sistemas embarcados.

    RESPOSTA: A EasyPIC v7 combina alto alcance de microcontroladores PIC de 8 bits com programador USB embarcado, seleção de tensão e um rico conjunto de periféricos didáticos (botões, LEDs, displays e ADC) — tudo acessível via conectores múltiplos e mikroBUS. Isso torna a placa ideal para prototipagem rápida de sistemas embarcados, testes de firmware em diferentes PICs e integração de módulos externos sem necessidade de solda ou ferramentas adicionais.

***

#### Questão 2

Em um projeto industrial, é necessário armazenar parâmetros de calibração do sistema para que sejam preservados mesmo após desligar o dispositivo. Onde esses dados devem ser armazenados em um microcontrolador PIC18F?

a) Na EEPROM, pois é uma memória não volátil e permite regravações sem afetar a execução do programa.

    COMENTÁRIO: **RESPOSTA CERTA**.
    Segundo o Slide 21, o PIC18F4550 possui 256 bytes de memoria EEPROM interna não volátil usados para guardar parâmetros que não podem ser apagados depois que o microcontrolador é desligado. A memoraia EEPROM tem acesso de leitura/escrita em tempo de execução e sem interferir no código residente na flash .

b) Na memória de programa (flash), pois a escrita e leitura nela são mais rápidas do que na EEPROM

    COMENTÁRIO: **RESPOSTA ERRADA**.
    De acordo com os slides 21 e 25, a flash é destinada ao código do programa. Para gravar dados nela é preciso apagar blocos inteiros, o que torna o processo é mais lento, limitado em ciclos de gravação/apagamento e normalmente suspende a CPU durante a operação. A organização da memória mostra a flash na seção de programa, enquanto dados voláteis/EEPROM ficam em áreas separadas, reforçando que a flash não é a escolha adequada para armazenar informações de calibração.

***
#### Questão 3

O correto funcionamento do ciclo de máquina no PIC18F está diretamente ligado à configuração do clock. Considerando esses aspectos, qual das afirmações está correta?

a) Cada instrução de 16 bits é executada em um único ciclo de máquina, independentemente de sua complexidade, e a frequência do clock é sempre sincronizada automaticamente com a fonte de alimentação.

    COMENTÁRIO: **INCORRETO**. Segundo os slides 18 e 19, quase todas as instruções gastam 1 ciclo, mas as de salto (branches, chamadas) consomem 2 ciclos de máquina porque o pipeline precisa ser esvaziado . Além disso, o clock não se “sincroniza” automaticamente com a fonte, o PIC oferece alguns modos de oscilador internos ou externos que o projetista seleciona por registradores, mas não há vínculo direto com a tensão de alimentação.

b) O pipeline de 2 estágios do PIC permite que a próxima instrução seja buscada enquanto a instrução atual está sendo executada, otimizando o desempenho.

    COMENTÁRIO: **CORRETO**. Segundo o slide 19, oPIC18F possui um pipeline de busca + execução em 2 estágios, de modo que, em condições normais, cada instrução é completada em 1 ciclo de máquina.

c) frequência do clock e não do tipo de instrução, sendo que o microcontrolador exige um oscilador externo para operar, pois não possui um oscilador interno configurável.

    COMENTÁRIO: **INCORRETO**. De acordo com o slide 18 e 35, as  instruções de salto já contradizem a ideia de que todas levam o mesmo tempo, pois elas levam 2 ciclos. Além disso o PIC18F tem sim um oscilador interno ajustável de 31 kHz a 32 MHz, tornando desnecessário um oscilador externo em muitas aplicações.

d) Todas as instruções do PIC18F possuem o mesmo tempo de execução, garantindo previsibilidade no tempo de resposta.

    COMENTÁRIO: **INCORRETO**. Já falei sobre isso nas respostas anteriores, embora a maiortia das instruções executem em 1 ciclos, instruções como salto quebram essa possibilidade de uniformidade,  precisando ser consideradas em rotinas temporizadas.

***
#### Questão 4

Qual é a principal vantagem do multiplicador de hardware 8x8 do PIC18F em comparação com uma multiplicação feita via software?

a) Reduz o consumo de memória RAM, pois evita a necessidade de armazenar variáveis intermediárias durante a operação.

    COMENTÁRIO: **INCORRETO**. Novamente no slide 21, é apresentado o rescurso e fala apenas que o multiplicador 8 × 8 termina a operação em 1 ciclo de máquina; mas nada é falado sobre a economia de RAM.

b) Permite executar multiplicações em um único ciclo de máquina, aumentando significativamente a eficiência de operações matemáticas.

    COMENTÁRIO: **CORRETO**. Segundo também o slide 21, o tópico “Multiplicador 8 × 8 de um ciclo de máquina” para o PIC18F4550 confirma que a operação inteira de 16 bits sai pronta no mesmo ciclo, aumentando a velocidade das rotinas matemáticas.

c) Aumenta a precisão dos cálculos matemáticos, pois o hardware pode processar valores de ponto flutuante diretamente.

    COMENTÁRIO: **INCORRETO**. No slide 21 menciona somente multiplicação inteira 8 × 8 com resultado de 16 bits. AS operações com ponto‑flutuante provavelmente são feitos usando bibliotecas em C. 


d) Substitui a necessidade de um barramento de dados separado para operações aritméticas, reduzindo a complexidade da arquitetura Harvard.

    COMENTÁRIO: **INCORRETO**. A arquitetura Harvard do PIC18F mantém barramentos de instrução e dados independentes. O multiplicador é somente um bloco, ele não altera a organização dos barramentos.

***
#### Questão 5

Assinale com V (verdadeiro) ou F (falso) em relação aos seguintes registradores:

a) **( F )** PORTx é usado para definir o estado lógico do pino de saída, enquanto LATx é utilizado apenas para entradas digitais.

    COMENTÁRIO: O slide 32 diz que o PORTx serve para leitura do nível presente no pino; quem efetivamente “escreve” na saída é o LATx (Port Latch). LATx não é usado como entrada, mas sim para manter o valor que será aplicado ao pino quando este estiver configurado como saída.

b) **( V )** PORTx reflete o estado real do pino físico, enquanto LATx mantém o último valor escrito, evitando problemas como leitura instável em saídas.

    COMENTÁRIO: Nos slides 29 e 32 é mostrado que o registrador PORTx devolve o nível lógico detectado no pino, inclusive se algum circuito externo alterá‑lo. Já LATx retém o dado escrito pela CPU, impedindo que uma leitura imediata (read‑modify‑write) capte transitoriamente um valor errôneo quando o pino está configurado como saída.

c) **( F )** PORTx pode ser usado para configurar a direção do pino (entrada ou saída), enquanto LATx é responsável pela comunicação serial.

    COMENTÁRIO: No Slide 32 mostra que a direção (entrada = 1, saída = 0) se define em TRISx, não em PORTx. O LATx não tem a ver com interfaces seriais, ele apenas grava o valor a ser aplicado aos pinos digitais

d) **( F )** Não há diferença entre PORTx e LATx, ambos armazenam e manipulam dados da mesma forma no PIC18F.

    COMENTÁRIO: também nos slides 29 e 32 mostra que os dois registradores têm propósitos diferentes.Enquanto PORTx lê o nível presente no pino, o LATx grava (latch) o valor de saída. Ignorar essa diferença pode causar leituras instáveis ou efeitos de “read‑modify‑write”.

e) **( V )** ADCON1 deve receber o valor 0x0F para configurar os pinos no modo digital, desabilitando todos os canais analógicos do PIC18F4550.

    COMENTÁRIO: No Slide 31 mostra que para modelos como o PIC18F4550, atribuir ADCON1 |= 0x0F força todos os pinos a operarem como digitais, desligando as funções analógicas do ADC.

***