.8086
.model small
.stack 100h
.data

	texto db 255 dup (24h), 0dh, 0ah, 24h
	posicion db 0
.code

	main proc
		mov ax, @data
		mov ds, ax
		
		mov dx, offset texto ;OFFSET VARIABLE A LLENAR
		mov al, 0dh ; Caracter de finalización
		call carga

		mov dx, offset texto ; offset variable a revisar
		mov al, 'a'; caracter a buscar
		xor ah, ah 
		push dx
		lea dx, posicion
		push dx
		push ax
		call encuentra
		;UDS HACEN  UNA FUNCION QUE IMPRIMA ESA CANTIDAD

		mov ax, 4c00h
		int 21h
	main endp

	encuentra proc
	;CARÁCTER		ss:[bp+4]
	;OF POS			ss:[bp+6]
	;OF TEXTO		ss:[bp+8]

		push bp ; Mando la direccion de BP al stack para no perderla
		mov bp, sp ;Y trabajo con bp por que no puedo mover el sp
		push bx
		push ax
		push si 

		mov bx, ss:[bp+8]
		mov si, ss:[bp+6]
		mov ax, ss:[bp+4]

		xor ah, ah 

procEncuentro:
		cmp [bx], byte ptr 24h    ; 003f ; 2
		je finEncuentra
		cmp [bx], al ;Comparo las posiciones con el caracter que quiero buscar
		je encontrado
		inc ah ;Contador de posiciones
		inc bx ;Incremento la posicion del array
	jmp procEncuentro

encontrado:
		inc ah
		mov [si], byte ptr ah ; Paso 'ah' a 1 solo byte para que dosbox no m joda
		jmp final	

finEncuentra:	
		mov [si], byte ptr 255; DEVUELVO CODIGO DE ERROR NO ENCONTRÖ
final:
		pop si
		pop ax
		pop bx
		pop bp
		ret 6
	encuentra endp

	carga proc
	push bx ; PROFILAXIS para no perder las posiciones de memoria originales
	push dx
	push ax

	mov bx, dx ; CARGO EL OFFSET EN BX
	mov dl, al ; MUEVO EL CARACTER DE FINALIZACIÖN A DL

cargaTexto:
	mov ah, 1
	int 21h
	cmp al, dl
	je finCarga 
	mov [bx], al 
	inc bx
jmp cargaTexto
finCarga:
	pop ax
	pop dx
	pop bx
	ret
	carga endp
end