#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
F)
#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MODULUS 34

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
*/
#define SIZE 1000

int chose(double memory[]);
void printArray(double *mass,int size);
int simpletron(double memory[],double accumulator);
int main(){
	double memory[SIZE]={0};
	//double d_memory[SIZE]={0};
	double accumulator=0;
	if(chose(memory)){
		simpletron(memory,accumulator);
	}else
		printArray(memory,SIZE);
	puts("\n(= ◕ ᆽ  ◕ =)");
	return 0;
	}
int chose(double memory[]){
	int ask_dec(int j);
	int ask_hex(double memory[],int m);
	int chek(int i);
	void print();
	int i,j=0,y=0;
	printf("***Please choise youre number system *** \nPlease enter: 1 -- Decimal\n2 -- Hexadecimal\n");
	puts("Else value will terminated programm");
	scanf(" %d",&y);
	switch(y){
	case 1:
		print();
		while((i=ask_dec(j))>=0&&i!=-99999){
		if(j==SIZE-1){
			puts("Memory stack overflow");
			puts("End the program");
			return 0;
			break;}			
		if(chek(i)){
			puts("Incorrect command");
			puts("***Please enter new command***");
			continue;}
		memory[j++]=i;}
		return 1;
		break;
	case 2:
		print();
		int m=0;
		while ((i=getchar())!=EOF&&i!='\n')
			;
		while(ask_hex(memory,m)){
			m++;
			if(m==SIZE-1){
			puts("Memory stack overflow");
			puts("End the program");
			return 0;
			}
		}
		return 1;
		break;
	default:
		puts("Terminated programm !!!");
		return 0;
		break;
	}
}
void print(){
	printf("%3s\n%3s\n%3s\n%3s\n%3s\n%3s\n","***Simpleton welcome you!***","***Please enter your program, one command ***","***(or data words) at a time. I will output the current ***","***address and a question mark (?) as a hint. The word you entered***","*** will be placed at the specified address. ***","***To stop entering the program, enter the number -99999(-1869F)***");
	puts("(A negative value will terminate the program)");
}
int ask_dec(int j){
	int i;
	printf("%02d (?) ",j);
	scanf("%d",&i);
	return i;
}
int ask_hex(double memory[],int m){
	int translate(int a);
	int chek(int i);
	int i,j=0,s=0,n=0,p,l=1;
	int a[SIZE]={0};
	printf("%02d (?) ",m);
	while ((i=getchar())!=EOF&&i!='\n'){
		a[j++]=i;
	}
	//printArray(&a[0],3);
	p=j-1;
	//printf("!!!P is %d!!!",p);
	for ( ; n < j; n++){
		if(a[n]==45){
			p--;
			l*=-1;
			continue;
		}
		//printf("!!! Translate is %d\n",translate(a[n]));
		s+=translate(a[n])*pow(16,p--);
	}
	//printf("!!! S is %d !!!\n",s);
	s*=l;
	if(s==-99999||m==SIZE-1)
		return 0;
	if(chek(s)){
		puts("Incorrect command");
		puts("***Please enter new command***");
		return ask_hex(memory,m);
	}
	memory[m]=s;
	return 1;
	//s=sizeof(a)/sizeof(a[0]);
	//printArray(&a[0],s);
	//printf("!s is %d\n",s);
}
int translate(int a){
	int b[16]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};
	int c[6]={97,98,99,100,101,102};
	int s_b=16,s_c=6,i;
	if(a>=97&&a<=102){
		for(i=0;i<s_c;i++){
			if(c[i]==a){
				return s_b-(s_c-i);
			}
		}
	}
	for(i=0;i<s_b;i++){
		if(b[i]==a)
			return i;
	}
	return 0;
}
int chek(int i){
	int brain(int i,int s);
	int a,b;
	a=brain(i,1);
	b=brain(i,2);
	if(a<1||a>=5)
		return 1;
	if(a==1&&(b<0||b>1)){
		return 1;
	}else if (a==2&&(b<0||b>1))
		return 1;
	else if(a==3&&(b<0||b>4))
		return 1;
	else if(a==4&&(b<0||b>3))
		return 1;
	return 0;
}
int brain(int i,int s){
	switch(s){
		case 1:
			return i/10000;
		case 2:
			return i/1000%10;
		case 3:
			return i%1000;
		default:
			break;
	}
	return 0;
}
int simpletron(double memory[],double accumulator){
	void read(double *var);
	void write(double *var);
	int brain(int i,int s);
	void load(double *memory,double *accum);
	int add(double *m1,double *m2,int i);
	void (*in_out[2])(double *)={read,write};
	int operation=0,operationCode=0,operand=0;
	double *var_ptr;
	int j=0;
	int i;
	while(memory[j]!=4300){
			i=memory[j++];
			operation=brain(i,1);
			operationCode=brain(i,2);
			operand=brain(i,3);
			var_ptr=memory+operand;
			//printf("\noperation is %d\noperationCode is %d\noperand is %d\nvar_ptr is %d\n",operation,operationCode,operand,*var_ptr);
			switch(operation){
			case 1:
				switch(operationCode){
					case 0:
						(*(in_out+operationCode))(var_ptr);
						break;
					case 1:
						(*(in_out+operationCode))(var_ptr);
						break;
					default:
						break;
				}
				break;
			case 2:
				switch(operationCode){
					case 0:
						load(var_ptr,&accumulator);
						break;
					case 1:
						load(&accumulator,var_ptr);
						break;
					default:
						break;
				}
				break;
			case 3:
				switch(add(&accumulator,var_ptr,operationCode)){
					case 0:
						break;
					case 1:
						puts("***Attempt to divide by zero***");
						puts("***Simpleton crash terminated the program***");
						return 1;
						break;
					case 2:
						puts("Memory overflow");
						puts("***Simpleton crash terminated the program***");
						return 1;
					default:
						break;
				}
				break;
			case 4:
				switch(operationCode){
					case 0:
						j=brain(i,3);
						break;
					case 1:
						if(accumulator<0)
							j=brain(i,3);
						break;
					case 2:
						if(accumulator==0)
							j=brain(i,3);
						break;
					case 3:
						break;
					default:
						break;
					}
			default:
				break;
		}
	}
	return 0;
}

void read(double *var){
	printf("Enter the number : ");
	scanf("%lf",var);
	puts(" ");
}
void write(double *var){
	if((*var-(int)*var)>0)
		printf("Number is : %f",*var);
	else
		printf("Number is : %.0f",*var);
	//printf("Number is : %d",*var);
	puts(" ");
}
void load(double *memory,double *accum){
	*accum=*memory;
}
int add(double *m1,double *m2,int i){
	//printf("\n%d\n",i);
	double j=*m1;
	switch(i){
		case 0:
			j+=*m2;
			break;
		case 1:
			j-=*m2;
			break;
		case 2:
			if ((*m2-(int)*m2)<0){
				return 1;
			}
			j/=*m2;
			break;
		case 3:
			j*=*m2;
			break;
		case 4:
			j=(int)j%(int)*m2;
			break;
		default:
			break;
	}
	if(j<=-9999||j>=9999){
		return 2;
	}
	*m1=j;
	return 0;
}
void printArray(double *mass,int size){
	printf(" ");
	for (int i = 0; i < 10; i++)
	{
		printf("%5d",i);
	}
	puts(" ");
	printf("%d ",0);
	for (int i = 0; i < size; i++)
	{
		if(i!=0&&i%10==0){
			puts(" ");
			printf("%d ",i/10);
		}
		printf("%.0lf ",*(mass+i));

	}
}