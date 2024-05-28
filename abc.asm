;27/05 MOVIMIENTO INDIVIDUAL INDEPENDIENTE SOLUCIONADO
;SOLUCION AL FLICKER TODAVIA EN PROCESO (CAMBIO DE PAGINAS AL IMPRIMIR (INTENTE PERO NO FUNCIONA) REVISAR MAS)
;COMENTADAS EN LAS IMPRESIONES LOS CAMBIOS DE PAGINA
.8086
.model small
.stack 100h
.data
	;---------------------------------------
	; VARIABLES PARA LOS OBJETOS SECUNDARIOS
	;---------------------------------------
	;caracter a imprimir idem obj principal
	;coordenadas
	col2 db 0 ;eje x
	reng2 db 20 ;eje y
	col3 db 78
	reng3 db 10
	;coordenadas anteriores
	prev_col2 db 0
	prev_reng2 db 20
	prev_col3 db 78
	prev_reng3 db 10
	;-----------------------------------
	; VARIABLES PARA EL OBJETO PRINCIPAL
	;-----------------------------------
	;caracter a imprimir
	cuadrado db 219
	;coordenadas
	col db 38 ;eje x
	reng db 24 ;eje y
	;coordenadas anteriores
	prev_col db 38
	prev_reng db 24
	;------------------------
	; MANSAJE DE FIN DE JUEGO
	;------------------------
	mensaje db "Fin del juego$"
	
.code
	;MAIN
	main proc
	mov ax, @data
	mov ds, ax
	;Limpia la pantalla
	mov ah, 0Fh
	int 10h
	mov ah, 0
	int 10h
	
inicio:
	;-------------------------------------
	; FUNCIONES DE IMPRESION DE CARACTERES
	; (con parametros pasados por registro)
	;-------------------------------------
	;parametros de cuadrado azul (principal)
	; mov al, 01h
	; call cambiaPag
	mov dh, reng ;en dh recibe la posicion X } Para posicionamiento del cursor
	mov dl, col ;en dl recibe la posicion Y  }
	mov bl, 1 ;en bl el color
	mov al, cuadrado ;forma/figura a imprimir
	mov cx, 2 ;cantidad de veces que se imprime
	call imprime
	
	; mov al, 02h
	; call cambiaPag

	;parametros de cuadrado secundario (rojo)
	
	mov dh, reng2
	mov dl, col2
	mov bl, 4
	mov al, cuadrado
	mov cx, 2
	call imprime

	; mov al, 03h
	; call cambiaPag

	mov dh, reng3
	mov dl, col3
	mov bl, 4
	mov al, cuadrado
	mov cx, 2
	call imprime

	; mov al, 00h
	; call cambiaPag

	;------------------------
	; FUNCIONES DE MOVIMIENTO 
	;------------------------

	;carga las posiciones anteriores con las actuales
	mov dh, col
	mov dl, reng
	mov ch, prev_col
	mov cl, prev_reng
	call actualizaPos
	mov prev_col, ch
	mov prev_reng, cl
	
	;Pulsacion de tecla y movimiento del cuadrado azul
	call pulsacion
	
	call retardo
	call retardo
	call retardo
	call retardo
	call retardo
	call retardo


	;borrado de la posicion previa del cuadrado azul
	mov dh, prev_reng ;col anterior a donde estoy ahora
	mov dl, prev_col ;reng anterior a donde estoy ahora
	mov ch, reng
	mov cl, col
	mov al, cuadrado;forma
	mov bl, 0;color
	mov cx, 2;repeticion
	call borrado

	;-----------
	;PRIMER ROJO
	;-----------
	;carga las posiciones anteriores con las actuales del segundo objeto
	mov dh, col2
	mov dl, reng2
	mov ch, prev_col2
	mov cl, prev_reng2
	call actualizaPos
	mov prev_col2, ch
	mov prev_reng2, cl 

	;movimiento secundario
	mov dh, col2
	call movSecundario
	mov col2, dh

	;borra la posicion anterior
	mov dh, prev_reng2
	mov dl, prev_col2
	mov ch, reng2
	mov cl, col2
	mov al, 219
	mov bl, 0
	mov cx, 2
	call borrado

	;------------
	;SEGUNDO ROJO
	;------------
	;carga las posiciones anteriores con las actuales del segundo objeto
	mov dh, col3
	mov dl, reng3
	mov ch, prev_col3
	mov cl, prev_reng3
	call actualizaPos
	mov prev_col3, ch
	mov prev_reng3, cl 

	;movimiento secundario
	mov dh, col3
	call movSecundario3
	mov col3, dh

	;borra la posicion anterior
	mov dh, prev_reng3
	mov dl, prev_col3
	mov ch, reng3
	mov cl, col3
	mov al, 219
	mov bl, 0
	mov cx, 2
	call borrado

	;vuelve a empezar
	jmp inicio

	;finalizacion
	call finDelJuego
