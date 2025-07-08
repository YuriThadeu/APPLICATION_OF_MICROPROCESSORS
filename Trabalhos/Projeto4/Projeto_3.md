 # SEL0433 - APLICAÇÃO DE MICROPROCESSADORES 
## Introdução aos Microcontroladores de 32 bits

### Projeto 4: Controle PWM e Comunicação

 - NOME: Yuri Thadeu Oliveira Costa
    - N° USP: 14754821
 - NOME: Heloisa Oliveira de Carvalho
    - N° USP: 13833960

***
***

### Informações Gerais

### Objetivos

- Exercitar a programação em alto nível para microcontroladores de 32 bits
- Desenvolver um projeto prático com foco em comunicação serial e PWM (pulse width modulation).
- Usar bibliotecas otimizadas para programação de periféricos e controle de GPIO: UART, I2C, Display OLED, Touch, PWM, Wi-Fi e Bluetooth por meio da plataforma ESP32 Devkit e do ambiente de simulação virtual Wokwi.
- Reflexão sobre as decisões de projeto envolvendo escolha de microcontroladores, recursos de hardware e software, otimização energética e desafios de implementação.

### Requisitos do projeto

### Parte 1 – Controle PWM de LED RGB

Implementar um projeto para controle PWM e comunicação serial utilizando a placa ESP32 Dev Module. Conectar um LED RGB (catodo comum) na GPIO da placa conforme esquemático ilustrado na Figura abaixo, utilizando resistores de 220 ohms. Programar utilizando bibliotecas do ESP32 por meio da Espressif IDE ou Arduino IDE ficando a critério do aluno qual framework usar. Com base na documentação e exemplos disponibilizados na página da biblioteca LED Control PWM (LEDC), elaborar um programa para realizar a modulação de brilho em um LED RGB utilizando a técnica PWM:

- O PWM deverá controlar o brilho individual de cada cor “ R- Red”, “G- Green” e “B- Blue” do LED, com resolução a partir de 8 bits (256 níveis) (pode ser escolhido uma resolução maior);

- Cada pino GPIO associado aos terminais R, G e B deve ser vinculado à um canal PWM individual da ESP32, utilizando a biblioteca LEDC (LED Control PWM).

- O duty cycle deve variar de 0 a 100% em loop, com frequência de 5kHz, com valor de incremento pré-definido (por exemplo: se definir o valor “5”, o controle/resolução do brilho será feito de 5 em 5, até 255, por exemplo).

- O valor de incremento será aplicado de forma individual e diferente a cada cor do LED RGB (por exemplo: R = incremento*2; G = incremento; B = incremento*3 – outra lógica poderá ser usada desde que o incremento seja aplicado com valores distintos em cada cor).

- Exibir uma mensagem no Monitor Serial/terminal (UART – baud: 115.200) que indique o valor de incremento e duty cycle.

- Elaborar e testar/simular o projeto no Wokwi (o qual dispõe de LED RGB). Pode-se também testar na placa física disponível no laboratório (o laboratório também dispõe de LED RGB, resistores, conectores e protoboard).

- Desafio proposto 1 (opcional - pontuação diferenciada): tentar implementar o controle do duty cycle de cada cor do LED RGB (ou escolher uma delas) via comunicação sem fio no programa. A implementação pode ser realizada por meio de um aplicativo de terminal Bluetooth comum disponível em smartphone, de forma a permitir que se envie valores numéricos que serão interpretados como incrementos para o duty cycle de cada canal (R, G, B) pelo programa por meio do módulo Bluetooth da ESP32. A implementação é opcional e faz parte do desafio que o/a aluno(a) estude por conta própria o uso de bibliotecas de comunicação serial Bluetooth com ESP32, a integração desse recurso ao programa base e a realização da interação prática via aplicativo de terminal no celular, visando explorar recursos mais avançados disponíveis em sistemas embarcados.
- O simulador Wokwi também oferece suporte a outras plataformas baseadas em microcontroladores de 32 bits, como a Raspberry Pi Pico e a STM32. O uso delas também é opcional e pode ser adotado como alternativa à ESP32 como um desafio adicional, a critério do aluno.

<b>Formato de entrega da Parte 1:</b> Apresentar em um documento o programa desenvolvido com as partes principais devidamente comentadas. Apresentar fotos da montagem/diagrama; prints do monitor serial.


### Parte 2 – Aplicação final de escolha do(a) aluno(a)

A aplicação final deverá envolver o uso de controle PWM para o comando de um motor, podendo incluir controle de movimento, rotação, velocidade ou posicionamento em motores de passo, e servo, motor, entre outros. A escolha deve ser compatível com os itens disponíveis no Wokwi, permitindo que o projeto seja totalmente simulado neste aplicativo. O projeto deve ser diferente do programa de Servo Motor solicitado na Atividade Semanal 11. Outras funcionalidades e recursos podem ser implementados, a critério do aluno, considerando que se trata de um projeto final. Ou seja, o ideal é que sejam utilizados todos os recursos estudados ao longo do semestre, além de explorar componentes e funcionalidades disponíveis no Wokwi, como sensores (temperatura, acelerômetros etc.), atuadores, Buzzers, uso de interrupções de GPIO para botões (se pertinente), integração com outros módulos como temporizadores/contadores, ADC/DAC etc. Para a parte de controle PWM, recomenda-se tentar utilizar a biblioteca MCPWM (via Arduino ou IDE nativa). Além disso, é obrigatório incluir algum tipo de comunicação serial e exibição dos resultados. Por exemplo: Exibição em um display OLED (via comunicação serial I2C) e/ou apresentação de dados no monitor serial ou terminal via UART.

<b>Formato de Entrega da Parte 2:</b> Apresentar em documento o programa desenvolvido, destacando as principais partes do código devidamente comentadas. Incluir uma discussão textual explicando o projeto escolhido e os principais conceitos envolvidos, bibliotecas utilizadas, além de outros recursos eventualmente empregados (como sensores, interrupções, conversores ADC/DAC, timers etc.) explicando como e por que cada um foi utilizado. Apresentar o diagrama e fotos da montagem prática (microcontrolador e circuito montado no Wokwi), com prints da simulação realizada mostrando, por exemplo, valores no display, monitor serial etc. Por fim, incluir na documentação uma discussão sobre os seguintes aspectos:

- Justificativa da escolha e do uso adequado de recursos de hardware (por que seria necessário usar um microcontrolador de 32 bits; quais os impactos e diferenças em relação a um de 8 bits; quando ou não utilizar);
- Qual o impacto do consumo de energia e formas de otimização desse consumo em sistemas embarcados quando se considera microcontroladores de 32 bits.

### Entrega final:

- Apresentar as Partes 1 e 2 em único arquivo PDF ou link para documentação em repositório no GitHub (enviar o link por meio de um arquivo).
- Enviar separadamente os códigos fonte dos programas desenvolvidos nas Partes 1 e 2. Os scripts podem ser enviados em arquivo compactado ou, caso escolher o GitHub para documentar o projeto, colocar os códigos diretamente no repositório, sendo opcional o envio separado pelo e-Disciplinas neste último caso (neste caso, enviar link para o repositório).
- Realizar o upload dos arquivos na respectiva tarefa atribuída no e-Disciplinas até a data especificada. A atividade poderá ser feita preferencialmente em duplas. Qualquer dúvida sobre o formato de envio ou sobre a implementação da atividade prática, entrar em contato com o professor ou monitores.

***
***

### RESULTADOS:

