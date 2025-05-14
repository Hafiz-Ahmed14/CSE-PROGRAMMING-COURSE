%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+    { yylval.num = atoi(yytext); return NUMBER; }
[ \t]+    { /* skip whitespace */ }
\n        { return '\n'; }
.         { return yytext[0]; }

%%
