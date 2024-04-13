#include <stdio.h>

int main(){
    int y=0;
    char s[1000]="";
    printf("y is %d\n",y);
    if(scanf("%s%n",s,&y))
        printf("%*s\n",y*2,s);
    puts(" ");
    return 0;
}