#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recFibo(int i){

   if(i == 0 || i == 1){
      return i;
   }

   return (recFibo(i-1) + recFibo(i-2));
}

int main(){

   int i, num;
   printf("How many numbers in the sequence would you like to see? ");
   scanf("%d",&i);

   for(int j = 0; j <= i; j++){
      printf("%d ",recFibo(j));
   }
   printf("\n");

   return 0;
}
