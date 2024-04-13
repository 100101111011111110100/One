#include <stdio.h>

void prt(int i, int size);

int main() {
    int i = 254;
    // printf("SIZEOF : %d\n",sizeof(int));
    int size = 32;
    prt(i, size);
    i >>= 4;
    prt(i, size);
    return 0;
}
void prt(int i, int size) {
    unsigned mask = 1 << size - 1;
    printf("Value : %-d == ", i);
    for (unsigned j = 1; j <= size; j++) {
        putchar(i & mask ? '1' : '0');
        i <<= 1;
        if (j % 8 == 0) putchar(' ');
    }
    putchar('\n');
}
