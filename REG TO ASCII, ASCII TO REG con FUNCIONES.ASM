.8086
.model small
.stack 100h
.data
numero db 30h,30h,30h, '$'
.code
main proc
	mov ax, @data
	mov ds, ax

	mov dl, 15; Valor a mostrar
	mov bx,offset numero
        call regtoascii
        mov dx, offset numero
        call imprimir

        mov dx, offset numero ;recibe el nro en ascii
        call asciitodec
        mov ax, 4c00h
        int 21h
main endp

imprimir proc 
        push ax
       
        mov ah,9
        int 21h

        pop ax
        ret
imprimir endp

regtoascii proc  ;recibe en bx el offset de una variable de 3 bytes, y el numero a convertir por dl no mayor a 255
        push ax
        push dx

	add bx,2
	xor ax,ax
	mov al, dl
	mov dl, 10
	div dl
	add [bx],ah

	xor ah,ah
	dec bx
        div dl
	add [bx],ah

	xor ah,ah
	dec bx
        div dl
	add [bx],ah

        pop dx
        pop ax

        ret
regtoascii endp

asciitodec proc ;RECIBE EN BX EL OFFSET DE UNA VARIABLE DE 3 DIGITOS ASCII Y DEVUELVE EN CX LA CANTIDAD NUMERICA

        push ax
        push bx
        ;push cx ;no se sube al stack porque vuelve como parametro
        push dx

        mov cx, 0
        sub [bx], 30h ;30h
        mov al, [bx]  ;0
        mov dl, 100
        mul dl 
        add cx, ax 

        inc bx
        sub [bx], 30h
        mov al, [bx]
        mov dl,10
        mul dl
        add cx,ax

        inc bx
        sub [bx], 30h
        add cl, [bx]

        pop dx
        ;pop cx
        pop bx
        pop ax

        ret
asciitodec endp

end main
