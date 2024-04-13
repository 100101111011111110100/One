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
		//printf("%s\n1%s|%d %s\n2%s|%X %s\n","Choise :"," -- Decimal",-99999," -- to finish typing"," -- Hexadecimal",-99999," -- to finish typing ");
		if(scanf("%d",&i)!=1)	i=0;
		return i;
	}
   void clear(){
      int c;
      while((c=getchar())!='\0' && c!='\n');
   }
	void print(){
		printf("%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n%-4s %50s %-4s\n","****","Simpletron welcome you !","****","****","PLease typing your program, one by one command","****","****","(or data words) at a time. I will output the current","****","****","addres and a question mark (?) as a hint. the word you entered","****","****","will be placed at the specified address.","****");
	}
   int empty_check(FILE * a){
      int flag=1;
      fseek(a,0,SEEK_END);
      if(ftell(a)==0) flag=0;
      fseek(a,0,SEEK_SET);
      return flag;
   }
   int command_read(node * memory){
      int flag=1;
      FILE * com_file=NULL;
      if(flag) com_file=fopen("sml/tst.sml","rb");
      if(com_file!=NULL)   flag=empty_check(com_file);
      else flag=0;
      for(int i=0;flag && i<MEM ;i++){
         int v;
         if(fread(&v,sizeof(int),1,com_file)==1){
            memory[i].num.i=v;
            memory[i].type=0; 
         }else break;
      }
      if(com_file!=NULL)   fclose(com_file);
      return flag;
   }
   /*Не знаю как побороть проверку на корректность ввода даных из файла
    * Так как если буду проверка в цикле мешает корректной обработке 
    */
	int command_init(node *  memory,int choise){
      int flag=1;
		for(int i=0,j=0;flag && i<MEM;i++){
         printf("%02d? : ",i);
			switch(choise){
				case 1: scanf("%d",&j);
					break;
				case 2:	scanf("%x",&j);
					break;
				default:	flag=0;
					break;
			}
         //if(scanf("%d",&j)!=1)   flag=0;
			if(j==-99999) break;
			memory[i].num.i=j;
			int a=memory[i].num.i/10000;
			if(a>9||a<-9)	 flag=0;
			memory[i].type=0;
         clear();
		}
		return flag;
	}
	int input(node * mem,int i){
		int flag=1;
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
				if(j<MEM &&mem[j].type==1)	*ram=mem[j].num.d;
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
   
   int arithmetic(node * mem,int command,double * ram){
      int flag=1;
      int j=command%1000;
      if(j>MEM) flag=0;
      else if(mem[j].type==1){
         switch(command/1000){
            case 30:
                  *ram+=mem[j].num.d;
                  break;
            case 31:
                  *ram-=mem[j].num.d;
                  break;
            case 32:
                  if(mem[j].num.d==0){
                     flag=0;
                     puts("division by zero");
                  }else *ram/=mem[j].num.d;
                     break;
            case 33:
                     *ram*=mem[j].num.d;
                     break;
            case 34:
                     *ram=(int)*ram%(int)mem[j].num.d;
                     break;
            case 35:
                     *ram=pow(*ram,mem[j].num.d);
                     break;
            default:
                  flag=0;
                  break;
         }
      }else flag=0;
      return flag;
   }

   int control(node * mem, int command,int * pos,double * ram){
      int flag=1;
      int j=command%1000;
      puts("1");
      if(j<MEM && mem[j].type==0){
      switch(command/1000){
         case 40:
               *pos=j-1;
               break;
         case 41:
               if(* ram <0)   *pos=j-1;
               break;
         case 42:
               if(*ram==0) *pos=j-1;
               break;
         default:
               flag=0;
               break;
      }
      }
      return flag;
   }
   void str_in(node * mem,int j){
      int flag=1;
      clear();
      for(int c; (c=getchar())!='\0' && c!='\n';j++){
         mem[j].num.i=c;
         mem[j].type=3;
         if(j+2>=MEM){
            flag=0;
            mem[j+1].num.i='\0';
            mem[j+1].type=3;
            break;
         }
         if(flag){
            mem[++j].num.i='\0';
            mem[j].type=3;
         } 
   }
   }
   void str_out(node * mem,int j){
      for(;j<MEM && mem[j].type==3 && mem[j].num.i!='\n';j++)  putchar(mem[j].num.i);
      putchar('\n');
   }
   int string(node * mem,int command){
      int flag=1;
      int j=command%1000;
      if(j>MEM)   flag=0;
      else{
         switch(command/1000){
            case 50:
                  str_in(mem,j);             
                  break;
            case 51:
                  str_out(mem,j);
                  break;
            default:
                  flag=0;
                  break;
         }
      }
      return flag;
   }
	int brain(node * mem){
		int flag =1;
		double ram=0;
		for(int i=0;flag && i<MEM && mem[i].num.i!=43000 && mem[i].type==0;i++){
			switch(mem[i].num.i/10000){
				case 1:
					flag=in_out(mem[i].num.i,mem);
					break;
				case 2:
					flag=r_access_memory(mem,&ram,mem[i].num.i);
					break;
				case 3:
               flag=arithmetic(mem,mem[i].num.i,&ram);
					break;
				case 4:
               flag=control(mem,mem[i].num.i,&i,&ram);
					break;
            case 5:
               flag=string(mem,mem[i].num.i);
               break;
            default:
					break;
			}
		}
		//printf("%f",ram);
		return flag;
	}
   void dumb_print(node * mem){
      for(int i=1;i<10;i++)   printf("%4d",i);
      for(int i=0,j=0;i<MEM;i++){
         if(i%10 ==0){
            printf("\n%2d :",j++);
         }
         if(mem[i].type==0 || mem[i].type==3)   printf("%7d",mem[i].num.i);
         else  printf("%#lf",mem[i].num.d);
      }
   }
#endif
