.model small
.stack 100h
.data   ; data segment
msg db 3       ; initilize a value in variable
msg2 db ?       ; input value initialize in variable

.code   ; code segment
main proc
    mov ax, @data  ; declare data segment in code segment
    mov ds, ax

    mov ah, 2
    add msg, 48
    mov dl, msg
    int 21h

    mov ah, 1
    int 21h
    mov msg2, al

    mov ah, 2
    ;add msg2, 48
    mov dl, msg2
    int 21h

    exit:
    mov ah, 4ch
    int 21h
    main endp
end main
