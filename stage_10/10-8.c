#include <stdio.h>

union integer{
    char c;
    short s;
    int i;
    long b;
}test;

union floatingPoint{
    float f;
    double d;
    long double x;
}tst;

int main (){
    test.c='C';
    printf("Char c: %c | %hd | %d | %d | %ld\n",test.c,test.c,test.c,test.c,test.c);
    test.s=12345;
    printf("Short s: %c | %hd | %d | %d | %ld\n",test.s,test.s,test.s,test.s,test.s);
    test.i=354;
    printf("Int i: %c | %hd | %d | %d | %ld\n",test.i,test.i,test.i,test.i,test.i);
    test.b=4567890;
    printf("Long b: %c | %hd | %d | %d | %ld\n",test.b,test.b,test.b,test.b,test.b);
    puts("FLOAT");
    tst.f=123.456780;
    printf("Float f: %f | %f | %lf | %E | %G\n",tst.f,tst.f,tst.f,tst.f,tst.f);
    tst.d=123.546644213;
    printf("Double d: %f | %f | %lf | %E | %G\n",tst.d,tst.d,tst.d,tst.d,tst.d);
    tst.x=123.1212312312314512;
    printf("Long double x: %f | %f | %lf | %E | %G\n",tst.x,tst.x,tst.x,tst.x,tst.x);
    return 0;
}

