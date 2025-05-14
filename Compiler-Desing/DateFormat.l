%{
#include <stdio.h>
%}

%%

[0-9][0-9]-[0-9][0-9]-[0-9][0-9][0-9][0-9] {
    printf("Valid date format: %s\n", yytext);
}

.+ {
    printf("Invalid! Use DD-MM-YYYY format\n");
}

%%

int yywrap() { return 1; }

int main() {
    printf("Enter date: ");
    yylex();
    return 0;
}
