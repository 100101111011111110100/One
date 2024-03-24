#ifndef MAIN_H
#define MAIN_H
	#include<stdio.h>
	#include<math.h>
	#define MEM 1000
	union value{
		int i;
		double d;
	};
	typedef struct node{
		union value num;
		int type;
	}node;
	
	int choise(){
		int i;
		printf("%s\n1%s|%d %s\n2%s|%X %s\n","Choise :"," -- Decimal",-99999," -- to finish typing"," -- Hexadecimal",-99999," -- to finish typing ");
		if(scanf("%d",&i)!=1)	i=0;
		return i;
	}
	void print(){
		printf("%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n","****","Simpletron welcome you !","****","****","PLease typing your program, one by one command","****","****","(or data words) at a time. I will output the current","****","****","addres and a question mark (?) as a hint. the word you entered","****","****","will be placed at the specified address.","****");
	}
	int command_init(node *  memory,int choise){
		int flag=1;
		for(int i=0,j=0;flag && i<MEM;i++){
			switch(choise){
				case 1: scanf("%d",&j);
					break;
				case 2:	scanf("%x",&j);
					break;
				default:	flag=0;
					break;
			}
			if(j==-99999) break;
			memory[i].num.i=j;
			int a=memory[i].num.i/10000;
			if(a>9||a<-9)	 flag=0;
			memory[i].type=0;
		}
		return flag;
	}
		
	int input(node * mem,int i){
		int flag=1;
		{
			int c;
			while((c=getchar())!='\n' && c!='\0')	;
		}
		if(i>=0 && i<MEM){
			if(scanf("%lf",&mem[i].num.d)!=1)	flag=0;
		}else	flag=0;
		if(flag)	mem[i].type=1;
		return flag;
	}
	int deg(double i){
		int j=0;
		while(1){
			double tmp=i/pow(10,j);
			if(tmp==(int)tmp) break;
			else	j--;
		}
		return j*-1;
	}
	void out(node * mem, int i){
		if(i>=0 && i<MEM && mem[i].type){
			int tmp=deg(mem[i].num.d);
			printf("%.*lf\n",tmp,mem[i].num.d);
		}
	}
	int in_out(int command,node * mem){
		int flag =1;
		switch(command/1000){
			case 10:
				flag=input(mem,command%1000);

				break;
			case 11:
				out(mem,command%1000);
				break;
			default:
				flag=0;
				break;
		}
		return flag;
	}
	
	int r_access_memory(node * mem,double * ram,int command){
		int flag =1;
		switch(command/1000){
			case 20:
				int j=command%1000;
				if(j<MEM &&mem[j].type)	*ram=mem[j].num.d;
				else if(j<MEM && mem[j].type==0) *ram=mem[j].num.i;
				else flag=0;
				break;
			case 21:
				int k=command%1000;
				if(k<MEM){
					mem[k].num.d=*ram;
					mem[k].type=1;
				}else	flag=0;
				break;
			default:
				flag=0;
				break;
		}
		return flag;
	}

	int brain(node * mem){
		int flag =1;
		double ram=0;
		for(int i=0;flag && i<MEM && mem[i].num.i!=43000 && mem[i].type==0;i++){
			//printf("%d!\n",mem[i].num.i);
			switch(mem[i].num.i/10000){
				case 1:
					flag=in_out(mem[i].num.i,mem);
					break;
				case 2:
					flag=r_access_memory(mem,&ram,mem[i].num.i);
					break;
				case 3:
					break;
				case 4:
					break;
				default:
					break;
			}
		}
		//printf("%f",ram);
		return flag;
	}
#endif
