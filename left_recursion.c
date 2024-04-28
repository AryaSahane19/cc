
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#de ine size 20 
 
int main() 
{ char pro[size], alpha[size], beta[size]; 
 int nt , i , j , index = 3; //nt-non terminal 
 printf("Enter Production Rule (Ex:S->S|A): "); 
 scanf("%s",pro); 
 nt = pro[0]; 
 if(nt == pro[index]) //Checking if Grammar is Left Recursive 
 { //Getting Alpha 
  for(i = ++index,j = 0;pro[i]!='|'; i++,j++){ 
   alpha[j] = pro[i]; 
   //Checking if there is NO Vertical Bar (|) 
   if(pro[i+j] == 0){ 
    printf("This Grammar can't be reduced.\n"); 
    exit(0); 
   } 
  } 
  alpha[j] = '\0'; //String ending NULL character 
  //Checking if there is a character after Vertical-Bar(|)  
  if(pro[++i] != 0){  
            //Getting Beta 
   for(j = i,i = 0;pro[j] !='\0';i++,j++){ 
    beta[i] = pro[j]; 
   } 
   beta[i] = '\0'; //String ending NULL character 
   // Showing Output without LEFT Recursion 
   printf("\nGrammar without Left Recursion: \n\n"); 
   printf(" %c->%s%c'\n", nt,beta,nt); 
   printf(" %c'->%s%c|#\n", nt,alpha,nt); 
  } 
  else 
   printf("This Grammar can't be reduced.\n"); 
 } 
 else 
  printf("\n This Grammar is not Left Recursive."); 
}
