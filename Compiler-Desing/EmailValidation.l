%{
#include <stdio.h>
#include <string.h>
%}

EMAIL [a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
%%
^{EMAIL}$    { printf("Valid\n"); }
^.*$         { printf("Not Valid\n"); }
%%

int yywrap(void) { return 1; }

int main() {
    printf("Enter your Email: ");
    yylex();
    return 0;
}
