#include <stdio.h>

int main(){
   int command[7]={10007,10008,20007,30008,21009,11009,43000};
   FILE * main = fopen("sml/tst.sml","wb");
   /*for(int i=0;main !=NULL && i<6;i++){
      fwrite(command+i,sizeof(int),1,main);
   }*/
fwrite(command+0,sizeof(int),1,main);
fwrite(command+1,sizeof(int),1,main);
fwrite(command+2,sizeof(int),1,main);
fwrite(command+3,sizeof(int),1,main);
fwrite(command+4,sizeof(int),1,main);
fwrite(command+5,sizeof(int),1,main);
fwrite(command+6,sizeof(int),1,main);
   fclose(main);
   return 0;
}
