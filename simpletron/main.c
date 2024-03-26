#include"main.h"
int main(){
	node memory[MEM];
	print();
	if(command_init(memory,choise())){
		if(brain(memory)==0) printf("n/a\n");
		/*for(int i=0;i<MEM;i++){
			printf("%d | %d\n",memory[i].num.i,memory[i].type);
		}*/
	}else	printf("n/a\n");
	dumb_print(memory);
   return 0;
}
