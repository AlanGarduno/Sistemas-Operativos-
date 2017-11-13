segment .data
    show db 'Contador[0,9]',0Ax
segment .bss
    num resb 1
segment .text
    global _start
_start:
    mov edx,38d     ;Longitud de cadena
    mov ecx,show  ;Cadena a escribir 
    mov ebx,1       ;Salida estandar
    mov eax,4       ;Numero de llamada al sistema sys_write
    int 0x80        ;Interrupcion de llamadas al sistema del kernel
    
    mov ecx,10					
	mov eax,0	
        asd:
            push ecx					
            push eax
            add eax,'0'					
            mov [num],eax			
            mov eax,4					
            mov ebx,1					
            mov ecx,num 				
            mov edx,1					
            int 0x80
            mov ebx,1
            mov eax,4
            pop eax
            inc eax				
            pop ecx
        loop asd
    mov eax,1
	mov ebx,0
	int 0x80