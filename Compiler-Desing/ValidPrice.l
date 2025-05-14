%{
#include <stdio.h>
%}

%option noyywrap

%%

^BDT[ ]+[0-9]+\.[0-9]{2}$     {
    printf("Valid product price format: %s\n", yytext);
}

.*                        {
    printf("Invalid product price format: %s\n", yytext);
}

%%

int main()
{
    printf("Enter product price: ");
    yylex();
    return 0;
}
