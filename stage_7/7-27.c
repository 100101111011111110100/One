/*
Чем больше значение размера
Тем дольше будет обрабатываться лабиринт
Из-за элемента рандома в теле функции с_way
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_X 100
#define SIZE_Y 100
void printArray(int *deck,const int size_x,const int size_y,int a);
int creator(int doors[][2],int maze[][SIZE_Y],const int size_x,const int size_y);
int way(int maze[][SIZE_Y],int x,int y, int const * out);
void test_print();
int main(){
	srand(time(NULL));
	int maze[SIZE_X][SIZE_Y]={0};
	int doors[2][2]={0};
   //test_print();
	if(creator(doors,maze,SIZE_X,SIZE_Y)&&way(maze,doors[0][0],doors[0][1],&doors[1][0])){
		puts("WIN!!!\n==============\n");
		printArray(&maze[0][0],SIZE_X,SIZE_Y,2);
		printArray(&maze[0][0],SIZE_X,SIZE_Y,1);
	}
	puts("\n(= ◕ ᆽ  ◕ =)");
	return 0;
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
	int c_way(int maze[][SIZE_Y],int x,int y,int const * out);
	int filling(int maze[][SIZE_Y],int const * size_x,int const *size_y);
	int wall(int maze[][SIZE_Y],int const *size_x,int const * size_y);
	return in_out(doors,maze,&size_x,&size_y)&&wall(maze,&size_x,&size_y)&&c_way(maze,doors[0][0],doors[0][1],&doors[1][0])&&filling(maze,&size_x,&size_y);
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
	doors[i][0]=x;
	doors[i][1]=y;
	}
	return 1;
}
int wall(int maze[][SIZE_Y],int const *size_x,int const * size_y){
	for (unsigned long i = 0; i < *size_x; i++){
			if(i==0||i==*size_x-1){
				for (int a = 0; a < *size_y; a++){
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
		//printf("b is -- %d c is %d\nb_cells(maze,&b,&c,12) is %d\n",b,c,b_cells(maze,&b,&c));
		if(maze[b][c]==0&&b_cells(maze,&b,&c,1)){
			maze[x][y]='.';
			//printArray(&maze[0][0],12,2);
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
void test_print(){
   int a[50][43]={0};
   int *a_ptr;
   a_ptr=&a[0][0];
   for (int i = 0; i < 50*43; i++)
   {
      if(i%43==0&&i!=0)
         puts(" ");
      printf("%3d",*(a_ptr+i));
   }
}