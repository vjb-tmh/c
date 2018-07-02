// structs, globals
typedef struct{
   char name[100];
   int age;
   float weight;
}tPerson;

struct Node{
   tPerson * pPerson;
   struct Node * next;
};

struct Node * head = NULL;

// typedefs
typedef struct Node tNode;

// print struct contents
void printPerson(tPerson * p)
{
   printf("Name: %s\n", p->name);
   printf("Age: %d\n", p->age);
   printf("Weight: %.2f\n", p->weight);
}

// create struct copy and return by value
tPerson copyPerson(tPerson * p)
{
   tPerson p1;
   strcpy(p1.name,p->name);
   p1.age = p->age;
   p1.weight = p->weight;

   return p1;
}

// allocate space for a person
tPerson * buildPerson(){

   tPerson * p = (tPerson*)malloc(sizeof(tPerson));
   if(!p)
      return NULL;

   strcpy(p->name,"blank");
   p->age = 0;
   p->weight = 0;

   return p;
}

// initialize linked list
tNode* initList(tPerson * p){
   tNode* p1 = (tNode*)malloc(sizeof(tNode));
   p1->pPerson = p;
   p1->next = NULL;
   head = p1;
}

// push person onto list
int push(tPerson * p)
{
   struct Node* p1 = (struct Node*)malloc(sizeof(struct Node*));
   p1->next = head;
   p1->pPerson = p;
   head = p1;
}

// print list
void printList(){

   struct Node* n = head;

   while(n){
      printPerson(n->pPerson);
      n = n->next;
   }
}

