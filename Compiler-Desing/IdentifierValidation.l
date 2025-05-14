%{
    #include<stdio.h>
%}

digit  [0-9]
letter [a-zA-Z]

%%

{letter}({letter}|{digit})*   { printf("id: %s\n", yytext); }
\n                            { printf("new line\n"); }

%%

int yywrap() { return 1; }

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}
