.model small
.stack 100h
.data
    a    db 'Enter your first number $'
    b    db 10,13,'Eneter your second number $'
    c    db 10,13,'Largest Number: $'

.code

main proc
            mov ax, @data
            mov ds, ax

            mov ah, 9
            lea dx, a
            int 21h

            mov ah, 1
            int 21h
            mov bl, al

            mov ah, 9
            lea dx, b
            int 21h

            mov ah, 1
            int 21h
            mov bh, al

            mov ah, 9
            lea dx, c
            int 21h

    biggest:
            cmp bl, bh
            jg  l1
            jmp l2


    l1:     
            mov ah, 2
            mov dl, bl
            int 21h
            jmp exit

    l2:     
            mov ah, 2
            mov dl, bh
            int 21h
    

    exit:   
            mov ah, 4ch
            int 21h
main endp
end main
