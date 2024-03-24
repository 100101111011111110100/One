#include"main.h"
int main(){
	node memory[MEM];
	print();
	if(command_init(memory,choise())){
		brain(memory);
		/*for(int i=0;i<MEM;i++){
			printf("%d | %d\n",memory[i].num.i,memory[i].type);
		}*/
	}else	printf("n/a\n");
	return 0;
}
