#include "stdio.h"

enum Days {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    enum Days myDays;
    myDays = Sunday;
    printf("%d\n", myDays);
    return 0;
}