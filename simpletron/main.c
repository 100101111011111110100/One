#include"main.h"
int main(){
	node memory[MEM];
	if(command_read(memory)){
      if(brain(memory)==0) printf("n/a\n");
	}else	printf("n/a\n");
   return 0;
}
