%{
#include <stdio.h>

int lines = 0;
int chars = 0;

%}


%%
\n { lines++; }
. { chars++; }

end {return 0;}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input:\n");
    yylex();

    printf("No of lines: %d\nNo of characters: %d\n", lines, chars);
    return 0;
}
