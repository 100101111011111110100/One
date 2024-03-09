#include "main.h"

#define SIZE 10
#define PATH "temp.dat"
void init_array(data * table[]);
int tr(const char *path,struct data * table[]);
int main(){
   srand(time(NULL));
   data* table[SIZE];
   init_array(table);
   tr(PATH,table);
   print_file(PATH);
   print_dic(table,SIZE);
   //printf("!1!\n");
   //data * temp=table[5]->n_ptr;
   //printf("table[5] : %d %c %p\n",table[5]->key,table[5]->value,table[5]->n_ptr);
   //printf("List table [5]: %d %c %p\n",temp->key,temp->value,temp->n_ptr);
   //temp=temp->n_ptr;
   //printf("List table [0]: %d %c %p\n",temp->key,temp->value,temp->n_ptr);
   clear(table,SIZE);
   //printf("!1!\n");
   putchar('\n');
   return 0;
}

void init_array(data * table[]){
   char ltr[24]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','X','Y','Z'};
   for(int i=0;i<SIZE;i++){
      table[i]=NULL;
   }
   for(int i=0,value=2;i<24;i++){
   if(i%3==0&&i>0)   value++;
   //printf("value %d\n",value);
   insert(value,ltr[i],table,SIZE);
   }
}

int tr(const char *path,struct data * table[]){
   FILE * main =fopen(path,"w+");
   if(main!=NULL){
      int number[7];
      char string[7];
      for(int i=0;i<7;i++){
         number[i]=2+rand()%9;
         if(number[i]<1||number[i]>=10){
            i--;
            continue;
         }
         //printf("!%d!",number[i]);
         fprintf(main,"%d",number[i]);
      }
      //putchar('\n');
      //fprintf(main,"\n");
      translat(main,number,string,table,0);
     fclose(main); 
   }else printf("n/a");
   return 0;
}

