.model small
.stack 100h
.data
    a    dw ?
    b    dw ?
    c    db 'Input First Digit: $'
    d    db 10, 13, 'Input Second Digit: $'
    e    db 10, 13, 'Result is: $'
.code
main proc
         mov ax, @data
         mov ds, ax

         mov ah, 9
         lea dx, c
         int 21h

         mov ah, 1
         int 21h
         sub al, 48
         mov a, ax

         mov ah, 9
         lea dx, d
         int 21h

         mov ah, 1
         int 21h
         sub al, 48
         mov b, ax

         mov ah, 9
         lea dx, e
         int 21h

         mov ax, a
         mov bx, b
         mul bx

         add ax, 48
         mov dl, al
         mov ah, 2
         int 21h

    exit:
         mov ah, 4ch
         int 21h
main endp
end main
