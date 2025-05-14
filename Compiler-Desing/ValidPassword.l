%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool has_letter = false;
bool has_digit = false;
bool has_special = false;

// Define the yywrap function to avoid the linking error
int yywrap(void) {
    return 1;  // End of input
}
%}

%%
[a-zA-Z]     { has_letter = true; }
[0-9]        { has_digit = true; }
[^a-zA-Z0-9\n\t ] { has_special = true; }
.|\n         ; // Ignore other characters
end {return 0;}
%%

int main(void)
{
    printf("Enter password: ");
    yylex();

    if (has_letter && has_digit && has_special)
        printf("Valid password: contains letter, digit, and special character.\n");
    else
        printf("Invalid password: must contain at least one letter, digit, and special character.\n");

    return 0;
}
