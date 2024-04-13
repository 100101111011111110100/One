#include "main.h"
void check_stack();
int main(){
   //check_stack();
   node * list=userInit();
   if(list!=NULL){
      print(list);
      node * pol=polish(list);
      print(pol);
      if(pol!=NULL) delet(pol);
   }
   putchar('\n');
   
   if (list != NULL) delet(list); 
   return 0;
}

void check_stack(){
   node * elem =init('v');
   int i=1;
   printf("!%p (%p)!\n",elem,elem->n_ptr);
   while(elem !=NULL){
      if(i++==3)
         break;
      elem=push(elem,'A');
      printf("%p (%p)==  ",elem,elem->n_ptr);
      putchar(pop(&elem));
      printf("%p (%p)\n",elem,elem->n_ptr);
   }
   putchar(pop(&elem));
   //delet(elem);
}
