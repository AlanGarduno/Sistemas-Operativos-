segment .data  ;Segmento de datos
cadena db 'Programando en esamblador para Linux',0Ax ;Cadena a imprimir
segment .text ;Segmento de codigi
    global _start  ;Punto de entrada al programa
_start:             ;Inicio del programa
    mov edx,38d     ;Longitud de cadena
    mov ecx,cadena  ;Cadena a escribir 
    mov ebx,1       ;Salida estandar
    mov eax,4       ;Numero de llamada al sistema sys_write
    int 0x80        ;Interrupcion de llamadas al sistema del kernel
    mov eax,1       ;Numero de llamada al sistemaa sys_exit
    int 0x80        ;Interrupcion de llamadas al sistema del kernel

