.8086
.model small
.stack 100h
.data
	;---------------------------------------
	; VARIABLES PARA LOS OBJETOS SECUNDARIOS
	;---------------------------------------
	;caracter a imprimir idem obj principal
	enemigo db 207
	;coordenadas
	;matriz de 16 enemigos + o - centrados
	;reng1 db 10, 20, 30, 40, 50 que pasa si lo hacemos asi? con reng[0] = fila y a partir de ahi las columnas
	;reng2 db 15, 20, 30, 40, 50
	;reng3 db 20, 20, 30, 40, 50
	;reng4 db 25, 20, 30, 40, 50

	col2 db 0 ;eje x
	reng2 db 3 ;eje y
	col3 db 78
	reng3 db 2
	;coordenadas anteriores
	prev_col2 db 0
	prev_reng2 db 20
	color2 db 4
	prev_col3 db 78
	prev_reng3 db 10
	color3 db 4
	;-----------------------------------
	; VARIABLES PARA EL OBJETO PRINCIPAL
	;-----------------------------------
	;caracter a imprimir
	cuadrado db 219
	bala db 173
	;coordenadas
	col db 38 ;eje x
	reng db 24 ;eje y
	col_bala db 0 ;eje x
	reng_bala db 24 ;eje y
	;coordenadas anteriores
	prev_col db 38
	prev_reng db 24
	;flag para disparo
	flag_bala db 0
	;------------------------
	; MANSAJE DE FIN DE JUEGO
	;------------------------
	finJuego db "Fin del juego$"
	;------------------------
	; MANSAJE DE BIENVENIDA
	;------------------------
	bienvenida db "Bienvenidx!$"
	bienvenida2 db "Presiona cualquier tecla para empezar$"
	
.code
	;MAIN
	main proc
	mov ax, @data
	mov ds, ax
	
	;Limpia la pantalla
	mov ah, 0Fh
	int 10h
	mov ah, 00h
	mov al, 02h
	int 10h
	
	;primer mensaje de bienvenida
	mov bh, 0 ;pagina
	mov dh, 10 ;renglon
	mov dl, 34 ;columna
	mov ah, 2
	int 10h

	mov ah, 9
	lea dx, bienvenida
	int 21h

	;segundo mensaje
	mov dh, 12 ;renglon
	mov dl, 21 ;columna
	mov ah, 2
	int 10h
	
	mov ah, 9
	lea dx, bienvenida2
	int 21h

	mov ah, 00h
	int 16h
	
	;Limpia la pantalla
	mov ah, 0Fh
	int 10h
	mov ah, 0
	int 10h

	;limpio los registros para que empiece todo en 0
	xor ax, ax
	xor dx, dx

inicio:
	;parametros de cuadrado secundario (rojo)
	;si el cuadrado ya se exploto, no quiero que se imprima siempre y se vuelva a borrar, que directamente no se imprima mas
	cmp color2, 0 
	je noImprime
	mov dh, reng2
	mov dl, col2
	mov bl, color2
	mov al, enemigo
	mov cx, 3
	call imprime
	
	noImprime:
	cmp color3, 0
	je noImprime2
	mov dh, reng3
	mov dl, col3
	mov bl, color3
	mov al, enemigo
	mov cx, 3
	call imprime

	;--------------------------------------
	; FUNCIONES DE IMPRESION DE CARACTERES
	;--------------------------------------
	;parametros de cuadrado azul (principal)
	mov dh, reng ;en dh recibe la posicion X } Para posicionamiento del cursor
	mov dl, col ;en dl recibe la posicion Y  }
	mov bl, 1 ;en bl el color
	mov al, cuadrado ;forma/figura a imprimir
	mov cx, 1 ;cantidad de veces que se imprime(Los imprime para la derecha)
	call imprime
	
	sub dl, 1
	mov bl, 1 ;en bl el color
	mov al, 220 ;forma/figura a imprimir
	mov cx, 1 ;cantidad de veces que se imprime(Los imprime para la derecha)
	call imprime
	
	add dl, 2
	mov bl, 1 ;en bl el color
	mov al, 220 ;forma/figura a imprimir
	mov cx, 1 ;cantidad de veces que se imprime(Los imprime para la derecha)
	call imprime

	noImprime2:
	cmp flag_bala, 0 ;chequea si en el ciclo anterior se presiono la tecla de disparar
	jnz balaDisparada ;si se presiono es q en el buffer hay algo, entonces no es cero
	jz sigo ;sino sigue con las otras instrucciones

