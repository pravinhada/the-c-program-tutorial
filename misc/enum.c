#include "stdio.h"

enum Days {
    Sunday, //0
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday    //6
};

int main() {
    const enum Days myDays = Saturday;
    printf("%d\n", myDays);
    return 0;
}