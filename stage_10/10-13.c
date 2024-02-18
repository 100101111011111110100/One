#include <stdio.h>


int init(char **c,int size);
unsigned packCharacters(char **c,int size);
void unpackCharacters(unsigned a,char **c,int size);
int main (){
    char c_1,c_2,c_3,c_4,n_1,n_2,n_3,n_4;
    int size=4;
    unsigned a;
    char *c[]={&c_1,&c_2,&c_3,&c_4};
    char *n[]={&n_1,&n_2,&n_3,&n_4};
    if(init(c,size)){
        a=packCharacters(c,size);
        unpackCharacters(a,n,size);
        puts("RESULT : ");
        for (int i = 0; i < 4; i++){
            printf("%4c",**(n+i));
        }
        
        //printf("Result : %c || %c",n_1,n_2);
    }
        
    //printf("%c %c \n",c_1,c_2);
    return 0;
}

int init(char **c,int size){
    void clear();
    for (size_t i = 1; i <= size; i++){
        printf("Please enter the simbol N%d :",i);
        scanf("%c",*(c+(i-1)));
        clear();
    }
    return 1;
}

void clear(){
    int c;
    while((c=getchar())!=EOF&&c!='\n')
        ;
}

unsigned packCharacters(char **c,int size){
    void bit(int value);
    unsigned a=**c;
    for (size_t i = 1; i < size; i++){
        //bit(*c[i]);
        a<<=8;
        a|=*c[i];
    }
    bit(a);
    return a;
}

void unpackCharacters(unsigned a,char **c,int size){
    void bit(int value);
    unsigned mask=255;
    //bit(mask);
    for (int i = size-1; i >=0; i--){
        **(c+i)=(a&mask);
        //**(c+i)=mask&a;
        //bit(a&mask);
        a>>=8;
        //mask<<=8;
        //bit(a);
        //bit(mask);
        
    }
    /*mask_1=65280
    *c_1=(a&mask_1)>>8;
    //bit((a&mask_1)>>8);
    bit(*c_1);
    //a>>=8;
    //bit(a);
    *c_2=a&mask_2;
    bit(*c_2);
    */
}
void bit(int value){
    unsigned i;
    unsigned mask=1<<31;
    printf("Value :%-10d == ",value);
    for (i = 1; i <= 32; i++){
        putchar(value&mask ? '1':'0');
        value<<=1;
        if(i%8==0)
            putchar(' ');
    }
    putchar('\n');
}

