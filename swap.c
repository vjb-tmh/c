#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int * x, int * y)
{
   int z;
   z = *x;
   *x = *y;
   *y = z;
}

int main() {

   int x, y;
   x = 5;
   y = 6;

   printf("Preswap = x: %d, y: %d", x, y);
   swap(&x,&y);
   printf("\nPostswap = x: %d, y: %d\n", x, y);

   return 0;
}