balaDisparada:
	;---------------
	; DISPARO BALA
	;---------------
	;la imprimo
	mov dh, reng_bala
	mov dl, col_bala
	mov bl, 8
	mov al, bala
	mov cx, 1
	call imprime

	;movimiento vertical
	mov dl, reng_bala
	call movVertical
	mov reng_bala, dl

	cmp color2, 4 ;comparo el color del objeto enemigo con rojo, si no es, es que ya se exploto
	jne explotado2 ;entonces sigue con la siguiente instruccion
	;si compara y es rojo, se fija si hay colision con el objeto
	mov dh, reng_bala
	mov dl, col_bala
	mov ch, reng2
	mov cl, col2
	call colisionBala
	mov reng_bala, dh
	cmp ah, 0 ;si choco, ah = 0, entonces salto a la respectiva etiqueta de choque
	je choco1

	sigo:
	jmp sigoSigo

	explotado2:
	cmp color3, 4 ;idem anterior
	jne nochoca
	mov dh, reng_bala
	mov dl, col_bala
	mov ch, reng3
	mov cl, col3
	call colisionBala
	mov reng_bala, dh
	cmp ah, 0
	je choco2
	jmp nochoca

	choco1:
	mov color2, 0 ;cambio el color del cuadrado a negro
	mov flag_bala, 0 ;para que no se siga imprimiendo en el proximo ciclo, una vez que choca, desaparece la bala
	jmp nochoca

	choco2:
	mov color3, 0
	mov flag_bala, 0
	jmp nochoca

	;no choco con ninguno, entonces sigo
	nochoca:
	sigoSigo:

	;------------------------
	; FUNCIONES DE MOVIMIENTO 
	;------------------------

	;carga las posiciones anteriores con las actuales
	mov dh, col
	mov dl, reng
	call actualizaPos
	mov prev_col, ch
	mov prev_reng, cl

	
	;Pulsacion de tecla y movimiento del cuadrado azul
	call pulsacion
	
	call retardo
	call retardo
	call retardo
	call retardo

	;-----------
	;PRIMER ROJO
	;-----------
	;carga las posiciones anteriores con las actuales del segundo objeto
	mov dh, col2
	mov dl, reng2
	call actualizaPos
	mov prev_col2, ch
	mov prev_reng2, cl 

	;movimiento secundario
	mov dh, col2
	call movSecundario
	mov col2, dh

	;------------
	;SEGUNDO ROJO
	;------------
	;carga las posiciones anteriores con las actuales del segundo objeto
	mov dh, col3
	mov dl, reng3
	call actualizaPos
	mov prev_col3, ch
	mov prev_reng3, cl 

	;movimiento secundario
	mov dh, col3
	call movSecundario3
	mov col3, dh

	;parametros para la funcion de colision
	; mov dh, reng
	; mov dl, col
	; mov ch, reng2
	; mov cl, col2
	; call colision

	;aca no paso dh ni dl porq ya estan cargados con lo anterior
	; mov ch, reng3
	; mov cl, col3
	; call colision

	;Limpia la pantalla
	mov ah, 0Fh
	int 10h
	mov ah, 0
	int 10h

	xor dx, dx
	xor cx, cx

	cmp color2, 0
	je casiFin
	casiFin:
	cmp color3, 0
	je findelmalditoJuego

	;vuelve a empezar
	jmp inicio

findelmalditoJuego:
	;finalizacion
	call finDelJuego
main endp

;Actualiza ejes X e Y, retorna posicion anterior en ch y cl
proc actualizaPos
	mov ch, dh
	mov cl, dl
	ret
actualizaPos endp

; se puede hacer que compare 3 posiciones al mismo tiempo? o tienen que ser 3 registros distintos
proc colisionBala
	mov ah, 1
	cmp dl, cl ;comparo las columnas
	je comparaRengBala
	inc cl ;sino comparo la proxima
	cmp dl, cl
	je comparaRengBala
	dec cl
	dec cl ;y la anterior
	cmp dl, cl
	je comparaRengBala
	jmp nadaBala ;sino sale
	comparaRengBala:
	cmp dh, ch ;y el renglon no puede ser uno mas o uno menos, es siempre el mismo
	je choqueBala
	jmp nadaBala
	choqueBala:
	mov dh, 24
	mov ah, 0
	ret
	nadaBala:
	ret
