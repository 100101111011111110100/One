#include "main.h"


int main(){
   srand(time(NULL));
   node * elem_f=init(1);
   node * elem_s=init(0);
   int a=-1;
   int flag=elem_f!=NULL && elem_s!=NULL;
   for(int i =0,tmp=2;flag && i<4;i++){
      insert(elem_f,NULL,tmp++);
      insert(elem_s,NULL,tmp++);
   }
   print(elem_f);
   print(elem_s);
   if(flag) scanf("%d",&a);
   switch(a){
      case 0:
         //Задание 12-6
         concatenate(elem_f,elem_s);
         print(elem_f);
         delet(elem_f);
         break;
      case 1:
         //Задание 12-7
         node * elem =merge(&elem_f,&elem_s);
         print(elem);
         delet(elem);
         break;
      case 2:
         long int sum=0;
         float avr=0;
         for(int i=0;i<21;i++){
            insert(elem_f,NULL,rand()%100);
         }
         print(elem_f);
         average(elem_f,&sum,&avr);
         printf("sum is %ld || average is %.2f\n",sum,avr);
         delet(elem_f);
         delet(elem_s);
         break;
      case 3:
         node * el_em = revers(elem_f);
         if(el_em != NULL)
            print(el_em);
         delet(el_em);
         delet(elem_f);
         delet(elem_s);
         break;
      default:
         printf("n/a");
         break;
   }
   return 0;
}
