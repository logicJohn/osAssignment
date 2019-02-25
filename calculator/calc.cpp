// Johnnie Hernandez & Malik Hill
//  CSCI 3000
#include <iostream>
#include <thread>
#include <list>
#include <iterator>

using namespace std;

double avgValue = 0;
int maxValue = 0;
int minValue = 0;

// Sets avgValue to the average of all ints in given list
void average(list<int> listOfNumbers);
// Sets maxValue to the smallest number in the list of ints
void minimumList(list<int> listOfNumbers);
// Sets minValue to the largest number in the list of ints
void maximumList(list<int> listOfNumbers);

int main () {

    int temp;
    //prompt user to enter a line of numbers
    cout << "insert a set of integers" << endl;
    // store numbers into integer list
    list<int> listOfNum;
    
    do {
        printf( "Enter number\n");
        scanf("%d", &temp);
        if( temp > 0 ) {
            listOfNum.push_back(temp);
        }
    } while (temp >= 0);

    //call three threads
    thread th1 (average, listOfNum);
    thread th2 (minimumList, listOfNum);
    thread th3 (maximumList, listOfNum);

    //wait for threads
    th1.join();
    th2.join();
    th3.join();

    //print avg, min, max
    
    printf("The average value is: %f\n", avgValue);
    printf("THe minimum value is: %d\n", minValue);
    printf("The maximum value is: %d\n", maxValue);
    
    return 0;    
}

void average(list<int> listOfNumbers) {
    double sum = 0;
    
    for (auto it = listOfNumbers.begin(); it != listOfNumbers.end(); ++it) {
        sum = sum + *it;
    }
    avgValue = sum/listOfNumbers.size();
}

void minimumList(list<int> listOfNumbers) {
    listOfNumbers.sort();
    minValue = listOfNumbers.front();
}

void maximumList(list<int> listOfNumbers) {
    listOfNumbers.sort();
    maxValue = listOfNumbers.back();
}