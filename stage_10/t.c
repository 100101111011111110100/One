#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct inventory {
    char partName[30];
    int partNumber;
    double price;
    int stock, reorder;
};

union data {
    char c;
    short s;
    long l;
    float f;
    double d;
};

struct address {
    char streetAddress[25];
    char city[20];
    char state[3];
    char zipCode[6];
};

struct student {
    char firstName[15];
    char lastName[15];
    struct address homeAddress;
};

struct test {
    unsigned a : 1;
    unsigned b : 1;
    unsigned c : 1;
    unsigned d : 1;
    unsigned e : 1;
    unsigned f : 1;
    unsigned g : 1;
    unsigned h : 1;
    unsigned i : 1;
    unsigned j : 1;
    unsigned k : 1;
    unsigned l : 1;
    unsigned m : 1;
    unsigned n : 1;
    unsigned o : 1;
    unsigned p : 1;
};
typedef struct first {
    int x;
    int y;
    char *string;
} sam1, sam2;

/*enum number{
    int x;
    float y;
};*/
char *string[] = {"Hello world", "Hell", "Back", "In", "The", "world"};
int init();
int main() {
    srand(time(NULL));
    init();
    puts("Hello world");
    return 0;
}

int init() {
    struct first sam[8];
    for (size_t i = 0; i < 8; i++) {
        sam[i].x = rand() % 6;
        sam[i].string = string[sam[i].x];
    }
    for (size_t i = 8; i > -1; i--) {
        printf("%-10d%s\n", sam[i].x, sam[i].string);
    }
    return 1;
}