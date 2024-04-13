#include <stdio.h>

int main (){
    int a;
    printf("\'\n");
    printf("\"\n");
    printf("\?\n");
    printf("\\\n");
    printf("\a\n");
    printf("1Hello\bWorld\n");
    printf("3Hello\rworld\n");
    printf("4Hello \tworld\n");
    printf("5Hello \v world\n");



    puts("=================");
    printf("?\n");
    puts("=================");



    puts("=================");
    for (size_t i = 0; i < 5; i++){
        switch (i){
        case 0:
            scanf("%d",&a);
            break;
        case 1:
            scanf("%i",&a);
            break;
        case 2:
            scanf("%o",&a);
            break;
        case 3:
            scanf("%u",&a);
            break;
        case 4:
            scanf("%x",&a);
            break;
        default:
            break;
        }
        printf("%d || %i || %o || %u || %x \n",a,a,a,a,a);
    }
    
    puts("=================");




    puts(" ");
    return 0;
}