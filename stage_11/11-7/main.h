#ifndef MAIN_H
#define MAIN_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define N_SIZE 30

void clear();
size_t fnd_res(FILE* main, int j);
double fnd_debt(size_t res, int acc, FILE* main);
int empty_check(FILE* main);
// srand(time(NULL));
typedef struct customer {
    int acc;
    char full_name[N_SIZE];
    char addrecc[N_SIZE];
    int p_number;
    double debt;      //Задолжность
    double l_credit;  //Лимит кредита
} cstmr;
typedef struct trans {
    int acc;
    // char * full_name;
    double debt;
    char full_name[N_SIZE];
} trans;

void init_file(char* path) {
    FILE* main = fopen(path, "w+");
    if (main != NULL) {
        char* names[] = {"Thomas Jhonson", "Emily Smith",   "Alexander Brown",  "Sarah Davis",
                         "William Wilson", "Olivia Jones",  "Benjamine Taylor", "Sophia Clark",
                         "Ethan Martines", "Grace Anderson"};
        int phone[] = {5551234, 7779876, 8885555, 3334567, 222334,
                       1115467, 2227890, 9991234, 7541239, 12345678};
        int j = 0;
        for (int i = 0, acc = 1; i < SIZE; i++, acc++) {
            // struct customer node={(1+rand()%100),*names[i]," ",phone[i],(1+rand()%10000),(1+rand()%10000)};
            float d = 1 + rand() % 1000;
            if (acc == 5) acc++;
            struct customer node = {acc, " ", " ", phone[i], d, 10000.1};
            for (int i = 0; i < N_SIZE && j < 10; i++) {
                node.full_name[i] = names[j][i];
            }
            j++;
            fwrite(&node, sizeof(node), 1, main);
        }
        fclose(main);
    } else {
        printf("n/a");
    }
}

void print_file(char* path, int j) {
    FILE* main;
    main = fopen(path, "r");
    if (main != NULL && empty_check(main)) {
        switch (j) {
            case 1:
                struct customer node;
                fseek(main, 0, SEEK_END);
                size_t res = ftell(main);
                fseek(main, 0, SEEK_SET);
                res -= sizeof(node);
                size_t temp = 0;
                while (temp <= res) {
                    fread(&node, sizeof(node), 1, main);
                    printf("%20d %30s %20lf\n", node.acc, node.full_name, node.debt);
                    temp += sizeof(node);
                }
                break;
            case 2:
                struct trans no_de;
                // fseek(main,sizeof(no_de)+i,SEEK_SET);
                fseek(main, 0, SEEK_END);
                size_t f_size = ftell(main);
                fseek(main, 0, SEEK_SET);
                size_t st_size = sizeof(no_de);
                size_t tmp = 0;
                while (tmp <= (f_size - st_size)) {
                    fread(&no_de, sizeof(no_de), 1, main);
                    printf("%20d %30s %20lf\n", no_de.acc, no_de.full_name, no_de.debt);
                    tmp += st_size;
                }
                break;
            default:
                break;
        }
        fclose(main);
    } else if (main != NULL) {
        fclose(main);
    } else {
        printf("n/a");
    }
}
int empty_check(FILE* main) {
    int flag = 0;
    fseek(main, 0, SEEK_END);
    size_t res = ftell(main);
    struct customer one;
    struct trans sec;
    size_t chek_one = sizeof(one);
    size_t check_two = sizeof(sec);
    if (res - chek_one > 0 || res - check_two > 0) flag = 1;
    return flag;
}
size_t fnd_res(FILE* main, int j) {
    size_t res;
    switch (j) {
        case 0:
            struct customer elem;
            fseek(main, 0, SEEK_END);
            res = ftell(main);
            fseek(main, 0, SEEK_SET);
            res -= sizeof(elem);
            break;
        case 1:
            struct trans el_em;
            fseek(main, 0, SEEK_END);
            res = ftell(main);
            fseek(main, 0, SEEK_SET);
            res -= sizeof(el_em);
            break;
        default:
            break;
    }
    return res;
}
int mod_trans(char* path) {
    FILE* trans = fopen(path, "a+");
    int flag = 1;
    if (trans == NULL) {
        flag = 0;
    }
    while (flag) {
        struct trans node;
        printf("Enter acc, debt:");
        if (scanf("%d", &node.acc) != 1 || node.acc <= 0) {
            break;
        }
        scanf("%lf", &node.debt);
        clear();
        fwrite(&node, sizeof(node), 1, trans);
    }
    if (trans != NULL) fclose(trans);
    if (flag == 0) {
        printf("n/a");
    }
    return 0;
}

void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != '\0')
        ;
}

void update_file(char* first_path, char* seconde_path) {
    FILE* main = fopen(first_path, "r");
    FILE* tmp = fopen("tmp.dat", "w+");
    int flag = 1, old_acc = 0;
    ;
    size_t res, temp = 0;
    if (main == NULL || tmp == NULL) flag = 0;
    if (flag) {
        res = fnd_res(main, 0);
    }
    while (flag && temp <= res) {
        struct customer old_elem_data;
        FILE* trns = fopen(seconde_path, "r");
        fread(&old_elem_data, sizeof(old_elem_data), 1, main);
        if (trns == NULL) {
            // flag=0;
            break;
        }
        old_elem_data.debt += fnd_debt(fnd_res(trns, 1), old_elem_data.acc, trns);
        fclose(trns);
        // printf("%d %d == %d\n",old_acc,old_elem_data.acc,old_elem_data.acc-old_acc);
        if (old_acc == 0) {
            old_acc = old_elem_data.acc;
            fwrite(&old_elem_data, sizeof(old_elem_data), 1, tmp);
        } else if ((old_elem_data.acc - old_acc) > 1) {
            fwrite(&old_elem_data, sizeof(old_elem_data), 1, tmp);
            for (int i = 1; i < old_elem_data.acc - old_acc; i++) {
                struct customer new_elem_data = {old_acc + i, "-", "-", 0, 0, 0};
                FILE* trns = fopen(seconde_path, "r");
                if ((new_elem_data.debt += fnd_debt(fnd_res(trns, 1), new_elem_data.acc, trns)) >
                    0.00000000001) {
                    fwrite(&new_elem_data, sizeof(new_elem_data), 1, tmp);
                }
                fclose(trns);
            }
        } else {
            fwrite(&old_elem_data, sizeof(old_elem_data), 1, tmp);
        }
        old_acc = old_elem_data.acc;
        temp += sizeof(old_elem_data);
    }
    if (main != NULL) fclose(main);
    if (tmp != NULL) {
        fclose(tmp);
        rename("tmp.dat", first_path);
    }
}
double fnd_debt(size_t res, int acc, FILE* main) {
    double d = 0;
    size_t tmp = 0;
    while (tmp <= res) {
        struct trans elem;
        fread(&elem, sizeof(elem), 1, main);
        if (acc == elem.acc) d += elem.debt;
        tmp += sizeof(elem);
    }
    return d;
}
#endif
