#include <iostream>
#include <iomanip>
using namespace std;

void GetData(int *, int *, int *);
void FindLargestSmallest(int , int , int , int *, int *);
void PrintData(int, int, int, int, int);

int CS_116_Lab_9_Pointers_Find_Largest_and_Smallest() {
    int inputNum1;
    int inputNum2;
    int inputNum3;
    int *inputNum1Ptr;
    int *inputNum2Ptr;
    int *inputNum3Ptr;
    int largest;
    int smallest;
    int *largestPtr;
    int *smallestPtr;

    inputNum1Ptr = &inputNum1;
    inputNum2Ptr = &inputNum2;
    inputNum3Ptr = &inputNum3;
    largestPtr   = &largest;
    smallestPtr  = &smallest;

    GetData(inputNum1Ptr, inputNum2Ptr, inputNum3Ptr);

    FindLargestSmallest(inputNum1, inputNum2, inputNum3, largestPtr, smallestPtr);

    PrintData(inputNum1, inputNum2, inputNum3, largest, smallest);

    return 0;
}

void GetData(int *num1, int *num2, int *num3) {
   cout << "Enter the first  number (1-100): ";
   cin >> *num1;
   while (!cin || *num1 < 0 || *num1 > 100) {
     cin.clear();
     cin.ignore(200,'\n');
     cout << "Error! Input number must be (1-100)." << endl;
     cout << "Enter the first  number (1-100): ";
     cin >> *num1;
   }

   cout << "Enter the second number (1-100): ";
   cin >> *num2;
   while (!cin || *num2 < 0 || *num2 > 100) {
     cin.clear();
     cin.ignore(200,'\n');
     cout << "Error! Input number must be (1-100)." << endl;
     cout << "Enter the second number (1-100): ";
     cin >> *num2;
   }

   cout << "Enter the third  number (1-100): ";
   cin >> *num3;
   while (!cin || *num3 < 0 || *num3 > 100) {
     cin.clear();
     cin.ignore(200,'\n');
     cout << "Error! Input number must be (1-100)." << endl;
     cout << "111Enter the third  number (1-100): ";
     cin >> *num3;
   }
}

void FindLargestSmallest(int num1, int num2, int num3, int *largestPtr, int *smallestPtr) 
{
    *largestPtr = num1;
    if (num2 > *largestPtr) {
        *largestPtr = num2;
    }
    if (num3 > *largestPtr) {
        *largestPtr = num3;
    }

    *smallestPtr = num1;
    if (num2 < *smallestPtr) {
        *smallestPtr = num2;
    }
    if (num3 < *smallestPtr) {
        *smallestPtr = num3;
    }
}

void PrintData(int num1, int num2, int num3, int largest, int smallest) 
{
    cout << "The first  data is " << num1 << "." << endl;
    cout << "The sencod data is " << num2 << "." << endl;
    cout << "The third  data is " << num3 << "." << endl;

    cout << "The largest  number is " << largest  << "." << endl;
    cout << "The smallest number is " << smallest << "." << endl;
}

/* Sample Run:
Enter the first  number (1-100): 1
Enter the second number (1-100): 2
Enter the third  number (1-100): 3
The first  data is 1.
The sencod data is 2.
The third  data is 3.
The largest  number is 3.
The smallest number is 1.

*/