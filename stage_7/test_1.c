#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_X 1000
#define SIZE_Y 1000
void printArray(int *deck,const int size_x,const int size_y,int a);
int creator(int doors[][2],int maze[][SIZE_Y],const int size_x,const int size_y);
int way(int maze[][SIZE_Y],int x,int y, int const * out);
void dimensions(int *x,int *y);
int main(){
	srand(time(0));
	int maze[SIZE_X][SIZE_Y]={0};
	int doors[2][2]={0};
   int s_x=0,s_y=0;
   dimensions(&s_x,&s_y);
	/*if(creator(doors,maze,SIZE_X,SIZE_Y)&& way(maze,doors[0][0],doors[0][1],&doors[1][0])){
		//printf("%d %d\n%d %d\n",doors[0][0],doors[0][1],doors[1][0],doors[1][1]);
      puts("WIN!!!\n==============\n");
		printArray(&maze[0][0],SIZE_X,SIZE_Y,2);
		printArray(&maze[0][0],SIZE_X,SIZE_Y,1);
	}*/
	if(creator(doors,maze,s_x,s_y)&& way(maze,doors[0][0],doors[0][1],&doors[1][0])){
		//printf("%d %d\n%d %d\n",doors[0][0],doors[0][1],doors[1][0],doors[1][1]);
      puts("WIN_2!!!\n==============\n");
		printArray(&maze[0][0],s_x,s_y,2);
		printArray(&maze[0][0],s_x,s_y,1);
	}
	puts("\n(= ◕ ᆽ  ◕ =)");
	return 0;
}
void dimensions(int *x,int *y){
	void clr();
	puts("Hello !");
	printf("Please specify the width and height of the maze \n****integers only !****\n***write the values separated by a space*** \n: ");
	if(scanf("%d %d",x,y) <=1){
		clr();
		dimensions(x,y);
	}
	if(*x<=5|| *y <= 5){
		clr();
		dimensions(x,y);
	}
}
void clr(){
	int c;
	while((c=getchar())!='\n'&&c!=EOF)
		;
}
int way(int maze[][SIZE_Y],int x,int y,int const * out){
	//printArray(&maze[0][0],SIZE_X,SIZE_Y,1);
	int a[4][2]={
		{0,1},{1,0},
		{0,-1},{-1,0}
	};
	int b=0,c=0,i;
	if(x==*out&&y==*(out+1)){
		maze[x][y]='X';
		return 1;
	}
	for (i = 0; i < 4; i++){
		b=x+a[i][0];
		c=y+a[i][1];
		if(maze[b][c]=='.'){
			maze[x][y]='X';
			if (way(maze,b,c,out)){
				return 1;
			}
		}
	}
	maze[x][y]='.';
	return 0;
}
int creator(int doors[][2],int maze[][SIZE_Y],const int size_x,const int size_y){
	int in_out (int doors[][2],int maze[][SIZE_Y],int const * size_x, int const *size_y);
	int wall(int maze[][SIZE_Y],int const *size_x,int const * size_y);
   int c_way(int maze[][SIZE_Y],int x,int y,int const * out);
	int filling(int maze[][SIZE_Y],int const * size_x,int const *size_y);
   //if(in_out(doors,maze,&size_x,&size_y)&&wall(maze,&size_x,&size_y)){
     // printArray(&maze[0][0],size_x,size_y,2);
      //printArray(&maze[0][0],SIZE_X,SIZE_Y,2);
   //}
   //return 0;
	return in_out(doors,maze,&size_x,&size_y)&&wall(maze,&size_x,&size_y)&&c_way(maze,doors[0][0],doors[0][1],&doors[1][0])&&filling(maze,&size_x,&size_y);
   
  /*return in_out(doors,maze,&size_x,&size_y)&&wall(maze,&size_x,&size_y)&&c_way(maze,doors[0][0],doors[0][1],&doors[1][0]);*/
}
int in_out (int doors[][2],int maze[][SIZE_Y],int const * size_x,int const *size_y){
	int x,y,a;
	for (int i = 0; i < 2; i++){
		x=rand()%(*size_x);
		if(x==0||x==*size_x-1){
			y=rand()%(*size_y);
		}else{
			a=rand()%2;
			switch(a){
				case 0:
					y=0;
					break;
				case 1:
					y=*size_y-1;
					break;
				default:
					break;
			}
		}
	if((x==0||x==*size_x-1)&&(y==0||y==*size_y-1)){
		i--;
		continue;
	}
	if((doors[0][0]==x||doors[0][0]+1==x||doors[0][0]-1==x)&&(doors[0][1]==y||doors[0][1]+1==y||doors[0][1]-1==y)){
		i--;
		continue;
	}
	maze[x][y]='.';
   printf("x is %d|| y is %d || maze is %d\n",x,y,maze[x][y]);
   doors[i][0]=x;
	doors[i][1]=y;
   //printArray(&doors[0][0],2,2,2);
   //printArray(&maze[0][0],*size_x+1,*size_y+1,2);
	}
	return 1;
}
int wall(int maze[][SIZE_Y],int const *size_x,int const * size_y){
	//printf("s_x is %d s_y is %d\n",*size_x,*size_y);
   for (int i = 0; i < *size_x; i++){
      //printf("wall :: i is %d\n",i);
      //printArray(&maze[0][0],*size_x,*size_y,2);
			if(i==0||i==*size_x-1){
				for (int a = 0; a < *size_y; a++){
               //printArray(&maze[0][0],*size_x,*size_y,2);
					if(maze[i][a]=='.')
						continue;
					maze[i][a]='#';
				}
			}
			if(maze[i][0]!='.')
				maze[i][0]='#';
			if(maze[i][*size_y-1]!='.')
				maze[i][*size_y-1]='#';
			}  
	return 1;
}
int c_way(int maze[][SIZE_Y],int x,int y,int const * out){
	void r_m(int a[][2],int size);
	int b_cells(int maze[][SIZE_Y],int const *x,int const *y,int j);
	int pffin(int maze[][SIZE_Y],int x, int y);
	int a[4][2]={0};
	r_m(a,4);
	int b=0,c=0,i;
	for(i=0;i<4;i++){
		b=x+a[i][0];
		c=y+a[i][1];
		if(b==*out&&c==*(out+1)){
		maze[x][y]='.';
		maze[b][c]='.';
		//printArray(&maze[0][0],12,2);
		return 1;
		}
	}
	for(i=0;i<4;i++){
		b=x+a[i][0];
		c=y+a[i][1];
		//printf("b is -- %d c is %d\nb_cells(maze,&b,&c,12) is %d\n",b,c,b_cells(maze,&b,&c,1));
		if(maze[b][c]==0&&b_cells(maze,&b,&c,1)){
			maze[x][y]='.';
			//printArray(&maze[0][0],SIZE_X,SIZE_Y,2);
			if(c_way(maze,b,c,out)){
				//if(rand()%2==0){
					//printf("%d\n",pffin(maze,x,y));
					//printf("x -- %d ||| y -- %d |||\n",x,y);
					if(!pffin(maze,x,y))
						maze[x][y]='.';
				//}
				return 1;
			}	
		}
	}
	maze[x][y]=0;
	return 0;
}
int pffin(int maze[][SIZE_Y],int x, int y){
	void r_m(int a[][2],int size);
	int b_cells(int maze[][SIZE_Y],int const *x,int const *y,int j);
	int d[4][2]={0};
	int b=0,c=0,i;
	r_m(d,4);
	for(i=0;i<4;i++){
		b=x+d[i][0];
		c=y+d[i][1];
		//printf("b is -- %d c is %d\nb_cells(maze,&b,&c,12) is %d\n",b,c,b_cells(maze,&b,&c));
		if (maze[b][c]=='#'){
		return 1;
		}
		//printf(" b_cells(2) is %d\n",b_cells(maze,&b,&c,2));
		if(maze[b][c]==0&&b_cells(maze,&b,&c,2)){
			maze[x][y]='.';
			//puts("pffin");
			//printArray(&maze[0][0],12,2);
			if(pffin(maze,b,c)){
				return 1;
			}	
		}
	}
	maze[x][y]=0;
	return 0;
}
int filling(int maze[][SIZE_Y],int const * size_x,int const *size_y){
   int x,y;
	for (unsigned long i = 0; i <((*size_x)*(*size_y)); i++)
		{
         x=i/(*size_y)%(*size_x);
         y=i%(*size_y)%(*size_y);
         //printf("Filling :: i is %d|| x is %d || y is %d \n",i,x,y);
			if(maze[x][y]==0){
				maze[x][y]='#';
			}
		}
      //printArray(&maze[0][0],*size_x,*size_y,2);
		return 1;
}
void r_m(int a[][2],int size){
	int r_cond(int c[],int j,int size);
	int r=0;
	int b[4][2]={
		{0,1},{1,0},
		{0,-1},{-1,0}	
	};
	int c[4]={-1,-1,-1,-1};
	for (int i = 0; i < size; i++)
	{
		r=rand()%4;
		//printf("\ni --%d\nr -- %d \nr_cond(c,r,4) -- %d",i,r,r_cond(c,r,4));
		if(r_cond(c,r,4)){
				c[i]=r;
				a[i][0]=b[r][0];
				a[i][1]=b[r][1];
		}else{
			--i;
		}
	}
}
int r_cond(int c[],int j,int size){
	for (int i = 0; i < size; i++){
		if(c[i]==j)
			return 0;
	}
	return 1;
}
int b_cells(int maze[][SIZE_Y],int const *x,int const *y,int j){
	int a[8][2]={
		{0,-1},{-1,-1},
		{-1,0},{-1,1},
		{0,1},{1,1},
		{1,0},{1,-1}
	};
	int x1,y1;
	int chek=1;
	for (int i = 0; i < 8; ++i)
	{
		x1=*x+a[i][0];
		y1=*y+a[i][1];
		if(maze[x1][y1]=='.')
			chek++;
	}
	switch(j){
		case 1:
		if (chek>=3){
		return 0;
		}
			break;
		case 2:
		if (chek>=4){
			return 0;
			}
			break;
		default:
			break;
	}
	/*if (chek>=3){
		return 0;
	}*/
	return 1;
}

