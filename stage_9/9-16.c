#include <stdio.h>

int main(){
    //printf("%s\n%s\n","suzy",'suzy');
    int a='?';
    printf("!%c!\n",a);
    for (int i = 1; i < 10; i++){
        printf("%.*g\n",i,9876.12345);
    }
    
    puts(" ");
    return 0;
}