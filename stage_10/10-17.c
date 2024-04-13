#include <stdio.h>

void reverseBites();
void bit (int value);
void b(int value);
int main(){
   reverseBites();
   putchar('\n');
   return 0;
}

void reverseBites(){
   int a,p,c,d;
   a=5;
   p=9;
   c='A';
   d='G';
   b(a);
   bit(a);
   b(p);
   bit(p);
   b(c);
   bit(c);
   b(d);
   bit(d);
}


void b(int value){
   unsigned int i;
   unsigned int mask=1<<31;
   for(i=1;i<=32;i++){
      putchar(value&mask ? '1':'0');
      value<<=1;
      if(i%8==0)putchar(' ');
   }
   putchar('|');
}
void bit (int value){
   unsigned int i;
   unsigned int mask=1<<31;
   printf("Value %d == ",value);
   for( i=1;i<=32;i++){
      putchar(value&mask ? '0':'1');
      value <<=1;
      if(i%8==0) putchar (' ');
   }
   putchar('\n');
}
