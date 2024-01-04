#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 1000
#define S 15


void p(int *a);
int vec(int *x, int *y, int t[][S],char **s);
int main(){
    char *hor[SIZE]={"MACHINE","COMMITTEE","INCOME","MOTORING"};
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
    int con(char *s_o,char *s_n);
    void take(int *x,int *y,int *n,int *v,char **s,size_t *i);
    int v=0,n=0;
    for (size_t i = 0; *(s+i); i++){
        v=i%2;
        if (i &&(n=con(*(s+(i-1)),*(s+i)))>=0){
           if(v){
            take(x,y,&n,&v,s,&i);
            printf("x is %d y is %d\n",*x,*y);
            }else{
            take(y,x,&n,&v,s,&i);
           printf("x is %d y is %d\n",*x,*y);
           }
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

int con(char *s_o,char *s_n){
    int i=0;
    for(char *c=s_n;*c;c++){
        for (; *(s_o+i); i++){
            if(*c==*(s_o+i))
                return i;
        }
    }
    return -1;
}

void take(int *x,int *y,int *n,int *v,char **s,size_t *i){
    int con(char *s_o,char *s_n);
    printf("take : x is %d y is %d || n is %d new n is %d\n",*x,*y,*n,con(*(s+*i),*(s+(*i-1)))+1);
    *x=*x+*n;
    *y=*y-(con(*(s+(*i-1)),*(s+*i))+1);
    printf("take : x is %d y is %d || n is %d new n is %d\n",*x,*y,*n,con(*(s+*i),*(s+(*i-1)))+1);
}


