#include "main.h"
void check_stack();
int main(){
   //check_stack();
   node * list=userInit();
   if(list!=NULL){
      print(list);
      node * pol=polish(list);
      print(pol);
   }
   putchar('\n');
   
   if (list != NULL) delet(list);
   return 0;
}

void check_stack(){
   node * elem =init('v');
   int i=1;
   while(elem !=NULL){
      if(i++==3)
         break;
      elem=push(elem,'A');
      putchar(pop(&elem));
   }
   putchar(pop(&elem));
   //delet(elem);
}
