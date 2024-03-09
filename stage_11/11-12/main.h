#ifndef MAIN_H
#define MAIN_H
   #include <stdio.h>
   struct instrument{
      int n_write;//number of write
      char name[40];
      int q;//quantity
      float price;
   };

   int init_nWrite();
   int init_d_struct(struct instrument *elem);
   void clear();


   void init_file(char * path){
      FILE * main =fopen(path,"ab+");
      if(main!=NULL){
         for(int i=1;i<=100;i++){
            struct instrument elem={i,"-",0,0};
            fwrite(&elem,sizeof(elem),1,main);
         }
         fclose(main);
      }else printf("n/a");
   }
   void print_file(char *path){
   FILE * main=fopen(path,"rb");
   if(main!=NULL){
      size_t temp=0;
      struct instrument elem;
      fseek(main,0,SEEK_END);
      size_t size=ftell(main);
      fseek(main,0,SEEK_SET);
      size-=sizeof(elem);
      while(temp<=size){
         fread(&elem,sizeof(elem),1,main);
         //printf("%c",elem.name[0]);
         if(elem.name[0] != '-') printf("%5d %40s %10d %.2f\n",elem.n_write,elem.name,elem.q,elem.price);
         temp+=sizeof(elem);   
      }
      fclose(main);
   }else printf("n/a");
   }
   void init_data(char * path){
      FILE * main=fopen(path,"r+b");
      while(main!=NULL){
         struct instrument elem;
         elem.n_write=init_nWrite();
         if((elem.n_write>1&&elem.n_write<=100)&&init_d_struct(&elem)){
            fseek(main,(sizeof(elem)*(elem.n_write-1)),SEEK_SET);
            printf("position %ld\n",ftell(main)/sizeof(elem));
            fwrite(&elem,sizeof(elem),1,main);
            rewind(main);
         }else{
            fclose(main);
            main = NULL;
         }
      }
   }

   int init_nWrite(){
      int a;
      printf("Please enter the number of write :");
      if(scanf("%d",&a)!=1) a=-1;
      return a;
   }
   int init_d_struct(struct instrument * elem){
      int f=1;
      printf("Name : ");
      clear();
      for(int i=0,c;i<=39 && (c=getchar())!='\n';i++){
         if(i==39){
         elem->name[i]='\0';
         break;
         }
         elem->name[i]=c;
      }
      printf("Quantity : ");
      if(scanf("%d",&elem->q)!=1) f=0;
      printf("Price : ");
      if(scanf("%f",&elem->price)!=1) f=0;
      return f;
   }
   void clear(){
   int c;
   while((c=getchar())!='\0'&&c!='\n') ;
   }
#endif
