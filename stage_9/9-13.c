#include <stdio.h>

float f(int c);
int main (){
    int y,x;
    printf("%10s%5c%10s\n","Fahrenheit",' ',"Celcius");
    for (int i = 0; i <=212; i++){
        //printf("%-d%*c%-.3f\n",i,' ',f(i));
        printf("%10d%5c%10.3f\n",i,' ',f(i));
        //printf("%10.3f\n",f(i));
    }
    puts(" ");
    return 0;
}

float f(int c){
    return 5.0/9.0*(c-32);
}