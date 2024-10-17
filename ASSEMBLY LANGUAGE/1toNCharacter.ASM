.model small
.stack 100h
.data

N DW 5

.code
main proc

mov ax,@data
mov ds,ax

mov cx,1
mov bx,N
mov dl,97

L1:
cmp cx,bx
jg exit 
mov ah,2
int 21h

inc dl
 
inc cx
jmp L1

exit:
mov ah,4ch
int 21h
main endp

end main