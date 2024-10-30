.model small
.stack 100h
.data

.code
main proc
    mov ax, @data
    mov ds, ax

    mov al, 30
    mov bl, 6

    xor ah, ah
    div bl
    mov bx, ax

    mov cx, 10
    mov si, 0

convert:
    xor dx, dx
    div cx
    add dl, 30h
    push dx
    inc si
    cmp ax, 0
    jnz convert

print:
    mov ah, 02h
print_loop:
    pop dx
    int 21h
    dec si
    jnz print_loop

    mov ah, 4Ch
    int 21h
main endp
end main
