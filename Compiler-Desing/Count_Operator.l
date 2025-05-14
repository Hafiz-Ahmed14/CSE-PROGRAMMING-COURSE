#include<string.h> 
int i = 0; 
%} 

/* Rules Section*/
%% 
([/*+-=]) {i++;}
.
"\n" {printf("%d\n", i); i = 0;} 
%% 

int yywrap(void){} 

int main() 
{ 
	// The function that starts the analysis 
	yylex(); 

	return 0; 
}
