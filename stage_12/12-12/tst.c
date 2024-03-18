#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   union value{
      char c;
      double i;
   };
   typedef struct node{
      union value number;
      struct node * n_ptr;
   }node;
   
   node * init(union value v){
      node * elem = (node*)malloc(sizeof(node));
      if(elem!=NULL){
         elem->number=v;
         elem->n_ptr=NULL;
      }
      return elem;
   }
   int insert(node * head,node * place,union value v){
      int flag =1;
      node * elem =init(v);
      if(elem !=NULL){
         while(head->n_ptr!=place) head=head->n_ptr;
         head->n_ptr=elem;
      }else flag=0;
      return flag;
      }
   void push(node ** head, union value v){
      node * elem =init(v);
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
         putchar(elem->number.c);
         elem=elem->n_ptr;
      }
      putchar('\n');
   }
   int add_list(node ** head,union value n){
      int flag=1;
      if((*head)!=NULL){ 
         if(!insert(*head,NULL,n)) flag=0;
      }else{
         if((*head=init(n))==NULL) flag=0;
      }
      return flag;
   }

  int priority(union value n){
      int res=0;
      if((n.c>='A'&&n.c<='Z')||(n.c>='a'&&n.c<='z')||(n.c>='0'&&n.c<='9')) res=1;
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
      if(oper_priority(n)!=3) add_list(&head,d);
      //printf("!%p!\n",*stack);
      if (head==NULL) flag=0;
      else if(*stack==NULL){ 
            *stack=init(n);
            printf(" NULL : ");
            print(*stack);
            if(stack==NULL)   flag=0;
      }else if (n.c==')'){
            add_list(&head,d);
            while((*stack)->number.c!='('){
               insert(head,NULL,pop(&(*stack)));
               //add_list(&head,d);
            }pop(&(*stack));
      }else if(oper_priority((*stack)->number) <j){
         push(&(*stack),n);
         //add_list(&head,d);
      }else if (oper_priority((*stack)->number) >=j){
         while((*stack)->number.c!='(' && oper_priority((*stack)->number)>=j){
            insert(head,NULL,pop(&(*stack)));
            add_list(&head,d);
         }
         push(&(*stack),n);
      }
      return flag;
   } 


   int translate(node * head){
      int flag=0;
      node * stack =NULL;
      while(head->number.c!=','){
         if(stack!=NULL){
            push(&stack,head->number);
         }else{
            stack=init(head->number);
         }
      }
      print(stack);
      delet(stack);
      return flag;
   }

   void convToNum(node * head){
      while(head!=NULL){
         if(priority(head->number)==2||head->number.c==','){
            head=head->n_ptr;
            continue;
         }
         printf("%c %")
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
                  flag=add_list(&result,head->number);
                  //flag=add_list(&result,d);
                  break;
               case 2:
                  //flag=add_list(&result,d);
                  flag=operation(result,&stack,head->number);
                  break;
               default:
                  break;
         } 
         head=head->n_ptr;
      }   
      while(stack!=NULL){
         add_list(&result,d);
         insert(result,NULL,pop(&stack));
         //add_list(&result,d);
      }
      convToNum(result);
      return result;
   } 
   /*
   double mth(node * p){
      double res=0;
      int flag;
      node * stack=NULL;
      while(flag && p!=NULL){
         switch(priority(p->number)){
            case 1:
               pop
               break;
            case 2:
               break;
            default:
               break;
         } 
         p=p->n_ptr;
      }
   }*/
   node * user_init(){
      node * head =NULL;
      int flag=1;
      union value n;
      while( flag && (( n.c=getchar() )!='\0' && n.c!='\n' )) add_list(&head,n);
      return head;
   }
   


int main(){
   node * list =user_init();
   node * p=pol(list);
   print(p);
   delet(list);
   delet(p);
   putchar('\n');
   return 0;
}
