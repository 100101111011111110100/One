#ifndef COMPILER_H
#define COMPILER_H
   #include"polish.h"
   #define SIZE 1000
   struct tableEntry {
      int symbol;
      char type; // 'c','l', or 'v'
      int location; // 000 to 999 memory simpletron
   };
      
   int checkEmpty(FILE * main){
         int flag=1;
         fseek(main,0,SEEK_END);
         if(ftell(main)==0) flag=0;
         fseek(main,0,SEEK_SET);
         //puts("2");
         return flag;
   }

   int condCheck  (char * s_ptr,const int * count ){
      int res=-1;
      if(*count ==0 && isdigit(s_ptr))   res=0;
      else if(stcrm(word,"rem")==0)   res=1;
      return res;
   }
   int table_init(struct tableEntry * table,int * count,char * word){
      int flag=1;
      int value;
      if(isdigit(word)) table[*count]=atoi(word);
      else  if(strlen(word)==1)  table[*count].symbol=*word;
      else flag=0;
      return flag;
   }
   int logic(char * word, int * mem, struct tableEntry * table, int * leftCount, int * rightCount,int * f_mem,const int * count){
      int flag =1; 
      switch(condCheck(word,count)){
         case 0:
            flag=table_init(table,leftCount,word);
            break;
         case 1:
            flag=0;
            break;
         case 2:

            break;
         default:
            flag=-1;
            break;
      }
      return flag;
   }

   int split(char * text,int * mem,struct tableEntry * table, int t_f[], int * m_count, int * leftCount,int * rightCount){
      int flag=1,count =0;
      char * s_ptr;
      char string[SIZE];
      strcpy(string,text);
      s_ptr=strtok(string," ");
      do{
         if()  count++;
         else{
            break;
         }
      }while((s_ptr=strtok(NULL," "))!=NULL);
      //putchar('\n');
      return flag;
   }
   int progInit(int * mem,struct tableEntry * table, int f_mem[]){
      int flag =1;
      char path[100];
      FILE * main=NULL;
      printf("Enter the path to file: ");
      if(scanf("%99s",path)!=1)  flag=0;
      else{
         main=fopen(path,"r");
         flag=checkEmpty(main);
      }
      int left=0,right=SIZE-1,m=0; // counts
      int count=1;
      while(count){
         char text[1000];
         //if(fscanf(main,"%999s",text)==EOF) break;
         if(feof(main)) break;
         fgets(text,sizeof(text),main);
         if(split(text,mem,&left,&right)==-1){
            count=0;
            flag=count;
         }
         //puts(text);
      }
      fclose(main);
      return flag;
   }
   void init_flags(int *flag){
     for(int i=0;i<SIZE;i++)  flags[i]=-1; 
   }
#endif
