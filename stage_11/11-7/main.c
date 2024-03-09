#include "main.h"

#define OLD "oldmast.dat"
#define TRN "transactions.dat"

int main() {
    init_file(OLD);
    print_file(OLD, 1);
    mod_trans(TRN);
    print_file(TRN, 2);
    update_file(OLD, TRN);
    print_file(OLD, 1);
    putchar('\n');
    return 0;
}
