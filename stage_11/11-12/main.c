#include "main.h"
#define MAIN "hardware.dat"

int file_size(char * path);

int main(){
   if(file_size(MAIN))   init_file(MAIN);
   print_file(MAIN);
   init_data(MAIN);
   print_file(MAIN);
   putchar('\n');
   return 0;
}

int file_size(char * path){
   FILE * main =fopen(path,"r");
   int flag=1;
   if(main!=NULL){
      fseek(main,0,SEEK_END);
      size_t size =ftell(main);
      if(size>0) flag=0;
      fclose(main);
   }
   return flag;
}
