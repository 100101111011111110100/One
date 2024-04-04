#ifndef POLSIH_H
#define POLISH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

   union value{
      char c;
      double i;
   };
   typedef struct node{
      union value number;
      int type;
      struct node * n_ptr;
   }node;
   
   node * init(union value v,int type){
      node * elem = (node*)malloc(sizeof(node));
      if(elem!=NULL){
         elem->number=v;
         elem->type=type;
         elem->n_ptr=NULL;
      }
      return elem;
   }
   int insert(node * head,node * place,union value v, int t){
      int flag =1;
      node * elem =init(v,t);
      if(elem !=NULL){
         while(head->n_ptr!=place) head=head->n_ptr;
         head->n_ptr=elem;
      }else flag=0;
      return flag;
      }
   void push(node ** head, union value v,int t){
      node * elem =init(v,t);
      if(elem!=NULL){
         elem->n_ptr=*head;
         *head=elem;
      }}
   union value pop(node ** head){
      union value res;
      res=(*head)->number;
      if((*head)->n_ptr!=NULL){
         node * tmp =*head;
         (*head)=(*head)->n_ptr;
         free(tmp);
      }else{
       free(*head);
       *head=NULL;
      }
      return res;
   }
   void delet(node * elem){
      while(elem!=NULL){
         node * tmp =elem;
         elem=elem->n_ptr;
         free(tmp);
      }
      if(elem !=NULL)   free(elem);
   }
   void print(node * elem){
      while(elem!=NULL){
         if(elem->type) printf("%lf",elem->number.i);
         else  putchar(elem->number.c);
         elem=elem->n_ptr;
      }
      putchar('\n');
   }
   int add_list(node ** head,union value n,int t){
      int flag=1;
      if((*head)!=NULL){ 
         if(!insert(*head,NULL,n,t)) flag=0;
      }else{
         if((*head=init(n,t))==NULL) flag=0;
      }
      return flag;
   }

  int priority(union value n){
      int res=0;
      //(n.c>='A'&&n.c<='Z')||(n.c>='a'&&n.c<='z')||
      if((n.c>='a'&&n.c<='z')||(n.c>='0'&&n.c<='9')||n.c=='.') res=1;
      else if  (n.c=='+'||n.c=='-'||n.c=='*'||n.c=='/'||n.c=='%'||n.c=='^'||n.c=='('||n.c==')') res=2;
      return res;
  }
  int oper_priority(union value n){
    int res =-1;
    if(n.c=='+'||n.c=='-') res=0;
    else if(n.c=='*'||n.c=='/'||n.c=='%') res=1;
    else if(n.c=='^') res=2;
    else if(n.c=='('||n.c==')') res=3;
    return res;
   }
   int operation(node * head,node **stack,union value n){
      int flag =1;
      int j=oper_priority(n);
      union value d;
      d.c=',';
      if(oper_priority(n)!=3) add_list(&head,d,0);
      //printf("!%p!\n",*stack);
      if (head==NULL) flag=0;
      else if(*stack==NULL){ 
            *stack=init(n,0);
            //printf(" NULL : ");
            //print(*stack);
            if(stack==NULL)   flag=0;
      }else if (n.c==')'){
            add_list(&head,d,0);
            while((*stack)->number.c!='('){
               insert(head,NULL,pop(&(*stack)),0);
            }pop(&(*stack));
      }else if(oper_priority((*stack)->number) <j){
         push(&(*stack),n,0);
      }else if (oper_priority((*stack)->number) >=j){
         while((*stack)->number.c!='(' && oper_priority((*stack)->number)>=j){
            insert(head,NULL,pop(&(*stack)),0);
            add_list(&head,d,0);
         }
         push(&(*stack),n,0);
      }
      return flag;
   } 
   node * restruct(node * head){
      while(head->number.c!=','){
         node * t =   head;
         head->n_ptr=t->n_ptr;
         head=head->n_ptr;
         free(t);    
      }
      return head;
   }
   double fnd_num(node ** stack){
      //print(*stack);
      double res=0;
      int a[]={48,49,50,51,52,53,54,55,56,57};
      for(int i=0;*stack!=NULL;i++){
         //printf("res == %lf\n",res);
         if((*stack)->number.c =='.'){
            int k=i*-1;
            i=-1;
            res*=pow(10,k);
            pop(&(*stack));
            continue;
         }
         int j=0;
         for(;j<10 && a[j]!=(*stack)->number.c ;j++) ;
         res+=(double)j*pow(10,i);
         pop(&(*stack));
      }
      return res;
   }
   

   int translate(node * head){
      int flag=0;
      node * stack =NULL;
      node * tmp = head;
      //print(head);
      // printf("translate : %p == %c \n",head,head->number.c);
      while(tmp->number.c!=','){
         if(stack!=NULL){
            push(&stack,tmp->number,0);
         }else{
            stack=init(tmp->number,0);
         }
         tmp=tmp->n_ptr;
      }
      print(head);
      print(stack);
      if(head != tmp)   head->n_ptr=restruct(head->n_ptr);
      print(head);
      // printf("%c ==",head->number.c);
      head->number.i=fnd_num(&stack);
      head->type=1;
      // printf("!%lf!\n",head->number.i);
      //print(head);
      //print(stack);
      delet(stack);
      return flag;
   }

   void convToNum(node * head){
      // printf("Conv : ");
      // print(head);
      while(head!=NULL){
         if(priority(head->number)==2||head->number.c==','){ 
            head=head->n_ptr;
            continue;
         }
         //printf("%c %p\n",head->number.c,head);
         translate(head);
         head=head->n_ptr;
      }
      
   }


   node * pol(node * head){
      node * stack = NULL;
      node * result = NULL;
      int flag=1;
      union value d;
      d.c=',';
      while(flag && head !=NULL){
         switch(priority(head->number)){
               case 1:
                  flag=add_list(&result,head->number,0);
                  //flag=add_list(&result,d);
                  break;
               case 2:
                  //flag=add_list(&result,d);
                  flag=operation(result,&stack,head->number);
                  break;
               default:
                  if(stack != NULL) delet(stack);
                  if(result !=NULL) delet(result);
                  printf("n/a\n");
                  result=NULL;
                  break;
         } 
         head=head->n_ptr;
      }   
      while(stack!=NULL){
         add_list(&result,d,0);
         insert(result,NULL,pop(&stack),0);
         //add_list(&result,d);
      }
      //print(result);
      if(result !=NULL) convToNum(result);
      return result;
   } 
   int ar_op(char c){
      int i=0;
      if(c=='+') i=1;
      else if(c=='-') i=2;
      else if(c=='*') i=3;
      else if(c=='/') i=4;
      else if(c=='%') i=5;
      else if(c=='^') i=6;
      return i;
   }
   int calculate(node ** head,int i){
      double a;
      int flag=1;
      if((*head)->n_ptr!=NULL){
      a=(*head)->number.i;  
      pop(&(*head));
      }else flag=0;
      printf("calculate : %d\n",i);
      if(flag){
         switch (i){
         case 1:
            (*head)->number.i+=a;
            break;
         case 2:
            (*head)->number.i-=a;
            break;
         case 3:
            (*head)->number.i*=a;
            break;
         case 4:
            (*head)->number.i/=a;
            break;
         case 5:
            (*head)->number.i=(int)(*head)->number.i%(int)a;
            break;
         case 6:
            pow((*head)->number.i,a);
            break;
         default:
            flag=0;
            break;
         }
      }
      return flag;
   }

   ///*
   node *  mth(node * p){
      int flag=1;
      node * stack=NULL;
      while(flag && p!=NULL){
         if(p->type==0 && p->number.c ==',') ;
         else if(p->type){
            push(&stack,p->number,p->type);
         }else if (p->type==0 && priority(p->number)==2){
           flag=calculate(&stack,ar_op(p->number.c));
         }
         printf("mth : ");
         print(stack);
         p=p->n_ptr;
      }
      if(flag==0){
         delet(stack);
         delet(p);
         printf("n/a");
         stack=NULL;
      }
      return stack;
   }
   //*/

   node * user_init(){
      node * head =NULL;
      int flag=1;
      union value n;
      while( flag && (( n.c=getchar() )!='\0' && n.c!='\n' )) add_list(&head,n,0);
      return head;
   }
   
#endif
/*
int main(){
   node * list =user_init();
   //print(list);
   node * p=pol(list);
   print(p);
   //node * res=mth(p);
   //print(res);
   //if(res!=NULL) delet(res);
   if(list !=NULL)delet(list);
   if(p !=NULL)delet(p);
   putchar('\n');
   return 0;
}*/
