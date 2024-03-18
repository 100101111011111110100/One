#ifndef MAIN_H
#define MAIN_H

   #include <stdio.h>
   #include <stdlib.h>


   typedef struct node{
      char c;
      struct node * n_ptr;
   }node;
   
   node * init(char c){
      node * new_node=(node*)malloc(sizeof(node));
      if(new_node !=NULL){
         new_node->c=c;
         new_node->n_ptr=NULL;
      }
      return new_node;
   }

   int insert(node * head, node * place,char c){
   node * new_elem=init(c);
   int flag=0;
   if(new_elem !=NULL){
      while(head->n_ptr!=place) head=head->n_ptr;
      new_elem->n_ptr=place;
      head->n_ptr=new_elem;
      flag=1;
   }
   return flag;
   }
   void delet(node * root){
      while(root !=NULL){
      node * tmp=root;
      root=root->n_ptr;
      free(tmp);}
   }
   node * push(node * head,char c){
      node * new_elem =init(c);
      if(new_elem!=NULL) new_elem->n_ptr=head;
      return new_elem;
   }
   char pop(node ** head){
      int c = (*head)->c;
      //printf("!%p %c ->%p!\n",*head,(*head)->c,(*head)->n_ptr);
      if((*head)->n_ptr!=NULL){
      node * tmp = (*head);
      *head=(*head)->n_ptr;
      //printf("!%p %c ->%p!\n",*head,(*head)->c,(*head)->n_ptr);
      free(tmp);
      }else{
      free(*head);
      *head=NULL;
      }
      return c;
   }
   int add_list(node ** head,char c){
      int flag=1;
      if(*head==NULL){
         if((*head=init(c))==NULL)  flag=0;
      }else if(!insert(*head,NULL,c))  flag=0;
      return flag;
   }
   node * userInit(){
   node * head=NULL;
   int flag=1,c;
   while(flag && ((c=getchar())!='\0'&&c!='\n')){ 
      flag=add_list(&head,c);
   }
   if(flag ==0 && head !=NULL){
      delet(head);
      head=NULL;
   }
   return head;
   }
   
   void print( node *  head){
      while(head!=NULL){
         putchar(head->c);
         head=head->n_ptr;
      }
      putchar('\n');
   }
   
   int priority(char c){
      int res=0;
      if((c>='A'&&c<='Z')||(c>='a'&&c<'z')||(c>='0'&&c<='9'))res=1;
      else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^'||c=='('||c==')') res=2;
      return res;
   }
   int oper_priority(int c){
      int res =-1;
      if(c=='+'||c=='-') res=0;
      else if(c=='*'||c=='/'||c=='%') res=1;
      else if(c=='^') res=2;
      else if(c=='('||c==')') res=3;
      return res;
   }
   int operation(node * head,node ** stack,int c){
      int flag=1;
      printf("%c !%d!\n==========\nstack:",c,c == ')'); 
      if (head==NULL) flag=0;
      else if(*stack==NULL){ 
         *stack=init(c);
         if(stack==NULL)   flag=0;
      }else if (c==')'){
         while((*stack)->c!='(') insert(head,NULL,pop(&(*stack)));
         pop(&(*stack));
      }else if(oper_priority((*stack)->c)<oper_priority(c)){
         *stack=push(*stack,c);
      }else if (oper_priority((*stack)->c)>=oper_priority(c)){
         while((*stack)->c!='(' && oper_priority((*stack)->c)>=oper_priority(c)){
            insert(head,NULL,pop(&(*stack)));
         }
         *stack=push(*stack,c);
      }
     print(*stack);      
     puts("==========");
      return flag;
   }
   node * polish(node * list){
      node * head=NULL;
      node * stack=NULL;
      int flag=1;
      while(flag && list!=NULL){
         switch(priority(list->c)){
            case 1:
               flag = add_list(&head,list->c);
               break;
            case 2:
               flag=operation(head,&stack,list->c);
               break;
            default:
               break;
         }
         list=list->n_ptr;
      } 
      while(stack!=NULL){
         //printf("%p %c\n",stack,stack->c); 
         insert(head,NULL,pop(&stack););
         //printf("%p %c\n",stack,stack->c);
      }
      if(stack!=NULL) delet(stack);
      return head;
   }
   double mth(node * pol){
      double res=0;
      node * stack=NULL;
      while(pol!=NULL){
         switch(priority(pol->c)){
         }
         pol=pol->n_ptr;
      }
      }
#endif
