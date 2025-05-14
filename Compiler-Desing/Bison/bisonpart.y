%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%union {
    int num;
}

%token <num> NUMBER
%left '+' '-'
%left '*' '/'
%type <num> E

%%

input:    /* empty */
        | input E '\n' { printf("The result is %d\n", $2); }
        ;

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | '(' E ')' { $$ = $2; }
 | NUMBER { $$ = $1; }
 ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
