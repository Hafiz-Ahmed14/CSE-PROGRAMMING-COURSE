%{
    #include<stdio.h>
%}

%%

[0-9]+(\.[0-9]+)?   { printf("Numbers : %s\n", yytext); }
is|am|are|was|were   { printf("%s: is a verb\n", yytext); }
[a-zA-Z]+            { printf("%s: is not a verb\n", yytext); }

%%

int yywrap() { return 1; }

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}
