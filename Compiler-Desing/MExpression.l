%{
#include <stdio.h>
#include <stdlib.h>

int paren_count = 0;
int valid = 1;
%}

%%

[0-9]+(\.[0-9]+)?    
[ \t]+              
[\+\-\*/]            
"("                 { paren_count++; }
")"                 { 
                      if (paren_count == 0) {
                        valid = 0;
                      } else {
                        paren_count--; 
                      }
                    }
\n                  { return 0; }
.                   { valid = 0; }

%%

int main() {
    printf("Enter expression: ");
    yylex();
    if (valid && paren_count == 0) {
        printf("Valid expression.\n");
    } else {
        printf("Invalid expression.\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}
