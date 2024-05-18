.8086
.model small
.stack 100h

.data
   botones dw 00
   botonesT db "00000",24h
   posX     db "00000", 24h
   posY     db "00000", 24h
   antX     dw 0
   antY     dw 0
   ButtonL  db "Left        ",24h
   ButtonR  db "Right       ",24h
   ButtonN  db "Sin Botones ",24h
   maxMC    dw 639
   maxML    dw 199
   maxPC    dw 80
   maxPL    dw 25


.code
     main proc
        mov ax, @data
        mov ds, ax


        mov ah, 0
        mov al, 03h 
        ;mov al, 12h ;ESTABA 03h 80x25 16 colores TEXTO
        int 10h

        mov ax, 1
        int 33h
        cmp ax, 0
        je fin2
        jmp arriba2
fin2: jmp fin

arriba2:  mov botones,bx
arriba: 

         in al, 60h
         cmp al, 1
         je fin2
         
         mov ax, 3
         int 33h
         push cx
         push dx

         cmp bx, 0
         je nada
         cmp bx, 1
         je left
         
         push si
         push dx
         push bx
         mov si, offset ButtonR
         mov dl, 1
         mov dh, 22
         mov bl, 15 
         call imprimirVideo

         mov cx, antY
         mov bx, antX
         call posicionM
         mov bl, 0
         mov al, " "
         call imprimirCaracter 
         ;RECIBE EN AL el CARACTER a IMPRIMIR en DH y DL donde debe imprimir
         ;EN BL el color


         pop bx
         pop dx
         pop si
         jmp cont
nada: 
         push si
         push dx
         push bx
         mov si, offset ButtonN
         mov dl, 1
         mov dh, 22
         mov bl, 15 
         call imprimirVideo

         pop bx
         pop dx
         pop si
         jmp cont
left:
         push si
         push dx
         push bx
         mov si, offset ButtonL
         mov dl, 1
         mov dh, 22
         mov bl, 15 
         call imprimirVideo

         pop bx
         pop dx
         pop si

         mov cx, antY
         mov bx, antX
         call posicionM
         mov bl, 19
         mov al, 219
         call imprimirCaracter 
         ;RECIBE EN AL el CARACTER a IMPRIMIR en DH y DL donde debe imprimir
         ;EN BL el color




cont:         pop cx
      cmp cx, antX
      je otro
         mov antX, cx
         xor ax, ax


         mov si, offset posX
         call regToAscii16

         push si
         push dx
         push bx
         mov si, offset posX
         mov dl, 1
         mov dh, 23
         mov bl, 10 
         call imprimirVideo

         pop bx
         pop dx
         pop si

otro:    
         pop dx
         cmp dx, antY
         je esto
         jmp sige
esto: jmp arriba

sige:    mov anty, dx
         mov cx, dx
         mov si, offset posY
         call regToAscii16

         push si
         push dx
         push bx
         mov si, offset posY
         mov dl, 1
         mov dh, 24
         mov bl, 10 
         call imprimirVideo

         pop bx
         pop dx
         pop si

         jmp arriba


fin:        mov ax, 4c00h
        int 21h
     main endp

    


imprimirVideo proc
;RECIBE EN si el offset de la variable a imprimir y en DH y DL donde debe imprimir
;EN BL el color

;POSICION
;AH = 02H
;BH = Página de vídeo
;DH = Línea donde situar el cursor
;DL = Columna donde situar el cursor

OtroCaracter:
   cmp byte ptr [si], 24h
   je termineImprimir
   mov ah, 2
   mov bh, 0
   int 10h

;IMPRESION
;AH = 09H
;AL = Código del carácter a escribir.
;BH = Página de vídeo donde escribir el carácter.
;BL = Atributo ó color que va a tener el carácter.
;CX = Cantidad de veces que se debe escribir el carácter, uno a continuación de otro.

  mov ah, 9
  mov al, [si]
  mov cx, 1
  int 10h
  inc dl
  inc si
  jmp OtroCaracter

termineImprimir:
   ret

imprimirVideo endp


imprimirCaracter proc
;RECIBE EN AL el CARACTER a IMPRIMIR en DH y DL donde debe imprimir
;EN BL el color

;POSICION
;AH = 02H
;BH = Página de vídeo
;DH = Línea donde situar el cursor
;DL = Columna donde situar el cursor

   mov ah, 2
   mov bh, 0
   int 10h

;IMPRESION
;AH = 09H
;AL = Código del carácter a escribir.
;BH = Página de vídeo donde escribir el carácter.
;BL = Atributo ó color que va a tener el carácter.
;CX = Cantidad de veces que se debe escribir el carácter, uno a continuación de otro.

  mov ah, 9
  mov cx, 1
  int 10h


   ret

imprimirCaracter endp

regToAscii16 proc
   ;Recibe en CX un nro de 16 bits, lo guarda en una variable que viene por SI
   push ax
   push dx
   push cx

         xor ax, ax
         xor dx, dx

         mov ax, cx ; GUARDO EL NRO

         mov cx, 10000
         div cx ; AHORA QUE DIVIDÍ EN AH TENGO EL RESTO Y EN AL EL RESULTADO
         add ax, 30h ; SUMO 30 h para convertir el nro en caracter ascii
         mov byte ptr [si], al; guardo el caracter en la posición mas significativa de la variable nro
        
         
         mov ax, dx ; GUARDO EL NUEVO VALOR A DIVIDIR EN AL
         xor dx, dx ; LIMPIO AH (para que no me haga lio con la división)
         mov cx, 1000 ; guardo el valor por el que voy a dividir en cl
         div cx     ; VUELVO A DIVIDIR
         add ax, 30h
         mov byte ptr [si+1], al
         

         mov ax, dx ; GUARDO EL NUEVO VALOR A DIVIDIR EN AL
         xor dx, dx ; LIMPIO AH (para que no me haga lio con la división)
         mov cx, 100 ; guardo el valor por el que voy a dividir en cl
         div cx     ; VUELVO A DIVIDIR
         add ax, 30h
         mov byte ptr [si+2], al
         
         mov ax, dx ; GUARDO EL NUEVO VALOR A DIVIDIR EN AL
         xor dx, dx ; LIMPIO AH (para que no me haga lio con la división)
         mov cx, 10 ; guardo el valor por el que voy a dividir en cl
         div cx     ; VUELVO A DIVIDIR
         add ax, 30h
         mov byte ptr [si+3], al
         

         add dx, 30h
         mov byte ptr [si+4] ,dl  
        
   pop cx
   pop dx
   pop ax
ret

regToAscii16 endp

posicionM proc
   ;este programa recibe en CX columna y en BX fila de la posición del mouse en pantalla
   ; devuelve en DX LA POSICIÓN de la pantalla DONDE estaría

   push bx
   push ax
   

   mov ax, maxPC
   mul cx
   div maxMC
   xor dx,dx
   mov cl, al

   mov ax, maxPL
   mul BX
   div maxML
   xor dx,dx
   mov dh, al
   mov dl, cl

   pop ax
   pop bx 
 ret
posicionM endp

end