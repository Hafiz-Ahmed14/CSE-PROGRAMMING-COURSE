%{
#include <stdio.h>
#include <string.h>

int keyword_count = 0;

// List of valid C keywords
char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", NULL
};

// Function to check if the matched word is a keyword
int is_keyword(char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}

%option noyywrap

%%
end              { return 0; }

[a-zA-Z_][a-zA-Z0-9_]* {
    if (is_keyword(yytext)) {
        keyword_count++;
    }
}

[ \t\n]+      ; // Skip whitespace
.             ; // Ignore other characters

%%

int main(void) {
    printf("Enter a statement:\n");
    yylex();
    printf("Number of valid keywords: %d\n", keyword_count);
    return 0;
}
