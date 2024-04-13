#include <stdio.h>

int main (){
    float a=0;
    for (size_t i = 0; i < 3; i++){
        switch (0){
        case 0:
            scanf("%f",&a);
            break;
        case 1:
            scanf("%e",&a);
            break;
        case 2:
            scanf("%g",&a);
            break;
        default:
            break;
        }
        printf("%f || %e || %g\n",a,a,a);
    }
    
    puts(" ");
    return 0;
}