void printArray(int *deck,const int size_x,const int size_y,int a){
	for(int i=0;i<size_x*size_y;i++){
		if(i%size_y==0&&i!=0)
			puts(" ");
		switch(a){
		case 1:
			printf("%3c",*(deck+i));
			break;
		case 2:
			printf("%3d",*(deck+i));
			break;
		default:
			break;
		}
	}
	puts(" ");
   putchar('\n');
}

/*int main (){
   int x;
   int j=0;
            x=1;
      printf("%d\n",x++);
      printf("%d\n",x++);
      printf("%d\n",x++);
   while(j++<2){
      int p=2;
      printf("%d\n",j);
      printf("%d\n",p);
      p=300;

   }
   j=0;
   do{
      x=1;
      printf("%d\n",x++);
   }while (j++<2);
   puts(" ");
   j=0;
   switch (1)
   {
   case 1:
         do{
      x=1;
      printf("%d\n",x++);
      }while (j++<2);
      break;
   
   default:
      break;
   }
}


void test(int chek[],int i);
void test_1(int *chek,int i);
int main(){
   int chek[10]={1,2,3,4,5,6,7,8,9,10};
   int *chek_ptr=&chek[0];
   test(chek,7);
   test(chek_ptr,7);
   test_1(chek,5);
   test_1(chek_ptr,4);
   return 0;
}

void test(int chek[],int i){
   printf("%d\n",chek[i]);
}
void test_1(int *chek,int i){
   printf("1--%d\n",chek[i]);
   printf("2--%d\n",*(chek+i));
}
//Рабочая версия 7-15.c

   Раздатчик карт 
   (=◕ᆽ◕ฺ=)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13
#define COL 4
#define P_SIZE 3
void shuffle (int wDeck[][SIZE]);
int deal(const int *const hand_size,int wDeck[][SIZE], const char *wFace[],const char *wSuit[],int lst_card,int *player_hand,int m);
void printArray(const int wDeck[][2],const int *const hand_size);
void smallest(int leader_hand[][2],const int *const size, int wDeck[][SIZE], const char *wFace[],const char *wSuit[],int *lst_card);
int gambler();
int combo(const int *hand,int i,const int *hand_size);
void result(int i);
void print_hand(const int *hand,const int *const size, const char *wFace[],const char *wSuit[]);
void print_deck(const int *const wDeck);
int ask();
//INT MAIN()
int main (void){
   const char *suit[4]={"Hearts","Diamonds","Clubs","Spades"};
   const char *face[SIZE]={"Ace","Deuce","Three","Four","Five",
   "Six","Seven","Eight","Nine","Ten","Jack","Queen","Kings"};
   int deck[COL][SIZE]={0};
   int i,a=gambler();
   const int hand_size=5;
   int hand_dist=1;
   int lst_card=hand_dist+hand_size;
   int leader_hand[hand_size][2]={0};
   int first_hand[hand_size][2]={0};
   int seconde_hand[hand_size][2]={0};
   const char *player_name[P_SIZE]={"First player\n","Seconde player\n","Croupier\n"};
   int *player[P_SIZE]={&first_hand[0][0],&seconde_hand[0][0],&leader_hand[0][0]};
   int *cards[2]={&lst_card,&hand_dist};
   int answer;
   srand(time(NULL));
   shuffle(deck);
   //print_deck(&deck[0][0]);
   int j=1;
   int trash;
   for (i = 0; i <= a; i++){
      if(i!=a){
      printf("\n%5s",player_name[i]);
      lst_card=deal(&hand_size,deck,face,suit,*cards[0],player[i],i);
      print_hand(player[i],&hand_size,face,suit);
      result(combo(player[i],0,&hand_size));
      if((answer=ask())==-1){
         break;
      }else{
         lst_card=deal(&j,deck,face,suit,*cards[0],player[i]+answer*2,i);
         print_hand(player[i],&hand_size,face,suit);
         scanf("%d",&trash);
      }
      }else{
      printf("\n%5s",player_name[P_SIZE-1]);
      deal(&hand_size,deck,face,suit,*cards[1],player[P_SIZE-1],P_SIZE-1);
      print_hand(player[P_SIZE-1],&hand_size,face,suit);
      result(combo(player[P_SIZE-1],0,&hand_size));
      smallest(leader_hand,&hand_size,deck,face,suit,&lst_card);
      puts(" ");
      print_hand(player[P_SIZE-1],&hand_size,face,suit);
      result(combo(player[P_SIZE-1],0,&hand_size));
      hand_dist+=lst_card;
      }
   }

   puts("\n(= ◕ ᆽ  ◕ =)");
   return 0;
}
void shuffle(int wDeck[][SIZE]){
   int row;
   int column;
   int card;
   for(card=1;card<=COL*SIZE;card++){
      do{
         row=rand()%COL;
         column=rand()%SIZE;
      }while(wDeck[row][column]!=0);
      wDeck[row][column] =card;
   }
}
int gambler(){
   int i;
   printf("How many people will play (enter the number 1 to 2):");
   scanf("%d",&i);
   if(i<=0||i>2){
      return 0;
   }
   return i;
}
int deal(const int *const hand_size,int wDeck[][SIZE], const char *wFace[],const char *wSuit[],int lst_card,int *player_hand,int m){
   void hand_m(int *element_1,int *element_2,int count,int *player_hand);
   void deal_manip(const int *const hand_size, int * wDeck,const int *const lst_card,int *const unusbl);
   int manip_chk(int *column,int *player_hand,const int *const size);
   int card=1;
   int row,column;
   int manip=0;
   //int hand[5][2]={{1,8},{1,8},{1,8},{1,8},{1,8}};
   while(card <= *hand_size){
      for (row = 0; row <=3; row++){
         for (column = 0; column <= 12; column++){
            if(card>*hand_size){
               //printArray(hand,hand_size);
               return lst_card;
            }
            if(wDeck[row][column]==lst_card){
               if(m==P_SIZE-1&&manip<=2&&manip_chk(&column,player_hand,hand_size)){
                  deal_manip(hand_size,&wDeck[0][0],&lst_card,&wDeck[row][column]);
                  manip++;
                  break;
               }
               hand_m(&row,&column,card-1,player_hand);
               lst_card++;
               card++;
            }
         }
      }  
   }
   return lst_card;
}
int manip_chk(int *column,int *player_hand,const int *const size){
   
      Дописть так что бы при 4-х картах одной масти выводила тру
      и программа выдавала карту для получения флюша
   
   for (int i = 0; i < *size; i++)
   {
      if(*column<*(player_hand+i*2+1)){
         return 1;
      }
   }
   return 0;
}
void deal_manip(const int *const hand_size, int * wDeck,const int *const lst_card,int *const unusbl){
   int j,r;
   do{
      j=1+rand()%(COL*SIZE);
   }while (j==*lst_card);
   for (int i = 0; i < COL*SIZE; i++)
   {
      if(*(wDeck+i)==j){
         r=*(wDeck+i);
         *(wDeck+i)=*unusbl;
         *unusbl=r;
      }
   }
   //print_deck(wDeck);
}
void hand_m(int *element_1,int *element_2,int count,int *player_hand){
   *(player_hand+count*2)=*element_1;
   *(player_hand+(count*2+1))=*element_2;
   
   //player_hand[count][1]=*element_2;
}
void smallest(int leader_hand[][2],const int *const size, int wDeck[][SIZE], const char *wFace[],const char *wSuit[],int *lst_card){
   int * fnd( int *hand,int i,const int *const size);
   int i,a=1,j=0;
   int * card;
   printArray(leader_hand,size);
   puts(" ");
   for ( i = 0; i <3; i++)
   {
      if(&leader_hand[i][1]!=0){
      card=fnd(&leader_hand[0][1],0,size);
      if(card==0){
         puts("Fail!");
         break;
      }
      *lst_card=deal(&a,wDeck,wFace,wSuit,*lst_card,card,0);
      }
   }
   puts(" ");
   for (i = 0; i < *size; i++)
   {
      printf("%5s of %-8s",wFace[leader_hand[i][1]],wSuit[leader_hand[i][0]]);
      puts(" ");
   }
   printArray(leader_hand,size);
   //printf("lst_card is %d",*lst_card);
}
int * fnd( int *hand,int i,const int *const size){
   //printf("i is %d\n",i);
   int * small;
   small=hand;
   for (int a = 1; a < *size-i; a++)
   {
      //printf("a is %d\n",a);
      if(*small>*(hand+a*2)){
         small=hand+a*2;
      }
   }
   return small-1;
}
int combo(const int *hand,int i,const int *hand_size){
   int flush_chk(const int *const hand,const int *const hand_size);
   int j=1;
   int count =0,b=0;
   while(j<=(*hand_size-(1))){
      if(*(hand+1) == *(hand+j*2+1)){
         b=j;
         count++;
      }
      j++;
   }
   i++;
   if(i==*hand_size-1){
      return count;
   }
   if(count ==0&& i<*hand_size-1){
      count=combo(hand+2,i,hand_size);
   }
   if(count != *hand_size-1){
      if(flush_chk(hand,hand_size)==5){
         return 5;
      }
   }
   if(count==1&&i<*hand_size-1){
      
      count+=combo(hand+b*2+2,i,hand_size);
   }
   return count;
   
}
int flush_chk(const int *const hand,const int * hand_size){
   int j=0,count=1;
   while(j<*hand_size-1){
      if(*(hand+j*2)== *(hand+(j+1)*2)){
         count++;
      }
      j++;
   }
   if(count ==*hand_size){
      return count;
   }else{
      return 0;
   }
}
void result(int i){
   switch (i)
               {
               case 1:
                  puts("Pair !");
                  break;
               case 2:
                  puts("Two Pairs !");
                  break;
               case 3:
                  puts("Three of a Kind !");
                  break;
               case 4:
                  puts("Four of a Kind !");
                  break;
               case 5:
                  puts("Flush !");
                  break;
               default:
                  break;
               }
}
int ask(){
   int i;
   puts("Do you want change card??");
   printf("Enter the number 1 to 5 : ");
   scanf("%d",&i);
   if(i<=5&&i>=0){
      return i-1;
   }
   return -1;
}
void printArray(const int wDeck[][2],const int *const hand_size){
   for (int i = 0; i < *hand_size; i++)
   {
      for (int a = 0; a < 2; a++)
      {
         printf("%3d",wDeck[i][a]);
         
      }
      puts(" ");
   }
}
void print_hand(const int *hand,const int *const size, const char *wFace[],const char *wSuit[]){
   for (int i = 0; i < *size; i++)
   {
      printf("%5s of %-8s",wFace[*(hand+i*2+1)],wSuit[*(hand+(i*2))]);
      puts(" ");
   }
   puts(" ");
}
void print_deck(const int *const wDeck){
   for (int i = 0; i < COL*SIZE; i++)
   {
      printf("%4d",*(wDeck+i));
      if(i%13==0&& i!=0){
         puts(" ");
      }
   }
   puts(" ");
}
*/
//Конец рабочий версии 7-15.c
/*
#include <stdio.h>
#include <stdlib.h>

int combo(const int *hand,int i,const int *const hand_size);
void printArray(const int wDeck[][2],const int *const hand_size);
int * a(int *b){
   int i;
   if(*b==6){
      return b;
   }
   for ( i = 1; i < 5; i++)
   {
      if(*b<*(b+i*2)){
         //printf("*b is %d < *(b+%d*2) is  %d\n",*b,i,*(b+i*2));      
         return a(b+i*2);
      }
   }
   return 0;
}
int main(){
   int b[5][2]={{1,2},{3,4},5,6,7,8,9,10};
   int * c = a(&b[0][1]);
   printf("%d\n",*(a(&b[0][1])));
   puts("======");
   printf("%d\n",*c);
   puts(" ");
   return 0;
}

int main(){
   const int hand_size=5;
   //int leader_hand[hand_size][2]={{1,2},{3,2},{1,3},{3,3},{1,0}};
   int leader_hand[hand_size][2]={{1,3},{1,3},{1,2},{1,2},{0,0}};
   int first_hand[hand_size][2]={0};
   int seconde_hand[hand_size][2]={0};
   const char *player_name[3]={"First player\n","Seconde player\n","Croupier\n"};
   int *player[3]={&first_hand[0][0],&seconde_hand[0][0],&leader_hand[0][0]};
   printArray(leader_hand,&hand_size);
   //printf("combo is %d\n",combo(player[2],0,&hand_size));
      switch (combo(player[2],0,&hand_size)){
               case 1:
                  puts("Pair !");
                  break;
               case 2:
                  puts("Two Pairs !");
                  break;
               case 3:
                  puts("Three of a Kind !");
                  break;
               case 4:
                  puts("Four of a Kind !");
                  break;
               case 5:
                  puts("Flush !");
                  break;
               default:
                  break;
   }
   puts("(=◕ᆽ◕ฺ=)");
   return 0;
}
int combo(const int *hand,int i,const int *hand_size){
   int flush_chk(const int *const hand,const int *const hand_size);
   int j=1;
   int count =0,b=0;
   printf("*(hand+1) is %d\n",*(hand+1));
   //printf("Flush is %d\n",flush);
   while(j<=(*hand_size-(1))){
      printf("j is %d\n",j);
      if(*(hand+1) == *(hand+j*2+1)){
         b=j;
         count++;
         printf("Count is %d\n",count);
      }
      j++;
      //printf("*(hand+j*2) is %d\n",*(hand+j*2));
      //printf("*(hand+j*2+1)is %d\n",*(hand+j*2+1));
   }
   i++;
   //printf("count is %d \n",count);
   if(i==*hand_size-1){
      return count;
   }
   if(count ==0&& i<*hand_size-1){
      //printf("first Count is %d\n",count);
      count=combo(hand+2,i,hand_size);
   }
   if(count != *hand_size-1){
      if(flush_chk(hand,hand_size)==5){
         //printf("flush Count is %d\n",count);
         return 5;
      }
   }
   if(count==1&&i<*hand_size-1){
      //printf("seconde Count is %d\n",count);
      count+=combo(hand+b*2+2,i,hand_size);
   }
   //printf("end Count is %d\n",count);
   return count;
   
}
int flush_chk(const int *const hand,const int * hand_size){
   int j=1,count=1;
   while(j<=*hand_size-1){
      if(*hand == *(hand+j*2)){
         count++;
      }
      j++;
   }
   printf("1 flush is %d\n",count);
   if(count == *hand_size){
      return count;
   }else{
      return 0;
   }
}

void printArray(const int wDeck[][2],const int *const hand_size){
   for (int i = 0; i < *hand_size; i++)
   {
      for (int a = 0; a < 2; a++)
      {
         printf("%3d",wDeck[i][a]);
         
      }
      puts(" ");
   }
}


      switch (flush)
      {
      case 5:
         puts("Flush !");
         break;
      default:
         break;
      }

   switch (count){
               case 1:
                  puts("Pair !");
                  break;
               case 2:
                  puts("Two Pairs !");
                  break;
               case 3:
                  puts("Three of a Kind !");
                  break;
               case 4:
                  puts("Four of a Kind !");
                  break;

               default:
                  break;
   }



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void chek(int player);
void seconde_chek(int *p);
int main(){
   int leader_hand[5][2]={1,5};
   int first_hand[5][2]={2,6,7,5,3,9,8,1,10,11};
   int seconde_hand[5][2]={3,7};
   int *player[3]={&first_hand[0][0],&seconde_hand[0][0],&leader_hand[0][0]};
   for(int i=0;i<10;i++){
      printf("%d",*(player[0]+i));
      puts(" ");
   }
   puts(" ");
   for (int i = 0; i < 3; i++)
   {
      chek(*player[i]);
      
      seconde_chek(player[i]);
      puts(" ");
   }
   puts("\n(= ◕ ᆽ  ◕ =)");
   return 0;
}

void chek(int player){
   printf("%d\n",player);
}
void seconde_chek(int *p){
   for (int i = 0; i < 2; i++)
   {
      printf("%d\n",*(p+i));
   }
}

void init(int *t_ptr);
void printArray(const int n[][2],int size,int size_1);

int main(){
   int t[5][2]={0,1,2,3,4,5,6,6,7,8};
   srand(time(NULL));
   int *t_ptr=&t[0][0];
   printArray(t,5,2);
   puts(" ");
   init(&t[0][0]);
   printf("*(t_ptr+6)==%d",*(t_ptr+6));
   puts(" ");
   printf("*(t_ptr+3*2)==%d",*(t_ptr+3*2));
   printArray(t,5,2);
   puts("( = ◕ ᆽ ◕ฺ =)");
   return 0;
}

void init(int *t_ptr){
   *(t_ptr+3*2)=113-70;
}
void printArray(const int n[][2],int size,int size_1){
      for(int i=0;i<size;i++){
         for (int j = 0; j < size_1; j++)
         {
         printf("t[%d][%d]==%d",i,j,n[i][j]);
         puts(" ");      
         }
      }
}
//void test_1()

   (=◕ᆽ◕ฺ=)
*/