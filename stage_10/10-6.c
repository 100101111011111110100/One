#include <stdio.h>

struct customer {
    char lastName[15];
    char firstName[15];
    int customerNumber;

    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;

void r();
void f();
void e();
void a();
void s();
void d();
void q();
void w();
int main() {
    customerPtr = &customerRecord;
    // struct customer f;
    r();
    f();
    e();
    a();
    s();
    d();
    q();
    w();
    printf("Hello %s %s your age is %d!\nYour phone number is %s\nYour address is %s %s %s\nCode : %s\n",
           customerPtr->firstName, customerPtr->lastName, (*customerPtr).customerNumber,
           customerPtr->personal.phoneNumber, customerPtr->personal.address, customerPtr->personal.city,
           customerPtr->personal.state, customerPtr->personal.zipCode);
    return 0;
}
void r() {
    char *s = "Ganeev";
    for (size_t i = 0; *(s + i); i++) {
        customerRecord.lastName[i] = *(s + i);
    }
}
void f() {
    char *s = "Artur";
    for (size_t i = 0; *(s + i); i++) {
        // customerRecord.firstName[i]=*(s+i);
        customerPtr->firstName[i] = *(s + i);
    }
}
void e() {
    int age = 25;
    (*customerPtr).customerNumber = age;
}

void a() {
    char *s = "+7(999)387-49-49";
    for (size_t i = 0; *(s + i); i++) {
        customerPtr->personal.phoneNumber[i] = *(s + i);
    }
}
void s() {
    char *s = "8 Pushkin Street";
    for (size_t i = 0; *(s + i); i++) {
        customerPtr->personal.address[i] = *(s + i);
    }
}

void d() {
    char *s = "Kazan city";
    for (size_t i = 0; *(s + i); i++) {
        customerPtr->personal.city[i] = *(s + i);
    }
}

void q() {
    char *s = "RT";
    for (size_t i = 0; *(s + i); i++) {
        customerPtr->personal.state[i] = *(s + i);
    }
}

void w() {
    char *s = "10-zA345";
    for (size_t i = 0; *(s + i); i++) {
        customerPtr->personal.zipCode[i] = *(s + i);
    }
}