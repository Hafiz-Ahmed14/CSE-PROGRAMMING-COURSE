.model small 
.stack 100h
.data
str1 db "Enter a capital letter: $"
str2 db 10, 13, "Small letter is: $"
char db ? ; Declare a variable to store the input character

.code 
main proc
    mov ax, @data
    mov ds, ax

    ; Display prompt to enter a capital letter
    mov ah, 09h
    lea dx, str1
    int 21h 

    ; Read the capital letter input from the user
    mov ah, 01h 
    int 21h 
    mov char, al ; Store the input character in `char`

    ; Convert to lowercase by adding 20h to ASCII value
    add char, 20h

    ; Display the message "Small letter is: "
    mov ah, 09h
    lea dx, str2
    int 21h 

    ; Display the lowercase character
    mov dl, char
    mov ah, 02h
    int 21h 

    ; Exit program
    mov ah, 4Ch
    int 21h
main endp
end main
