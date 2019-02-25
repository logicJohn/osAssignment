
Compiled using gcc version 7.3.0 (Ubuntu 7.3.0-27ubuntu1~18.04) :

g++ calc.cpp -o Calc -std=c++0x -pthread

./Calc

--------------------------

Program taks a list of integers and stops collecting ints on a -1 input

It then starts 3 threads using provided ints and finds avg min max

---------------------------

There is no data validation so improper inputs will require terminating program

Sample
---------------------


insert a set of integers
Enter number
4
Enter number
5
Enter number
6
Enter number
7
Enter number
8
Enter number
-1
The program will report:
The average value is: 6.000000
THe minimum value is: 4
The maximum value is: 8

