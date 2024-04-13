#ifndef COMPILER_H
#define COMPILER_H
   #include"polish.h"
   #include <ctype.h>
   #define SIZE 1000
   #define READ 10
   #define WRITE 11
   #define BRANCH 40
   #define HALT 43
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
         return flag;
   }
   int checkDigit(char *s_ptr){
      int flag=1;
      for(int i=0;*(s_ptr+i);i++){
         if(!isdigit(*(s_ptr+i))){
               flag=0;
               break;
         }
      }
      return flag;
   }
   int checkOper(char * s_ptr,int * sCount){
      int flag=0;
      if(*sCount ==0 && checkDigit(s_ptr))   flag=1;
      else if(strcmp(s_ptr,"input")==0)   flag=2;
      else if(strcmp(s_ptr,"let")==0)     flag=3;
      else if(strcmp(s_ptr,"print")==0)   flag=4;
      else if(strcmp(s_ptr,"goto")==0)      flag=5;
      else if(strcmp(s_ptr,"if")==0)    flag=6;
      else if(strcmp(s_ptr,"end")==0)  flag=7;
      return flag;
   }


   int insertDic(int symbol,struct tableEntry * dic, int * count,int * pos,int i){
      int flag=1;
      switch(i){
         case 1:
            dic[*count].type='C';
            break;
         case 2:
            dic[*count].type='L';
            break;
         case 3:
            dic[*count].type='V';
            break;
         default:
            flag=0;
            break;
      }
      dic[*count].symbol=symbol;
      dic[*count].location=*pos;
      (*count)++;
      return flag;
   }
   int inPut(char * command,int * mem, struct tableEntry * dic,int * lCount,int *rCount,int *dCount){
      int flag=1;
      if(*lCount<*rCount && (*rCount>0 && *lCount<SIZE-1))  mem[(*lCount)++]=READ * SIZE + *rCount;
      else flag=0;
      if(flag){
         insertDic((int)*command,dic,dCount,rCount,3);
         (*rCount)--;
      }
      return flag;
   }
   int fndDic(char * command,struct tableEntry * dic,int type){
      int flag=-1;
      for(int i=0;i<SIZE;i++){
         switch(type){
            case 86:
               if(flag==-1){
                  flag=isalpha(*command);
                  if(flag > 0)   flag=-2;
               }
               if(flag==-2 && dic[i].type==type && dic[i].symbol==(int)*command)  flag=dic[i].location;
             break;
            case 76:
               int j=atoi(command);
               if(dic[i].type==type && dic[i].symbol==j) flag=dic[i].location;
             break;
            default:
               break;
            }  
      }
      if(flag<-1) flag=-1;
      return flag;
   }
   int prInt(char * command,int * mem,struct tableEntry * dic,int * lCount){
      int flag=1;
      int loc=fndDic(command,dic,'V');
      if(loc !=-1 && *lCount<SIZE-1)  mem[(*lCount)++]=WRITE * SIZE +loc;
      else flag=0;
      return flag;
   }
   
   int insFlags(int *f_mem,int * lCount,int command){
      int flag=1;
      f_mem[*lCount]=command;
      return flag;
   }
   int goTo(char * command,int * mem, int * f_mem,struct tableEntry * dic,int *lCount){
      int flag=1,loc;
      if(!checkDigit(command)) flag=0;
      if((loc=fndDic(command,dic,'L'))!=-1) mem[(*lCount)++]=BRANCH*SIZE+loc ;
      else  if(loc==-1){
         insFlags(f_mem,lCount,atoi(command));
         mem[(*lCount)++]=BRANCH*SIZE;
      }
      return flag;
   }
   int close(int * mem,int * lCount){
      int flag=0;
      if(*(lCount)<SIZE)mem[(*lCount)++]= HALT *SIZE;
      return flag;
   }
   int splitAndTranslate (char * command,int * mem, struct tableEntry * dic, int *f_mem,int * lCount,int *rCount,int *dCount){
      int flag=1,count=0,b_point=1;
      char string[SIZE];
      char * s_ptr;
      strcpy(string,command);
      s_ptr=strtok(string," ");
      do{
         switch(checkOper(s_ptr,&count)){
            case 1:
               b_point=insertDic(atoi(s_ptr),dic,dCount,lCount,2);
               break;
            case 2:
               b_point=inPut(strtok(NULL," "),mem,dic,lCount,rCount,dCount);
               break;
            case 3:
               break;
            case 4:
               b_point=prInt(strtok(NULL," "),mem,dic,lCount);
               break;
            case 5:
               b_point=goTo(strtok(NULL," "),mem,f_mem,dic,lCount);
               break;
            case 7:
               b_point=close(mem,lCount);
               break;
            default:
               b_point=0;
               break;
         }
         count ++ ;
      }while((s_ptr=strtok(NULL," "))&&b_point);
      //printf("%d",f_mem[0]);
      return flag;
   }


   int progInit(int *mem,struct tableEntry * dic, int f_mem[]){
      int flag =1;
      char path[100];
      FILE * main=NULL;
      printf("Enter the path to file: ");
      if(scanf("%99s",path)!=1)  flag=0;
      else{
         main=fopen(path,"r");
         flag=checkEmpty(main);
      }
      int left=0,right=SIZE-1,d=0;
      while(!feof(main)){
         char text[1000];
         //if(feof(main)) break;
         fgets(text,sizeof(text),main);
         splitAndTranslate(text,mem,dic,f_mem,&left,&right,&d);
         //puts(text);
      }
      fclose(main);
      return flag;
   }
   void in_it(int * m,int * f,struct tableEntry *d){
      for(int i=0;i<SIZE;i++){
         m[i]=0;
         f[i]=-1;
         d[i].symbol=0;
         d[i].type=0;
         d[i].location=-1;
      }
   }
   void dumb(int * m,int * f,struct tableEntry *d){
      for(int i=1;i<=10;i++)  printf("%*d",10+i>=16?15:10+i,i);
      putchar('\n');
      printf("%2d ",0);
      for(int i=0,count=1;i<SIZE;i++){
         if(i!=0 && i%10==0){
            putchar('\n');
            printf("%2d ",count++);
         }
         printf("~%d |%d |%d %c %d~",m[i],f[i],d[i].symbol,d[i].type,d[i].location);
      }
   }
#endif
