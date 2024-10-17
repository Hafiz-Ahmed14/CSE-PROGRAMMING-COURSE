.model small
.stack 100h
.data
a db "Enter your number: $"
msg db "Hello World! $"
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

    mov ah, 9
    lea dx, msg
    int 21h

    mov ah, 2
    mov dl, 10
    int 21h 
    mov dl, 13
    int 21h

    inc cx
    jmp Loop_start

    exit:
    mov ah, 4ch
    int 21h
    main endp

end main