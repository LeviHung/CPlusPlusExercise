#include <iostream>
using namespace std;
#include <string>

/*THE ALGORITHM:
  1.  Set up variables for name and weight
  2.  Ask users for their name and store it
  3.  Ask users for their age and store it
  4.  Output the name and age to the screen*/

// Levi Hung / LeviHung
// Section 17664
// Lab 1
//This little program converts pounds to kilograms

int main() {
  string name;
  double pounds, kg;
  cout << "What is your name (first name only)?";
  cin >> name;
  cout << "How many pounds do you weigh?";
  cin >> pounds;
  kg = pounds / 2.205;
  cout << name << ", you weigh " << kg << " kilograms." << endl;
  return 0;
}

/*
What is your name (first name only)?Levi
How many pounds do you weigh?175
Levi, you weigh 79.3651 kilograms.
*/