/*A very nice program*/

/* Professor, I have modified my math. I used totalCaffeine to instead of remainCaffeine and I removed the expression about assigning totalCaffeine to 0. Thanks. */

/*A very nice program--but I disagree with your math.  The project says "After caffeine is absorbed into the body, 13% is eliminated from the body each hour. ". It should go down by 13% of what is still in the body--not 13% of the original amount.*/

#include <iostream>
#include <iomanip>
using namespace std;

/* THE ALGORITHM:
  1. Set up variables for type drink, total caffeine, remaining caffeine, 
     during hours and eliminated hours, 
  2. Set up a constant variable for eliminated rate each hour. 
  3. Ask the user for the type of drink.
  4. Ask the user for the amount of caffeine and store it.
     If the user enter invalid data, 
     the program outputs error messages and wait for the next input data.
  5. Ask the user for hours to see and store it.
     If the user enter invalid hours, 
     the program outputs error messages and wait for the next input data.
  6. Output user prompts, drink name, the amount of caffeine, and show hours.
  7. Use a for-loop to calculate and output after hours and remaining caffeine.
     loop initial - 
        eliminated hours is 1
     loop body - 
        totalCaffeine = totalCaffeine * (1 - 0.13);
        output eliminated hours and remaining caffeine     
     loop condition -
        until the user's limit is reached.
  8. Ask the user to continue or quit the program. 
*/

/* The PSEUDOCODE:
   Purpose of the program:  Write a program to compute the amount of caffeine 
                            in the body X hours after the person drinks the coffee.

   Input or given data: 
   typeDrink      - The type of drink
   totalCaffeine  - The amount of caffeine
   duringHours    - The hours you want to see
   repeatChar     - The input date to continue or quit 

   Processing:
   while (repeatChar == 'y' or 'Y')
      typeDrink = getline()

      totalCaffeine = cin()
      while (totalCaffeine is not good data)
         print "Invalid input data. re-enter total caffeine." 
         totalCaffeine = cin()

      duringHours = cin()
      while (duringHours is not good data)
         print "Invalid input data. re-enter hours you want to see." 
         duringHours = cin()

      print typeDrink, totalCaffeine and show hours
      for (hours = 1; hours <= duringHours; hours++) 
         totalCaffeine = totalCaffeine * (1 - 0.13);
         print hours
         print totalCaffeine

      print "Type y to continue, any other to quit:"
      repeatChar = cin() 

   Output:
   The type of drink, the amount of caffeine, the hours you want to see: 
   After hour(s):   remaining caffeine (mg):
           1                    total caffeine * (1 - 0.13)
           2                   (total caffeine * (1 - 0.13)) * (1 - 0.13)
           ...                  ...

   Type y to continue, any other to quit: y
*/

// Levi Hung
// Section 22855
// Lab 4D
// Due Date        : 04/02/23
// Day             : 03/19/23
// Time            : 02:40 AM
// This program computes the amount of caffeine in the body X hours after the person drinks the coffee.

int CS_116_Lab_4_Looping_Caffeine() {
  string typeDrink;
  float totalCaffeine;
  int duringHours;
  int eliminateHours;
  char repeatChar;

  const float ELIMINATED_RATE_HOUR = 0.13;

  cout << fixed << setprecision(2);
  repeatChar = 'y';

  while (repeatChar == 'Y' || repeatChar == 'y') 
  {
     cout << "Enter the type of drink: ";
     getline(cin, typeDrink);

     cout << "Enter the amount of caffeine (mg): ";
     cin >> totalCaffeine;
     while (!cin || totalCaffeine > 350 || totalCaffeine < 0)
     {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error! Invaild data. Enter a positive integer and not be greater than 350: ";
        cin >> totalCaffeine;
     }

     cout << "Enter hours you want to see: ";
     cin >> duringHours;
     while (!cin || duringHours > 14 || duringHours < 0)
     {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error! Invaild data. Enter a positive integer and not be greater than 14: ";
        cin >> duringHours;
     }

     cout << endl;
     cout << typeDrink << ", " << totalCaffeine << " mg of caffeine, show " <<
             duringHours << " hour(s): " << endl;
     cout << "After hour(s):   remaining caffeine (mg):" << endl;

     for (eliminateHours = 1; eliminateHours <= duringHours; eliminateHours++) 
     {
        totalCaffeine = totalCaffeine * (1 - ELIMINATED_RATE_HOUR);
        cout << setw(9)  << right << eliminateHours;
        cout << setw(26) << right << totalCaffeine << endl;
     }

     cout << endl;
     cout << "Type y to continue, any other to quit: ";
     cin >> repeatChar;
     cin.ignore(200, '\n');
     cout << endl;
  }

  return 0;
}

/* Sample Run 1:
Enter the type of drink: 16 oz Starbucks coffee
Enter the amount of caffeine (mg): 310
Enter hours you want to see: 10

16 oz Starbucks coffee, 310.00 mg of caffeine, show 10 hour(s): 
After hour(s):   remaining caffeine (mg):
        1                    269.70
        2                    234.64
        3                    204.14
        4                    177.60
        5                    154.51
        6                    134.42
        7                    116.95
        8                    101.75
        9                     88.52
       10                     77.01

Type y to continue, any other to quit: y

Enter the type of drink: 5-hr Energy drink
Enter the amount of caffeine (mg): 245
Enter hours you want to see: 7

5-hr Energy drink, 245.00 mg of caffeine, show 7 hour(s): 
After hour(s):   remaining caffeine (mg):
        1                    213.15
        2                    185.44
        3                    161.33
        4                    140.36
        5                    122.11
        6                    106.24
        7                     92.43

Type y to continue, any other to quit: y

Enter the type of drink: Black tea
Enter the amount of caffeine (mg): 47
Enter hours you want to see: 5

Black tea, 47.00 mg of caffeine, show 5 hour(s): 
After hour(s):   remaining caffeine (mg):
        1                     40.89
        2                     35.57
        3                     30.95
        4                     26.93
        5                     23.43

Type y to continue, any other to quit: y

Enter the type of drink: Red Bull
Enter the amount of caffeine (mg): 80
Enter hours you want to see: 12

Red Bull, 80.00 mg of caffeine, show 12 hour(s): 
After hour(s):   remaining caffeine (mg):
        1                     69.60
        2                     60.55
        3                     52.68
        4                     45.83
        5                     39.87
        6                     34.69
        7                     30.18
        8                     26.26
        9                     22.84
       10                     19.87
       11                     17.29
       12                     15.04

Type y to continue, any other to quit: q

Sample Run 2:
Enter the type of drink: Sample Run 2
Enter the amount of caffeine (mg): 351
Error! Invaild data. Enter a positive integer and not be greater than 350: -300
Error! Invaild data. Enter a positive integer and not be greater than 350: 350
Enter hours you want to see: 15
Error! Invaild data. Enter a positive integer and not be greater than 14: -10
Error! Invaild data. Enter a positive integer and not be greater than 14: 14

Sample Run 2, 350.00 mg of caffeine, show 14 hour(s): 
After hour(s):   remaining caffeine (mg):
        1                    304.50
        2                    264.92
        3                    230.48
        4                    200.51
        5                    174.45
        6                    151.77
        7                    132.04
        8                    114.87
        9                     99.94
       10                     86.95
       11                     75.64
       12                     65.81
       13                     57.26
       14                     49.81

Type y to continue, any other to quit: Q

*/