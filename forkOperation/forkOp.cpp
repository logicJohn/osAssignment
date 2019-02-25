// Johnnie Hernandez & Malik Hill

#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
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
        printf(" %d ", temp);
    }
    printf("\n");
}

int main () {

    int temp;
    printf("Input integer\n");
    scanf("%d", &temp);
    if ( fork() == 0 ) {
        //Child Process
        forkCalc(temp);
        exit(0);
    } else {
        wait(NULL);
    }
    return 0;
}