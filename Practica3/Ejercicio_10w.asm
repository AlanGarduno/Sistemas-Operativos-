segment .data
	text1 db 'Ingresa las 3 cadenas: ',0xA
	handleCon dd 1
	longCad dd 1
	caract dd 1
	anArg dd 1

segment .bss
	string1 resb 50
	string2 resb 50
	string3 resb 50
	stringN resb 150

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
	mov eax,23d
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
	read1:
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
		push dword string1
		push dword [handleCon]
		call _ReadConsoleA@20
	read2:
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
		push dword string2
		push dword [handleCon]
		call _ReadConsoleA@20
	read3:
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
		push dword string3
		push dword [handleCon]
		call _ReadConsoleA@20
	findmaxlong:
		mov edx,0	
		mov esi, string1
		mov ebx, 0
		count:
			mov al,[esi]
			cmp al,0
			je count_end
			inc esi
			inc ebx
			jmp count
		count_end:
			mov edx,ebx
			dec esi
				mov [esi],al
				dec esi
				mov [esi],al
			mov esi, string2
			mov ebx, 0
		count2:
			mov al,[esi]
			cmp al,0
			je count2_end
			inc esi
			inc ebx
			jmp count2
		count2_end:
			cmp edx,ebx
			jg next2
			mov edx,ebx
			next2:
				dec esi
				mov [esi],al
				dec esi
				mov [esi],al
				mov esi, string3
				mov ebx, 0
		count3:
			mov al,[esi]
			cmp al,0
			je count3_end
			inc esi
			inc ebx
			jmp count3
		count3_end:
			cmp edx,ebx
			jg next3
			mov edx,ebx
			next3:
				dec esi
				mov [esi],al
				dec esi
				mov [esi],al
				dec edx
				dec edx
	copystrings:
		mov ebx,0
		mov edi, stringN
		copycharN:
			mov esi,string1
			add esi,ebx
			mov al,[esi]
			cmp al,0
			je copychar2
			mov [edi],al
			inc edi
			copychar2:
				mov esi,string2
				add esi,ebx
				mov al,[esi]
				cmp al,0
				je copychar3
				mov[edi],al
				inc edi
				copychar3:
					mov esi,string3
					add esi,ebx
					mov al,[esi]
					cmp al,0
					je copycharN_next
					mov[edi],al
					inc edi
			copycharN_next:
				inc ebx
				cmp edx,ebx
				jg copycharN
	copystrings_end:
		xor eax,eax
		push dword -11
		call _GetStdHandle@4
		mov [handleCon],eax

		xor eax,eax
		mov eax,150d
		mov [longCad],eax
		xor eax,eax
		mov eax,0d
		mov [anArg],eax
		push dword [anArg]
		push dword caract
		push dword [longCad]
		push dword stringN
		push dword [handleCon]
		call _WriteConsoleA@20

		xor eax,eax
		mov eax,0d
		push dword [anArg]
		call _ExitProcess@4