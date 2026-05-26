bits 64
default rel
global casillas
section .text

; en c declaramos asi: int contarCaracteres(char *mapa, int totalCeldas, char objetivo)

; rdi = direccion del mapa
; rsi = total de celdas
; rdx = caracter objetivo
; eax = cantidad encontrada


contarCaracteres:

    xor eax, eax          ; contador = 0

    cmp rsi, 0
    jle .fin

.loop:

    mov r8b, [rdi]        ; leer caracter actual

    cmp r8b, dl           ; comparar con objetivo
    jne .noCoincide

    inc eax               ; contador++

.noCoincide:

    inc rdi               ; siguiente celda
    dec rsi               ; totalCeldas--

    jnz .loop

.fin:
    ret