colisionBala endp

;Esta no va a ser necesaria por ahora por que no hay colision entre bloques, vemos si se puede reutilizar cuando disparen los enemigos
; proc colision
; 	cmp dl, cl ;comparo las posiciones 
; 	je comparaReng
; 	inc cl ;sino comparo la proxima
; 	cmp dl, cl
; 	je comparaReng
; 	dec cl
; 	dec cl ;y la anterior
; 	cmp dl, cl
; 	je comparaReng
; 	inc cl
; 	jmp nada ;sino sale
; 	comparaReng:
; 	cmp dh, ch
; 	je choque
; 	jmp nada
; 	choque:
; 	call finDelJuego
; 	nada:
; 	ret
; colision endp

;funcion de validacion si se presiona una tecla
proc pulsacion
	push ax
	xor ax, ax
	mov ah, 01H ; Se fija si hay una tecla presionada
	int 16h
	jz volver
	mov ah, 00H ;Si encuentra una tecla, la obtiene y la manda a AL
	int 16h
	cmp al, 'w' ;cambio la tecla de disparo al espacio
	je dispara
	cmp al, 'W'
	je dispara 
	cmp al,'A'
	je izquierda
	cmp al,'a'
	je izquierda
	; cmp al,'S'
	; je baja
	; cmp al,'s'
	; je baja
	cmp al,'D'
	je derecha
	cmp al,'d'
	je derecha
	cmp al, 27 ; tecla: [ESC]
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
	dispara:
	mov flag_bala, 1 ;cambia el flag de la bala a uno para el proximo ciclo
	sub reng_bala, 1 ;1 posicion mas arriba para que se dispare arriba del cuadrado
	mov dl, col 
	mov col_bala, dl ;cargo la columna de la bala con la columna del cuadrado azul
	pop ax
	ret
	;por ahora no usamos
	; baja:
	; cmp reng, 24
	; je margen
	; add reng, 2
	; pop ax
	; ret
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
; proc borrado
; 	;rutina de posicionamiento en pantalla
; 	mov bh, 0 ;pagina
; 	mov ah, 2
; 	int 10h
; 	;pinto de negro donde estaba el cuadrado
; 	mov ah, 09h
; 	mov bh, 0
; 	int 10h
; 	ret
; borrado endp

proc movSecundario
	;La idea es la siguiente: que cuando llegue al margen derecho, sea 0 otra vez y vuelva a empezar
	push cx
	xor cx, cx
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
	;aca si queremos darle mas movimiento, podemos pasarle mas parametros y cambiar tambien los renglones (tambien al de arriba)
	push cx
	xor cx, cx
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

proc movVertical
	;misma idea anterior, pero para arriba
	;aca si queremos darle mas movimiento, podemos pasarle mas parametros y cambiar tambien los renglones (tambien al de arriba)
	push cx
	xor cx, cx
	call retardo
	call retardo
	pop cx
	comparacionTop: ;compara si llega arriba de todo
	cmp dl, 0
	je top
	jmp resta4
	top:
	dec flag_bala ;si llega, el flag vuelve a ser cero
	mov dl, 24	  ;y el renglon 24
	jmp finalTop
	resta4:
	sub dl, 1
	finalTop:
	ret
movVertical endp

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
	mov dh, 12 ;renglon
	mov dl, 35 ;columna
	mov ah, 2
	int 10h
	mov ah, 9
	lea dx, finJuego
	int 21h

	mov ax, 4c00h
	int 21h
finDelJuego endp

;Provisoria para evitar flickering
; proc cambiaPag
; 	mov ah, 05h
; 	int 10h
; 	ret
; cambiaPag endp

proc retardo
	mov cx, 9FFFh
	decrementa:
	cmp cx, 0
	je incrementa
	dec cx
	jmp decrementa
	incrementa:
	cmp cx, 9FFFh
	je finDec
	inc cx
	jmp incrementa

	finDec:
	ret
retardo endp

end