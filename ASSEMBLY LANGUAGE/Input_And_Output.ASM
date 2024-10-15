.model small
.stack 100h
.code

main proc
    mov ah, 1    ; input a value
    int 21h      ; call value
    mov bl, al   ;set input value to a register

    mov ah, 1
    int 21h
    mov bh, al

    mov ah, 2
    mov dl, bl
    int 21h

    mov ah, 2
    mov dl, bh
    int 21h

    exit:
    mov ah, 4ch
    int 21h
    main endp
end main
