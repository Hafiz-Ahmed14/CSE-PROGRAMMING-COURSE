%{
#include <stdio.h>
#include <ctype.h>
%}

DIGIT [0-9]
INT [+-]?{DIGIT}+
FLOAT [+-]?{DIGIT}*\.{DIGIT}+

%%
{INT}   { printf("Integer: %s\n", yytext); }
{FLOAT} { printf("Float: %s\n", yytext); }
[ \t\n]+ ;
.       { printf("Not a number: %s\n", yytext); }
%%

int yywrap(void) { return 1; }
int main() { printf("Enter tokens:\n"); yylex(); return 0; }
