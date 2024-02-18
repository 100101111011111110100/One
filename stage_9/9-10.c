#include <stdio.h>

int main(){
    double a=100.453627;
    printf("%.*f\n",0,a);
    printf("%.*f\n",1,a);
    printf("%.*f\n",2,a);
    printf("%.*f\n",3,a);
    printf("%.*f\n",4,a);
    puts(" ");
    return 0;
}