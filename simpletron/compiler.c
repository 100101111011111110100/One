#include "compiler.h"
int main(){
   int flags[SIZE]={0};
   struct tableEntry table[SIZE];
   int memory[SIZE];
   in_it(memory,flags,table);
   progInit(memory,table,flags);
   dumb(memory,flags,table);
   return   0;
}
