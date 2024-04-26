.8086
.model small
.stack 100h
.data
	mensaje1 db "Ingresa una cadena, vamos a cambiar los puntos (' . ') por comas (' , ')",0dh, 0ah, 24h
	mensaje2 db "El texto quedo asi: ",0dh, 0ah, 24h
	texto db 255 dup (24h), 0dh, 0ah, 24h
	textocambiado db 255 dup (24h), 0dh, 0ah, 24h
	espacio db " ",0dh,0ah,24h
	cantidadpuntos db "Cantidad de puntos: ",0dh, 0ah, 24h

.code
	main proc
		mov ax, @data
		mov ds, ax

		mov ah, 9
		mov dx, offset mensaje1
		int 21h

		mov bx, 0
		mov ch, 0

CargaTexto: ;Cargo la cadena de texto a cambiar
		mov ah, 1
		int 21h
		cmp al, 0dh
		je FinCarga
		mov texto[bx], al
		cmp texto[bx], 46
		je Cambio
		mov textocambiado[bx], al
		inc bx
		jmp CargaTexto

Cambio:	
		mov textocambiado[bx], 44
		inc bx
		inc ch ;contador de puntos
		jmp CargaTexto

FinCarga:
		mov ah, 9
		mov dx, offset mensaje2
		int 21h

		mov ah, 9
		mov dx, offset textocambiado
		int 21h

		mov ah, 9
		mov dx, offset espacio
		int 21h

		mov ah, 9
		mov dx, offset cantidadpuntos
		int 21h

		mov ah, 2
		mov dl, ch
		add dl, 30h
		int 21h

		mov ax, 4c00h
		int 21h
	main endp

end