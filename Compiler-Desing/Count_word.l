/*lex program to count number of words*/
%{ 
#include<stdio.h> 
#include<string.h> 
int i = 0; 
%} 

/* Rules Section*/
%% 
([' ']) {i++;}
.
"\n" {printf("%d\n", i+1); i = 0;} 
%% 

int yywrap(void){} 

int main() 
{ 
	// The function that starts the analysis 
	yylex(); 

	return 0; 
}
