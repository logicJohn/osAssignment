#include <thread>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int avg = 0;
int max = 0;
int min = 0;

// Returns the average of all ints in given list
void average(list<int> listOfNumbers);
// Returns the smallest number in the list of ints
void minimumList(list<int> listOfNumbers);
// Returns the largest number in the list of ints
void maximumList(list<int> listOfNumbers);

int main () {

    //prompt user to enter a line of numbers
    cout << "insert a set of integers" << endl;
    // store numbers in list
    list<int> listOfNum;
    
    //call three threads
    thread th1(average, 3);

    thread th2(minimumList, 3);

    thread th3(maximumList, 3);

    th1.join();
    th2.join();
    th3.join();

    cout << "The program will report:\n"
    << "The average value is " << avg << 
    "\nThe minimum value is " << max << 
    "\nThe maximum value is " << min << endl;

    return 0;    
}

void average(list<int> listOfNumbers) {

    return 0;
}

void minimumList(list<int> listOfNumbers) {
    
    return 0;
}

void maximumList(list<int> listOfNumbers) {
    
    return 0;
}