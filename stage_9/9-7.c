#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main (){
    int j,x,x_n=0;
    srand(time(NULL));
    printf("%-10s%10s\n","Value","Total characters");
    for (size_t i = 0; i < 10; i++){
        j=rand()%1000+1;
        printf("%-d%n",j,&x);
        printf("%*c",11-(x+1),' ');
        x_n+=x;
        printf("%-d\n",x_n);
    }
    puts(" ");
    return 0;
}