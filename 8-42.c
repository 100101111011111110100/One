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
    int j=0;
    printf("%4c",' ');
    for (size_t i = 0; i<S; i++)
        printf("%4d",i);
    printf("\n");
    for (size_t i = 0; i<(S*S); i++){
        if (i%S==0)
            printf("%4d",j++);
        if(isalpha(*(a+i)))
            printf("%4c",*(a+i));
        else{
            printf("%4d",*(a+i));
        }
        if (i!=0&&(i%S==14))
            puts(" ");
    }
    puts(" ");
}

int vec(int *x, int *y, int t[][S], char **s){
    void pr(int x, int y, char *s,int t[][S],int *v);
    int con(char *s_o,char *s_n,int *x,int *y);
    int take(int *x,int *y,int *n_x,int *n_y);
    int v=0,n=0,n_x=0,n_y=0;
    for (size_t i = 0; *(s+i); i++){
        v=i%2;
        if (i &&con(*(s+(i-1)),*(s+i),&n_x,&n_y)){
           //printf("x is %d || y is %d \nn_x is %d || n_y is %d\n",*x,*y,n_x,n_y);
            --n_y;
            if(v){
                take(x,y,&n_y,&n_x);
            }else {
                take(x,y,&n_x,&n_y); 
            }
        }
        if(v){
            t[(*x)++][*y]=i+1;
            printf("v||x is %d y is %d\n",*x,*y);           
            p(&t[0][0]);    
        }else{
            t[*x][(*y)++]=i+1;
            printf("not v||x is %d y is %d\n",*x,*y);
        }
        pr(*x,*y,*(s+i),t,&v);
        p(&t[0][0]);
        puts(" ");
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
    int i,j=0,c=0;
    for(char *c=s_n;*c;c++){
        for (i=0; *(s_o+i); i++){
            //printf("%d , %c\n",i,*(s_o+i));
            if(*c==*(s_o+i)){
                c++;
                break;
            }
        }
        if(c)
            break;
    }
    for (; *(s_n+j); j++){
        if(*(s_n+j)==*(s_o+i))
            break;
    }
    if(i>=0&&j>=0){
        //printf("%d , %d\n",i,j);
        *x=i;
        *y=j;
        return 1;
    }
    return 0;
}

int take(int *x,int *y,int *n_x,int *n_y){
    int new_x=0,new_y=0;
    printf("take : x is %d y is %d\n new_x is %d new_y is %d",*x,*y,*n_x,*n_y);
    new_x=*x+*n_x;
    new_y=*y+*n_y;
    printf("take :x is %d y is %d\n",new_x,new_y);
    if (new_x>=0&&new_y>=0){
        *x=new_x;
        *y=new_y;
        return 1;
    }
    return 0;
}
