.model small
.stack 100h
.data
m db 'I love bangladesh $'

.code
main proc
    ;1 input a character
    ;2 output a character
    ;9 output a string
    mov ax,@data
    mov ds, ax

    mov ah, 9
    lea dx, m
    int 21h

    exit:
    mov ah, 4ch
    int 21h
    main endp
end main