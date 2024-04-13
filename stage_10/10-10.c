#include <stdio.h>

long int pw(const int const *i, const int const *size);
void clear();
void bit(int value, const int const *x, const int const *size);
int main() {
    int i, size, j;
    int *int_ptr[] = {&i, &size};
    char *s[] = {"Enter the number : ", "Enter the pow : "};
    for (size_t j = 0; j < 2; j++) {
        printf("%s", s[j]);
        scanf("%d", int_ptr[j]);
        clear();
    }
    j = pw(*int_ptr, *(int_ptr + 1));
    bit(j, &i, &size);
    return 0;
}

long int pw(const int const *i, const int const *size) { return *i << *size; }
void clear() {
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        ;
}

void bit(int value, const int const *x, const int const *size) {
    unsigned i;
    unsigned mask = 1 << 31;
    printf("%d*2^(%d)==%d\n%d == ", *x, *size, value, value);
    for (i = 1; i <= 32; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}
