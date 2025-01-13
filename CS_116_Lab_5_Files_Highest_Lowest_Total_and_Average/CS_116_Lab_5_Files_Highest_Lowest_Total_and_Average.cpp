/*Looks good.   No validation necessary.  It would be a good idea to include a "File opened successfully" message.*/

/*Professor, if the program needs to check the input data with validation, please let me know. */

/* THE ALGORITHM:
  1. Set up variables for input file, output file, input Value, 
     highest number, lowest number, their total and average. 
  2. Open input.txt file and check the file is a good file.
  3. Open output.txt file.
  4. Output the labels and write them to output.txt file.
  5. Use a while-loop to check the end of file.
  6. Use a for-loop to read 7 numbers from input file and write them to output file. 
  7. Determine the highest, the lowest, their total and average. 
  8. Output the highest, the lowest, their total and average and write them to output file.
  9. Go to step 5 until the end of file.
 10. Close input.txt and output.txt.
*/

/* The PSEUDOCODE:
   Purpose of the program: 
   Write a program to utilize one file for input and one file for output to find the highest number, the lowest number, their total and average.

   Input or given data: 
   input.txt   - the name of input file
   infile      - input file
   inputValue  - input Value from input file

   Processing:
   infile.open("input.txt")
   if (!infile) 
      print error message and exit program.

   outfile.open("output.txt")
   print "The 7 numbers, Highest, Lowest, Total, and Average"
   outfile = The 7 numbers, Highest, Lowest, Total, and Average

   while (!infile.eof()))
      total = 0;
      for (i = 0; i < 7; i++)
         inputValue = infile 
         print inputValue
         outfile = inputValue
         if (i == 0)
            highest = lowest = inputValue
         else if (inputValue > highest)
            highest = inputValue
         else if (inputValue < lowest)
            lowest = inputValue
         total += inputValue

      average = total / 7
      print "highest, lowest, total and average"
      outfile = highest, lowest, total and average

   infile.close()
   outfile.close()

   Output:
   output.txt - the name of output file
   The 7 numbers                             Highest Lowest  Total   Average 
   346   130   982   90    656   117   595   982     90      2916    416.57  
   ...
   151   64    98    813   67    834   369   834     64      2396    342.29
*/

// Levi Hung
// Section 22855
// Lab 5A
// Day             : 03/28/23
// Time            : 09:00 PM
// This program utilizes one file for input and one file for output to find the highest number, the lowest number, their total and average.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int CS_116_Lab_5_Files_Highest_Lowest_Total_and_Average()
{ 
  ifstream infile; 
  ofstream outfile; 
  int inputValue;
  int highest;
  int lowest;
  int total;
  float average;
  int i;

  infile.open ("input.txt");

  if (!infile)
  { 
     cout << "Cannot open file, terminating program"<< endl;
     exit (1);
  }

  cout << "File \"input.txt\" opened successfully." << endl;

  outfile.open ("output.txt");
  cout << "File \"output.txt\" opened successfully." << endl;
  cout << endl;

  cout << fixed << setprecision(2);
  outfile << fixed << setprecision(2);
  cout << setw(42) << left << "The 7 numbers" << setw(8) << "Highest" << 
          setw(8) << "Lowest" << setw(8) << "Total" << setw(8) << "Average" << endl;
  outfile << setw(42) << left << "The 7 numbers" << setw(8) << "Highest" << 
             setw(8) << "Lowest" << setw(8) << "Total" << setw(8) << "Average" << endl;

  while (!infile.eof())
  { 
     total = 0;

     for (i = 0; i < 7; i++) 
     {
        infile  >> inputValue;
        cout    << setw(6) << left << inputValue;
        outfile << setw(6) << left << inputValue;;
        if (i == 0) {
           highest = inputValue;
           lowest  = inputValue;
        } 
        else if (inputValue > highest) 
        {
           highest = inputValue;
        } 
        else if (inputValue < lowest) 
        {
           lowest = inputValue;
        }
        total += inputValue;
     }

     average = static_cast<float> (total) / 7;
     cout << setw(8) << highest;
     cout << setw(8) << lowest;
     cout << setw(8) << total;
     cout << setw(8) << average;
     cout << endl;

     outfile << setw(8) << highest;
     outfile << setw(8) << lowest;
     outfile << setw(8) << total;
     outfile << setw(8) << average;
     outfile << endl;

  }

  infile.close();
  outfile.close ();
  cout << "Process completed.";

  return 0;
}

/* Sample Run:
File "input.txt" opened successfully.
File "output.txt" opened successfully.

The 7 numbers                             Highest Lowest  Total   Average 
346   130   982   90    656   117   595   982     90      2916    416.57  
415   948   126   -4    558   571   87    948     -4      2701    385.86  
42    360   412   721   463   47    119   721     42      2164    309.14  
441   190   985   214   509   2     571   985     2       2912    416.00  
77    81    681   651   995   93    74    995     74      2652    378.86  
310   9     995   561   92    14    288   995     9       2269    324.14  
466   664   892   8     766   34    639   892     8       3469    495.57  
151   64    98    813   67    834   369   834     64      2396    342.29
*/