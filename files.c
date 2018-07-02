#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLN 128

int main()
{
   FILE * fp = fopen("foo.txt","r");

   char input[MAXLN];
   char str[MAXLN];
   char newstr[MAXLN];
   int x,y,z;

   while(fgets(input,MAXLN,fp)){

      if(sscanf(input,"%d %d %d",&x,&y,&z) == 3)
         printf("%d %d %d\n",x,y,z);
      else if(sscanf(input,"blue %d %d",&x,&y) == 2)
         printf("blue %d %d\n",x,y);
      else{
         strcpy(newstr,input);
         newstr[strlen(newstr)- 1] = 0;
         printf("[%s] not matched.\n",newstr);
      }
   }

   fclose(fp);

   return 0;
}
