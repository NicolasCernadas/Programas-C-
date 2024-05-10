.8086
.model small
.stack 100h
.data

	;SON DE LA FUNCIÓN
	nroAscii db '000',0dh,0ah,24h
	dataDiv db   100 ,10 ,1 

	;SON DEL MAIN
	texto db 255 dup (24h), 0dh, 0ah, 24h
	posicion db 0
	salto db 0dh,0ah, 24h
	
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

		mov dl, posicion
		lea bx, nroAscii
		lea si, dataDiv
		call regToAscii

		mov ah,9
		mov dx, offset Salto
		int 21h

		mov ah, 9
		lea dx, nroAscii
		int 21h

		mov ax, 4c00h
		int 21h
	main endp

	encuentra proc
	;CARÁCTER		ss:[bp+4]
	;OF POS			ss:[bp+6]
	;OF TEXTO		ss:[bp+8]

		push bp
		mov bp, sp
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
		cmp [bx], al
		je encontrado
		inc ah 
		inc bx
	jmp procEncuentro

encontrado:
		inc ah
		mov [si], byte ptr ah ; CANTIDAD
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
	push bx ; PROFILAXIS
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


;RECIBE EN DL UN NRO DE UN BYTE
;(BX) Y DEVUELVE EN UN OFFSET (DIRECCIÓN) 
;UNA VARIABLE CON 3 ASCII LLENA
; (SI), PARA DATADIV
regToAscii proc
	push ax
	push dx
	push cx
	push si
	push bx
;REG TO ASCII

	xor ax, ax
	mov al, dl

	mov cx, 3
	;ACA EMPIEZA EL CODIGO
proceso:
	mov dl, [si]
	div dl 
	add [bx],al 
	xchg al, ah  			;INTERCAMBIA VALORES
	xor ah, ah 
	inc bx 
	inc si
loop proceso
	
	pop bx
	pop si
	pop cx
	pop dx
	pop ax
ret
regToAscii endp
end