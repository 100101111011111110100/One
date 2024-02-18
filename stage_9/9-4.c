#include <stdio.h>

int main(){
    int hex;
    char s[10]="";
    //a
    printf("%-15.8d\n",40000);
    /*b
    scanf("%x",&hex);
    printf("Hex is %X (%d)\n",hex,hex);
    */
    //c
    printf("%+d ||% d\n",-200,200);
    //d
    printf("%#x\n",100);
    /*e
    printf("Enter the string : ");
    scanf("%[^p]",s);
    puts(s);
    */
    //f
    printf("%.9f\n",1.234);
    /*g
    {
        int h,s,m;
        printf("%s\n","Enter the date format (hh:mm:ss):");
        scanf("%d%*c%d%*c%d%*c",&h,&m,&s);
        printf("Time is %d-%d-%d\n",h,m,s);
    }*/
    /*h
    {
        char s[1000]="";
        scanf("%*c%[^\"]",s);
        puts(s);
    }*/
    //i
    {
        int h,s,m,c;
        //char c[10]="";
        printf("%s\n","Enter the date format (hh:mm:ss):");
        printf("%d %d\n",h,m);
        scanf("%d:%d:%d",&h,&m,&s);// Более удобный способ
        //scanf("%d%[:]%d%[:]%d",&h,&c,&m,&c,&s);
        printf("%d %d %d\n",h,m,s);
        //scanf("%d[^:]%d[^:]%d[^:]",&h,&m,&s);
        //printf("Time is %d-%d-%d\n",h,m,s);
    }
    puts(" ");
    return 0;
}