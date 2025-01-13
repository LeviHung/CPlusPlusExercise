/*Very nice program.  You might consider using getline for the name in case someone types in their first and last name.*/

#include <iostream>
#include <iomanip>
using namespace std;
//#include <string>

/*THE ALGORITHM:
  1.  Set up variables for name, meal cost, tax, less tip, more tip, 
      a total bill with less tip(15%), and a total bill with more tip(20%).
  2.  Set up constant variables for tax rate, less tip rate, and more tip rate.
  3.  Ask the user for their name and store it
  4.  Ask the user for their meal cost and store it
  5.  Calculate the tax of the meal cost.
      tax = meal cost * tax rate
  6.  Calculate the less tip and more tip for the meal cost.
      tip = meal cost * tip rate
  7.  Calculate the total bills after 15% gratuity and 20% gratuity.
      bill = meal cost + tax + tip
  8.  Output the meal cost, tax, tip(15%), tip(20%), 
      your total bill after 15% gratuity, and your total bill after 20% gratuity. */

// Levi Hung
// Section 17664
// Lab 2
// This program computes the tax and tip on a restaurant bill.

int CS_116_Lab_2_Input_Output_Tax_and_Tip() {
  string name;
  float  mealCost;
  float  tax;
  float  lessTip;
  float  moreTip;
  float  totalBillwithLessTip;
  float  totalBillwithMoreTip;

  const float TAX_RATE = 0.0975;
  const float LESS_TIP_RATE = 0.15;
  const float MORE_TIP_RATE = 0.20;

  cout << "Enter your first name:  ";
  getline (cin, name);
  cout << "Enter the meal cost: ";
  cin >> mealCost; 

  tax     = mealCost * TAX_RATE;
  lessTip = mealCost * LESS_TIP_RATE;
  moreTip = mealCost * MORE_TIP_RATE;

  totalBillwithLessTip = mealCost + tax + lessTip;
  totalBillwithMoreTip = mealCost + tax + moreTip;
  cout << setw(40) << setfill('*') << "" << endl;
  cout << setfill(' ');

  cout << fixed << setprecision(2);
  cout << setw(20) << left  << "Meal Cost" << "$";
  cout << setw(6)  << right << mealCost << endl;
  cout << setw(20) << left  << "Tax" << "$"; 
  cout << setw(6)  << right << tax << endl;
  cout << setw(20) << left  <<  "Tip (15%)" << "$";
  cout << setw(6)  << right << lessTip << endl;
  cout << setw(20) << left  <<  "Tip (20%)" << "$";
  cout << setw(6)  << right << moreTip << endl;
  cout << endl;

  cout << "Your total bill is " << totalBillwithLessTip << " after 15% gratuity." << endl;
  cout << "or" << endl;
  cout << "Your total bill is " << totalBillwithMoreTip << " after 20% gratuity." << endl;

  return 0;
  }

/*
Sample Run 1:

Enter your first name:  Levi Hung
Enter the meal cost: 56.00
****************************************
Meal Cost           $ 56.00
Tax                 $  5.46
Tip (15%)           $  8.40
Tip (20%)           $ 11.20

Your total bill is 69.86 after 15% gratuity.
or
Your total bill is 72.66 after 20% gratuity.

Sample Run 2:

Enter your first name:  Cathy Li
Enter the meal cost: 100
****************************************
Meal Cost           $100.00
Tax                 $  9.75
Tip (15%)           $ 15.00
Tip (20%)           $ 20.00

Your total bill is 124.75 after 15% gratuity.
or
Your total bill is 129.75 after 20% gratuity.
*/