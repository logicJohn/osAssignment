
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void forkCalc(int x) {
    int temp = x;
    printf("%d", temp);
    while( temp != 1 ) {
        if (temp%2 == 0) {
            temp = temp/2;
        } else {
            temp = (temp*3) + 1;
        }
        printf("%d", temp);
    }
}

int main () {

    int temp;
    printf("Input integer");
    scanf("%d", &temp);
    if ( fork() == 0 ) {
        forkCalc(temp);
        exit(0);
    } else {
        wait(NULL);
    }
    return 1;
}