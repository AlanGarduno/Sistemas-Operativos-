segment .data
	text1 db 'Ingresa la cadena: ',0xA
	handleCon dd 1
	longCad dd 1
	caract dd 1
	anArg dd 1

segment .bss
	string resb 50
	numString resb 4

segment .text
	global _main
	extern _GetStdHandle@4
	extern _WriteConsoleA@20
	extern _ReadConsoleA@20
	extern _ExitProcess@4

_main:
	push dword -11
	call _GetStdHandle@4
	mov [handleCon],eax

	xor eax,eax
	mov eax,19d
	mov [longCad],eax
	xor eax,eax
	mov eax,0d
	mov [anArg],eax
	push dword [anArg]
	push dword caract
	push dword [longCad]
	push dword text1
	push dword [handleCon]
	call _WriteConsoleA@20

	xor eax,eax
	push dword -10
	call _GetStdHandle@4
	mov [handleCon],eax
	
	xor eax,eax
	mov eax,50d
	mov [longCad],eax
	xor eax,eax
	mov eax,0d
	mov [anArg],eax
	push dword [anArg]
	push dword caract
	push dword [longCad]
	push dword string
	push dword [handleCon]
	call _ReadConsoleA@20

	mov esi, string
	mov ebx, 0
	count:
		mov al,[esi]
		cmp al,0
		je count_end
		inc esi
		inc ebx
		jmp count
	count_end:
		dec ebx
		dec ebx
	print_number:
		mov eax,ebx
		xor esi,esi
		mov edi,numString
		decod:
			mov edx,0
			mov ebx,10
			div ebx
			add edx,48
			push edx
			inc esi
			cmp eax,0
			jz pnum
			jmp decod
		pnum:
			cmp esi,0
			jz print_number_end
			dec esi
			mov al,[esp]
			mov [edi],al
			add esp,4
			add edi,1
			jmp  pnum
	print_number_end:
		push dword -11
		xor eax,eax
		call _GetStdHandle@4
		mov [handleCon],eax
		
		xor eax,eax
		mov eax,4d
		mov [longCad],eax
		xor eax,eax
		mov eax,0d
		mov [anArg],eax
		push dword [anArg]
		push dword caract
		push dword [longCad]	
		push dword numString
		push dword [handleCon]
		call _WriteConsoleA@20

		xor eax,eax
		mov eax,0d
		push dword [anArg]
		call _ExitProcess@4
