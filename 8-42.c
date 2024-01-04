#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 1000
#define S 15


void p(int *a);
int vec(int *x, int *y, int t[][S],char **s);
int main(){
    char *hor[SIZE]={"MACHINE","COMMITTEE"};//,"INCOME","MOTORING"};
    char que[SIZE]={""};

    int table[S][S]={
    {0},{0},{0},
    {0},{0},{0},
    {0},{0},{0},
    {0}
    };
    int num[SIZE]={0};
    int x=1,y=0;
    vec(&x,&y,table,hor);
    //p(&table[0][0]);
    return 0;
}

void p( int *a){
    for (size_t i = 0; i<(S*S); i++){
        if (i!=0&&(i%S==0))
            puts(" ");
        if(isalpha(*(a+i)))
            printf("%3c",*(a+i));
        else 
            printf("%3d",*(a+i));
        //printf("%3d",*(a+i));    
    }
    puts(" ");
}

int vec(int *x, int *y, int t[][S], char **s){
    void pr(int x, int y, char *s,int t[][S],int *v);
    int con(char *s_o,char *s_n,int *x,int *y);
    void take(int *x,int *y,int *n,int *v,char **s,size_t *i);
    int v=0,n=0,n_x=0,n_y=0;
    for (size_t i = 0; *(s+i); i++){
        v=i%2;
        if (i &&con(*(s+(i-1)),*(s+i),&n_x,&n_y)){
           printf("x is %d || y is %d \nn_x is %d || n_y is %d\n",*x,*y,n_x,n_y);
        }
        if(v){
            t[*x++][*y]=i+1;
        }else{
            t[*x][*y++]=i+1;
        }
        printf("x is %d y is %d\n",*x,*y);
        pr(*x,*y,*(s+i),t,&v);
        p(&t[0][0]);
    }
}

void pr(int x, int y, char *s,int t[][S],int *v){
    for(char *c=(char *)s;*c;c++){
        switch (*v){
        case 0:
            t[x][y++]=(int)*c;
            break;
        case 1:
            t[x++][y]=(int)*c;
        default:
            break;
        }
    }
}

int con(char *s_o,char *s_n,int *x,int *y){
    int i=0,j=0;
    for(char *c=s_n;*c;c++){
        for (i=0; *(s_o+i); i++){
            if(*c==*(s_o+i))
                break;
        }
    }
    for (; *(s_n+j); j++){
        if(*(s_n+j)==*(s_o+i))
            break;
    }
    if(i&&j){
        *x=i;
        *y=j;
        return 1;
    }
    return 0;
}

void take(int *x,int *y,int *n,int *v,char **s,size_t *i){
    
}



