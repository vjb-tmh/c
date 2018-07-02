#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void reverse(char * c){

   char d;

   for(int i = 0, j = (strlen(c) - 1); i < ceil(strlen(c)/2); i++, j--)
   {
      d = c[i];
      c[i] = c[j];
      c[j] = d;
   }
}

int main(){

   char c[100] = "foobar";
   reverse(c);
   printf("%s",c);

   return 0;
}
