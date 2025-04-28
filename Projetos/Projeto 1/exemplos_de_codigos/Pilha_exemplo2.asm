; Aplic. de Microprocessadores
;--------------------------------------------
; Pilha - Exemplo 2

; o registrador SP armazena o endereço
; no topo da pilha

; No exemplo 1, vimos que o endereço
;inicial de SP é 07h
; Entretanto, esse endereço usa a área
; dos bancos de registradores gerais
; e a pilha pode aumentar os dados e
; envadir outras áreas de armz. na RAM


; Portanto, é mais conveniente usar
; os endereços de 50h a 7Fh p/ pilha

; logo, neste exemplo, vamos iniciar
;SP no endereço anterior ao 50
;--------------------------------------------

org 0000h

MOV SP, #4Fh ; move para SP o valor
; do topo da pilha (anterior a 50h)

MOV A, #250h
MOV B, #05h
;----------------------------------
; Uso da pilha
; Uma vez que SP possui no topo
; da pilha o valor 4Fh, o valor de A
; será armazenado no próximo endereç.

PUSH ACC; Escreve na pilha o valor de  A
PUSH B ; Escreve na pilha o valor de B

; Multiplica A por B e move o resultado
; para dois endereços na RAM
MUL AB
MOV  23h, A
MOV  24h, B


; Leitura na pilha (desempilhar) 
;(recuperação dos valores anteriores
; de A e B)

POP B ; Leitura do valor B (LIFO)
POP ACC ; Leitura de A

; Neste exemplo foi usado a área correta
; para pilha de dados
NOP

end



