#include <stdio.h>

int main(void){

   char answer[100];

    printf("Qual o seu nome? ");

    fgets(answer, sizeof(answer), stdin);

    printf("Ola, %s", answer);
    
   return 0;
}
