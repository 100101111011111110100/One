#ifndef MAIN_H
#define MAIN_H
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct node{
      char c;
      struct node * n_ptr;
   }node;
   node * init(char c){
      node * elem =(node *) malloc(sizeof(node));
      if(elem!=NULL){
         elem->c=c;
         elem->n_ptr=NULL;
      }
      return elem;
   }
   int insert(node *elem,node * place,char c){
      int flag=0;
      node * tmp = init(c);
      if(tmp!=NULL){
         while(elem->n_ptr!=place) elem=elem->n_ptr;
         tmp->n_ptr=elem->n_ptr;
         elem->n_ptr=tmp;
         flag =1;
      }
      return flag;
   }
   node * push(node ** head,char c){
      node *elem=init(c);
      if(elem!=NULL){
         elem->n_ptr=*head;
      }
      return elem;
   }
   void print(node * elem){
      while(elem!=NULL){
         printf("%c",elem->c);
         elem=elem->n_ptr;
      }
      putchar('\n');
   }
   int poly(node * l,node *s){
      int flag=1;
      while(l!=NULL && s!=NULL){
         if(l->c!=s->c){
         flag=0; 
         break;
         }
         l=l->n_ptr;
         s=s->n_ptr;
      }
      return flag;}
   //node * pop(node ** head);
   void del(node * head){
      while(head!=NULL){
         node * tmp= head;
         head=head->n_ptr;
         free(tmp);
      }
      free(head);
   }
#endif
