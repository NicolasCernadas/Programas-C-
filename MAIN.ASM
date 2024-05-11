.8086
.model small
.stack 100h
.data
	texto db 255 dup (24h),24h
	cantidad db 0 ;cantidad de A
			 db 0 ;cantidad de E
			 db 0 ;cantidad de I
			 db 0 ;cantidad de O
			 db 0 ;cantidad de U
	nroImp db "000",24h

	letra db 'A:',24h
		  db 'E:',24h 	
		  db 'I:',24h 
		  db 'O:',24h 
		  db 'U:',24h 
.code
	
	extrn lectura:proc
	extrn asciiToReg:proc
	extrn regToAscii:proc
	extrn printar:proc
	extrn cuentaVoc:proc

	main proc
		mov ax, @data
		mov ds, ax

		mov ah, 0
		mov al, 0
		mov dx, offset texto
		call lectura ;recibe en ah el modo con el que se va a trabajar , y en al el caracter modificador
					 ; recibe en dx el offset donde guardar lo leido

		mov bx, offset texto
		mov dx, offset cantidad
		call cuentaVoc ;ESTA FUNCION RECIBE EN BX, EL OFFSET DE UNA VARIABLE Y DEVUELVE EN OTRA VARIABLE (offset en DX) LA CANTIDAD DE CADA VOCAL SIENDO
					   ; v[0] cantidad de A, v[1] cantidad de E y asi sucesivamente


		mov cx, 5
		mov si, 0
		mov dx, offset letra

imprimir:	
			mov ah, 9
			int 21h
			add dx, 3
			push dx
			mov bx, offset cantidad 
			xor dh, dh
			mov dl, [bx+si]
			mov bx, offset nroImp
			call regToAscii
			mov bx, offset nroImp
			call printar
			inc si
			pop dx
		loop imprimir


		mov ax, 4c00h
		int 21h

main endp
end main

