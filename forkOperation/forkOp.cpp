// Johnnie Hernandez & Malik Hill
//  CSCI 3000

// Takes an integer and produces a squence(n) until sequence(n) equals 1
// The sequence is run by a child and the parent waits for the child to finish

// The sequence(n):
// if n is odd
// n = n*3 + 1
// if n is even
// n = n/2
// if n is not equal to 1 then run sequence(n) again
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

// sequence to run
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
    // Creates a child and has the child do forkCalc and the parent wait()
    if ( fork() == 0 ) {
        //Child Process
        forkCalc(temp);
        exit(0);
    } else {
        wait(NULL);
    }
    return 0;
}