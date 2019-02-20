//Johnnie Hernandez

#include <thread>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

double avg = 0;
double maxValue = 0;
double minValue = 0;

// Returns the average of all ints in given list
void average(list<int> listOfNumbers);
// Returns the smallest number in the list of ints
void minimumList(list<int> listOfNumbers);
// Returns the largest number in the list of ints
void maximumList(list<int> listOfNumbers);

int main () {

    int temp;
    //prompt user to enter a line of numbers
    cout << "insert a set of integers" << endl;
    // store numbers in list
    list<int> listOfNum;
    
    do {
        printf( "Enter number");
        scanf("%d", &temp);
    } while (temp >= 0);

    //call three threads
    thread th1(average, 3);

    thread th2(minimumList, 3);

    thread th3(maximumList, 3);

    th1.join();
    th2.join();
    th3.join();

    printf("The program will report:\n");
    printf("The average value is: %d\n", avg);
    printf("THe minimum value is: %d\n", minValue);
    printf("The maximum value is: %d\n", maxValue);
    
    return 0;    
}

void average(list<int> listOfNumbers) {
    int sum = 0;
    for (list<int>::iterator it = listOfNumbers.begin(); it != listOfNumbers.end(); ++it) {
        sum = sum + *it;
    }
    avg = sum/listOfNumbers.size();

    return;
}

void minimumList(list<int> listOfNumbers) {
    listOfNumbers.sort();
    minValue = listOfNumbers.front();
    return;
}

void maximumList(list<int> listOfNumbers) {
    listOfNumbers.sort();
    maxValue = listOfNumbers.back();
    return;
}