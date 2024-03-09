#include "main.h"
void clear();
int main(){
   node * stack =NULL;
   node * list = NULL;
   int c=0;
   int i;
   scanf("%d",&i);
   switch(i){
      case 0:
         stack=init(getchar());
         while(stack!=NULL&&((c=getchar())!='\0'&&c!='\n'))  stack=push(&stack,c);
         print(stack);
         del(stack);
         break;
      case 1:
         clear();
         c=getchar();
         stack=init(c);
         list=init(c);
         while(stack !=NULL && list != NULL && ((c=getchar())!='\0'&&c!='\n')){
            stack=push(&stack,c);
            if(insert(list,NULL,c)==0)
               break;
         }
         //print(list);
         //print(stack);
         if(poly(list,stack)) printf("String is poly!!\n");
         else printf("String is not poly!!\n");
         del(list);
         del(stack);
         break;
      default:
         printf("n/a");
         break;
   }
   putchar('\n');
   return 0;
}

void clear(){
   int c;
   while((c=getchar())!='\0' && c!='\n') ;}
