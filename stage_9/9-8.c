#include<stdio.h>

int main(){
    int i,d;
    
    for (size_t j = 0; j < 5; j++){
        printf("Number: ");
        scanf("%i %d",&i,&d);
        printf("%d %d\n",i,d);
        puts("================");
    }
    puts(" ");
    return 0;
}