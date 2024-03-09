#ifndef MAIN_H
#define MAIN_H
   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h> 
   size_t size(FILE * main);
   typedef struct data{
      int key;
      int value;
      struct data * n_ptr;
   }data;
 void clear_list(data * ptr);   
   //data * hashTable[SIZE];
   
   size_t hashFunction(char c,int size){
      size_t hash=5381;
      return (((hash<<5)+hash)+c) % size;
   }

   void insert(char key,int value,data *table[],int size){
      size_t index=hashFunction(key,size);
      data * item = (data*)malloc(sizeof(data));
      if(table[index]==NULL){
      item->key=key;
      item->value=value;
      item->n_ptr=NULL;
      table[index]=item;
      //printf("%ld | %p | %d %c\n",index,&table[index],table[index]->key,table[index]->value);
      }else if(table[index]!=NULL){
         //printf("1)%p\n",&table[index]);
         data * temp =table[index];
         //printf("1)%p | table[%ld] : %d %c %p\n",&table[index],index,table[index]->key,table[index]->value,table[index]->n_ptr);
         while(temp->n_ptr!= NULL) temp=temp->n_ptr;
         //printf("2)%p | table[%ld] : %d %c %p\n",&table[index],index,table[index]->key,table[index]->value,table[index]->n_ptr);
         data * node_item=(data*)malloc(sizeof(data));
         //printf("2)%p\n",&table[index]);
         if(node_item!=NULL){
            //printf("table[index] : %d %c %p\n",table[index]->key,table[index]->value,table[index]->n_ptr);
            //printf("new node %p\n",node_item);
            node_item->key=key;
            node_item->value=value;
            node_item->n_ptr=NULL;
            temp->n_ptr=node_item;
            //printf("%p | table[index] : %d %c %p\n",&table[index],table[index]->n_ptr->key,table[index]->n_ptr->value,table[index]->n_ptr->n_ptr);
         }
         //printf("4)%p | table[%ld] : %d %c %p\n",&table[index],index,table[index]->key,table[index]->value,table[index]->n_ptr);
         //printf("%ld | %p | %d %c\n",index,&table[index],table[index]->n_ptr->key,table[index]->n_ptr->value);
      }
   }
   int getValue(char key,data * table[],int size){
   size_t index = hashFunction(key,size);
   int value;
   if(table[index]!=NULL){
      value=table[index]->value;
   }else value=-1;
   return value;
   }
   void clear(data *table[],int size){
      for(int i=0;i<size;i++){
        if(table[i]!=NULL){
         if(table[i]->n_ptr !=NULL)clear_list(table[i]->n_ptr); 
         free(table[i]); 
         }
      }
   }
   void clear_list(data * ptr){
      data * temp=NULL;
      while(ptr!=NULL){
         temp=ptr;
         ptr=ptr->n_ptr;
         free(temp);
      }
      free(ptr);
   }
   void print_dic(data * table[],int size){
      puts("====================");
      for(int i=0;i<size;i++){
      if(table[i]!=NULL){
         printf("%d | %d %c\n",i,table[i]->key,table[i]->value);
         while(table[i]->n_ptr!=NULL){
            table[i]=table[i]->n_ptr;
            printf("%d | %d %c\n",i,table[i]->key,table[i]->value);
         }     
      }
      }
   }

   void translat(FILE * main,int * num,char * str,struct data * table[], int j){
      if(j==7){
      //putchar('\n');
      fprintf(main,"%s",str);
      //printf("%s\n",str);
      return ;
      }
      //printf("num[j]==%d\n",num[j]);
      size_t index=hashFunction(num[j],10);
      struct data * temp=table[index];
      for(int i=0;i<3&&temp!=NULL;i++){
         str[j]=temp->value;
         //printf("!%c! == !%p!\n",str[j],&temp);
         translat(main,num,str,table,j+1);
         temp=temp->n_ptr;
      }
   }
   void print_file(const char * path){
      FILE * main=fopen(path,"r");
      size_t s=size(main),temp=0;
      while(main!=NULL && temp<=s){
         char string [10]="";
         fread(string,1,sizeof(char)*7,main);
         puts(string);
         temp+=1;
      }
      if(main!=NULL) fclose(main);
   }
   size_t size(FILE * main){
      fseek(main,0,SEEK_END);
      size_t a=ftell(main);
      fseek(main,0,SEEK_SET);
      return a/(sizeof(char)*7);}
#endif
