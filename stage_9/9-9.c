#include<stdio.h>
/**/
int main(){
    int x=0;
    int *x_ptr=&x;
    printf("P %p\n",x_ptr);
    puts("===========");
    printf("D :%d\nI :%d\nO :%o\nX : %x\n",x_ptr,x_ptr,x_ptr,x_ptr);
    printf("E :%e\nF :%f\nG :%g\n",x_ptr,x_ptr,x_ptr);
    printf("C :%c\nS :%s\n",x_ptr,x_ptr);
    
    puts(" ");
    return 0;
}