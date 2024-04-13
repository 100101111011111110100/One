#ifndef MAIN_H
#define MAIN_H

   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

   typedef struct node{
      int value;
      struct node * n_ptr;
   }node;
   
   node * init(int data){
      node * elem=(node*) malloc(sizeof(node));
      if(elem !=NULL){
         elem->value=data;
         elem->n_ptr=NULL;
      }
      return elem;
   }
   void insert(struct node * root,struct node * place,int value){
      while(root->n_ptr!=place) root=root->n_ptr;
      node * elem=(node*)malloc(sizeof(node));
      if(elem!=NULL){
         elem->value=value;
         elem->n_ptr=place;
         root->n_ptr=elem;
      }
   }
   void print(struct node* root){
      while(root!=NULL){
      printf("%3d",root->value);
      root=root->n_ptr;
      }
      putchar('\n');
   }
   void delet(struct node* root){
      while(root!=NULL){
         node* temp =root;
         root=root->n_ptr;
         free(temp);
      }
      free(root);
   }
   void concatenate(node * elem_f,node * elem_s){
      while(elem_f->n_ptr!=NULL) elem_f=elem_f->n_ptr;
      elem_f->n_ptr=elem_s;
   }
   node * merge(node ** elemF,node ** elemS){
      node * root=NULL;
      node * elem_1=*elemF;
      node * elem_2=*elemS;
      while(elem_1!=NULL && elem_2 !=NULL){
         if(root==NULL)root=elem_1;
         node *tmp = elem_1->n_ptr;
         elem_1->n_ptr=elem_2;
         elem_2=elem_2->n_ptr;
         elem_1->n_ptr->n_ptr=tmp;
         elem_1=tmp;
      }
      return root;
   }
   void average(node * elem,long int * sum,float *average){
      int i=1;
      while(elem!=NULL){
        *sum+=elem->value;
         i++;
         elem=elem->n_ptr;
      }
      *average=*sum/i;
   }
   node * revers(node * elem){
      node * new_list=NULL;
      node * lst=NULL;
      node *root=NULL;
      int flag=1;
      while(elem !=lst && flag){
         puts("1");
         node * tmp=elem;
         while(tmp->n_ptr!=lst) tmp=tmp->n_ptr;
         lst=tmp;
         printf("%p == %d %p \n",lst,lst->value,lst->n_ptr);
         if(root!=NULL){
            printf("new_list %p == %d %p \n",new_list,new_list->value,new_list->n_ptr);
            insert(new_list,NULL,tmp->value);
            new_list=new_list->n_ptr;
            printf("%p\n",new_list);
         }else{
            new_list=init(tmp->value);
            if(new_list==NULL) flag=0;
            else root=new_list;
            printf("root is %p == %d %p \n",root,root->value,root->n_ptr);
         }
      }
      return root;
   }
#endif
