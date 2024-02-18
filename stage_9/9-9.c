#include <stdio.h>

int main(){
    int a=12345;
    float b=1.2345;
    {
        for (int i = 1; i < 11; i++){
            printf("%10c %-d\n",'N',i);
            printf("%*d || %*.*f\n",i,a,i,i,b);
            puts("=================");
        }
    }
    puts(" ");
    return 0;
}