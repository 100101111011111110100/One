#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 1000
#define S 15

int table[S][S]={
    {0},{0},{0},
    {0},{0},{0},
    {0},{0},{0},
    {0}
    };
int num[SIZE]={0};

char *hor[SIZE]={"ABNEY","GRUFF"};
char *ver[SIZE]={"DINGO","FLUSH"};
char **wor[]={hor,ver};
char que[SIZE]={""};

void p(int size);
int g_field();

int main(){
    g_field();
    puts(" ");
    return 0;
}

int g_field(){
    int ent(char * s, int * x,int *y,int v,int n);
    int n_ent(char *s,char *n_s,int *x,int *y);
    int n=0,j=0,x=S/2,y=0;
    for (size_t i=0; i<4/**(wor[i%2]+n%2)*/; i++){
        printf("i is %d |{x=%d,y=%d}| n is %d|| string : %s\n",i%2,x,y,n%2,*(wor[i%2]+n%2));
        num[n]++;
        ent(*(wor[i%2]+n%2),&x,&y,i%2,n+1);
        p(S);
        if (i%2==1){
            n++;
        }
        printf("`%d`\n",(i+1)%2);
        switch ((i+1)%2){
        case 0:
            n_ent(*(wor[i%2]+((n-1)%2)),*(wor[(i+1)%2]+n%2),&y,&x);
            break;
        case 1:
            n_ent(*(wor[i%2]+n%2),*(wor[(i+1)%2]+n%2),&x,&y);
            break;
        default:
            break;
        }
    }
    return 0;
}
int n_ent(char *s,char *n_s,int *x,int *y){
    int n_x=0,n_y=0,j=0;
    char * s_ptr=strpbrk(s,n_s);
    puts(n_s);
    if(s_ptr){
        puts(s_ptr);
        for (size_t i = 0; *(s+i); i++){
            if(*(s+i)==*(s_ptr+0)){
                {
                    for (; *(n_s+j); j++){
                        if (*(n_s+j)==*(s_ptr+0))
                            break;
                                               
                    }
                    
                }
                n_x=*x-(i+1);
                printf("strlen is %d|i is %d\n",strlen(s),i);
                n_y=*y-(j);
                printf("n_ent:{x==%d | n_x==%d},{y==%d|n_y==%d}\n",*y,n_y,*x,n_x);
                if (n_x>=0&&n_y>=0){
                    *x=n_x;
                    *y=n_y;
                    return 1;
                }
            }
        }
        
    }
    return 0;
}
int ent(char * s, int * x,int *y,int v, int n){
    int to_ch(int *n);
    int x_1=*x,y_1=*y;
    char n_n=to_ch(&n);
    //printf("V %d",v);
    for (char *c=s; *c; c++){
        switch (v){
        case 0:
            if (y_1==*y){            
                table[x_1][y_1++]=n_n;
                printf("%d\n",table[x_1][y_1-1]);
            }table[x_1][y_1++]=*c;
            //printf("%c\n",table[x_1-1][y_1]);
            break;
        case 1:
            if (x_1==*x)            
                table[x_1++][y_1]=n_n;
            table[x_1++][y_1]=*c;
            //printf("%c\n",table[x_1][y_1-1]);
            break;
        default:
            break;
        }
    }
    *y=y_1;
    *x=x_1;
    return 1;
}
int to_ch(int *n){
    int num[]={'0','1','2','3','4','5','6','7','8','9'};
    return num[*n];
}
void p(int size){
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){            
            printf("%c",table[i][j]);
            if(j%9==0 && j!=0)
            puts(" ");
        }
    }
}
