// Levi Hung
// Section 22855
// Extra credit Lab 4
// Day             : 03/28/23
// Time            : 06:00 PM
// This program writes the C++ code to output some patterns.

#include <iostream>
#include <iomanip>
using namespace std;

int CS_116_Lab_4_Extra_Patterns() {
  int i;
  int j;
  int baseNumber;
  int medianNumber;

  cout << "Nested For Loop #1:" << endl;
  for (i = 0; i < 12; i += 4) 
  {
     for (j = 1; j <= 4; j++)
     {
        cout << setw(3) << j+i;   
     }  
     cout << endl;
  }
  cout << endl;

  cout << "Nested For Loop #2:" << endl;
  for (i = 1; i <= 5; i++) 
  {
     for (j = 1; j <= i; j++)
     {
         cout << i << " "; 
     }
     cout << endl;
  }
  cout << endl;

  cout << "Nested For Loop #3:" << endl;
  cout << "Enter a base number: ";
  cin >> baseNumber;
  while (!cin || baseNumber > 20 || baseNumber < 1 || (baseNumber%2 == 0)) 
  { 
     cin.clear();
     cin.ignore(200, '\n');
     cout << "Error! Invalid data. You must enter an odd positive integer and not greater than 20: ";
     cin >> baseNumber;   
  }

  medianNumber = baseNumber/2 + 1;
  for (i = 0; i < medianNumber; i++) 
  {
     for (j = 1; j <= baseNumber; j++)
     {
       if ((j >= (medianNumber - i)) && 
           (j <= (medianNumber + i))) 
       {
         cout << "X";  
       } 
       else 
       {
         cout << " ";
       }
     }
     cout << endl;
  }

  cout << endl;

  cout << "Nested For Loop #4:" << endl;
  cout << "Enter a base number: ";
  cin >> baseNumber;
  while (!cin || baseNumber > 20 || baseNumber < 1 || (baseNumber%2 == 0)) 
  { 
     cin.clear();
     cin.ignore(200, '\n');
     cout << "Error! Invalid data. You must enter an odd positive integer and not greater than 20: ";
     cin >> baseNumber;   
  }

  medianNumber = baseNumber/2 + 1;
  for (i = 0; i < baseNumber; i++) 
  {
     for (j = 1; j <= baseNumber; j++)
     {
       if (i < medianNumber) {
          if ((j >= (medianNumber - i)) && 
              (j <= (medianNumber + i))) 
          {
             cout << "X";  
          } 
          else 
          {
             cout << " ";
          }
       } 
       else 
       {
          if ((j >= (medianNumber - (baseNumber - i - 1)) && 
              (j <= (medianNumber + (baseNumber - i - 1))))) 
          {
             cout << "X";  
          } 
          else 
          {
             cout << " ";
          }         
       }
     }
     cout << endl;
  }
  cout << endl;

  return 0;
}