main endp

;Actualiza ejes X e Y, retorna posicion anterior en ch y cl
proc actualizaPos
	mov ch, dh
	mov cl, dl
	ret
actualizaPos endp

;funcion de validacion si se presiona una tecla
proc pulsacion
	xor ax, ax
	push ax
	mov ah, 01H ; Se fija si hay una tecla presionada
	int 16h
	jz volver
	mov ah, 00H ;Si encuentra una tecla, la obtiene y la manda a AL
	int 16h
	cmp al,'W'
	je sube 
	cmp al,'w'
	je sube
	cmp al,'A'
	je izquierda
	cmp al,'a'
	je izquierda
	cmp al,'S'
	je baja
	cmp al,'s'
	je baja
	cmp al,'D'
	je derecha
	cmp al,'d'
	je derecha
	cmp al, 27
	je fin
	jmp volver
	fin:
	call finDelJuego
	volver:
	pop ax
	ret
	;Esta en el borde, entonces no hago nada
	margen:
	jmp volver
	sube:
	cmp reng, 0
	je margen
	sub reng, 2
	pop ax
	ret
	baja:
	cmp reng, 24
	je margen
	add reng, 2
	pop ax
	ret
	izquierda:
	cmp col, 0
	je margen
	sub col, 2
	pop ax
	ret
	derecha:
	cmp col, 78
	je margen
	add col, 2
	pop ax
	ret
pulsacion endp

;Funcion de borrado de pantalla de posicion anterior
proc borrado
	;rutina de posicionamiento en pantalla
	mov bh, 0 ;pagina
	mov ah, 2
	int 10h
	;pinto de negro donde estaba el cuadrado
	mov ah, 09h
	mov bh, 0
	int 10h
	ret
borrado endp

proc movSecundario
	;La idea es la siguiente: que cuando llegue al margen derecho, sea 0 otra vez y vuelva a empezar
	push cx
	xor cx, cx
	call retardo
	call retardo
	call retardo
	pop cx
	comparacion:
	cmp dh, 78
	je vuelve
	jmp suma
	vuelve:
	mov dh, 0
	jmp final
	suma:
	add dh, 1
	final:
	ret
movSecundario endp

proc movSecundario3
	;misma idea anterior, pero para la izquierda
	push cx
	xor cx, cx
	call retardo
	call retardo
	call retardo
	pop cx
	comparacion3:
	cmp dh, 0
	je vuelve3
	jmp resta3
	vuelve3:
	mov dh, 78
	jmp final3
	resta3:
	sub dh, 1
	final3:
	ret
movSecundario3 endp

proc imprime
	;--------------------
	; IMPRESION DE OBJETO
	;--------------------
	;Imprime la caja azul
	;rutina de posicionamiento en pantalla
	mov bh, 0 ;pagina
	mov ah, 2 ;posicionamiento del cursor con los parametros de dh y dl
	int 10h
	;imprimo el cuerpo con la rutina 9
	mov ah, 9h
	mov bh, 0
	int 10h
	ret
imprime endp

proc finDelJuego
	mov ah, 0Fh
	int 10h
	mov ah, 0
	int 10h
	mov bh, 0 ;pagina
	mov dh, 10 ;renglon
	mov dl, 34 ;columna
	mov ah, 2
	int 10h
	mov ah, 9
	lea dx, mensaje
	int 21h

	mov ax, 4c00h
	int 21h
finDelJuego endp

proc cambiaPag
	mov ah, 05h
	int 10h
	ret
cambiaPag endp

proc retardo
	mov cx, 9FFFh
	decrementa:
	cmp cx, 0
	je incrementa
	dec cx
	jmp decrementa
	incrementa:
	cmp cx, 9FFFh
	je decrementa2
	inc cx
	jmp incrementa
	decrementa2:
	cmp cx, 0
	je finDec
	dec cx
	jmp decrementa2
	finDec:
	ret
retardo endp

end