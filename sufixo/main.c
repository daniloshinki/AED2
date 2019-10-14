#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isSuffix(char s1[], char s2[]) 
    { 
      
        int n1 = strlen(s1), n2 = strlen(s2); 
        if (n1 > n2) 
        return false; 
        for (int i=0; i<n1; i++) 
        if (s1[n1 - i - 1] != s2[n2 - i - 1])
            return false; 
        return true; 
    } 


int main(void) {
  char s1[30];
  char s2[30];
  //char s1[30] = "inho";
  //char s2[30] = "shinkinho";
  printf("Digite o sufixo : ");
  fgets(s1, 30, stdin);
   printf("Digite a string a verificar : ");
  fgets(s2, 30, stdin);

  int result = isSuffix(s1, s2);

  if (result)  
            printf( "Sim! é sufixo"); 
        else
            printf("Não é sufixo");
}