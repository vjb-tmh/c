#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/linked.h"

int main() {

   tPerson p1;

   strcpy(p1.name,"Spok");
   p1.age = 40;
   p1.weight = 107.5;

   printPerson(&p1);

   tPerson p2 = copyPerson(&p1);
   printPerson(&p2);

   tPerson * ptr1 = buildPerson();
   printPerson(ptr1);

   strcpy(ptr1->name,"Jim");
   ptr1->age = 35;
   ptr1->weight = 180.5;
   printPerson(ptr1);

   tPerson * ptr2 = buildPerson();
   printPerson(ptr2);

   strcpy(ptr2->name,"Bones");
   ptr2->age = 45;
   ptr2->weight = 160.5;
   printPerson(ptr2);

   // Person Linked List
   printf("\n>> Contents of linked list:\n\n");
   initList(ptr1);
   push(ptr2);
   printList();

   return 0;
}
