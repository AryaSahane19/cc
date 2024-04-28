#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 
 
int isKeyword (char *str) 
{ int i; 
 char keywords[][10] = 
{"void","main","if","else","while","for","int"," loat","char","break","return"}; 
 int numKeywords = sizeof (keywords) / sizeof (keywords[0]); 
 for (i=0;i<numKeywords;i++) 
 { if (strcmp(str, keywords[i]) == 0) 
  { return 1; 
  } 
 } 
 return 0; 
} 
 
void lexicalAnalyzer (char *input) 
{ char *token = strtok(input, " "); 
 while (token != NULL) 
 { if (isKeyword(token)) 
  { printf("Lexeme: %s, Token: Keyword\n", token); 
  } 
  else if (isalpha(token[0])) 
  { printf("Lexeme: %s, Token: Identi ier\n",token); 
  } 
  else if (isdigit(token[0])) 
  { printf("Lexeme: %s, Token: Constant\n",token); 
  } 
  else 
  { printf("Lexeme: %s, Token: Operator\n",token); 
  } 
  token = strtok(NULL, " "); 
 } 
} 
 
int main() 
{ char input[250]; 
 printf("Enter the String:\n"); 
 fgets(input, sizeof(input), stdin); 
 input[strcspn(input, "\n")] = '\0'; 
 lexicalAnalyzer(input); 
    return 0; 
}  
