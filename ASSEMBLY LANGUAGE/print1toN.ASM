; .model small
; .stack 100h
; .data
; N dw 5
; .code
; main proc
    
;     mov ax, @data
;     mov ds, ax
    
;     mov cx, 1
;     mov bx, N

;     Loop_start:
;     cmp cx, bx
;     jg exit

;     mov ax, cx
;     add al, 48
;     mov dl, al
;     mov ah, 2
;     int 21h

;     mov dl, ' '
;     mov ah, 2
;     int 21h

;     inc cx
;     jmp Loop_start

;     exit:
;     mov ah, 4ch
;     int 21h
;     main endp

; end main



.model small
.stack 100h
.data
a db "Enter your number: $"
.code
main proc
    
    mov ax, @data
    mov ds, ax 

    mov ah, 9
    lea dx, a
    int 21h 
    
    mov ah, 1
    int 21h
    sub al, 48
    mov bl, al

    mov cx, 1

    mov ah, 2
    mov dl, 10
    int 21h 
    mov dl, 13
    int 21h 


    Loop_start:
    cmp cx, bx
    jg exit

    mov ax, cx
    add al, 48
    mov dl, al
    mov ah, 2
    int 21h

    mov dl, ' '
    mov ah, 2
    int 21h

    inc cx
    jmp Loop_start

    exit:
    mov ah, 4ch
    int 21h
    main endp

end main


