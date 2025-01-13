/*Professor, I'm sorry. I forgot to test negative income and the number of members less than 1. I added the code. Thank you. Happy Mother's Day! */ 

/*Levil:  This is a beautiful program.  Everything works and your error checking is good.  Did you test all of the errors?*/

/* THE PROGRAM STRUCTURE: 
                                       main
                                         |
   ------------------------------------------------------------------------------------
   |                       |                           |               |              |
GetDataFromFile         SortData                   PrintMenu    PrintData             |
Conf : fileName         Conf :  numRecords         Conf : None  Conf : householdArray |
       arraySize        Ref  :  householdSortArray Ref  : None         numRecords     |
Ref  : householdArray                                           Ref  : None           |
       numRecords                                                                     |
       errorMsg                                                                       |
Ret  : isGoodData                                                                     |
                                                                                      |
   ------------------------------------------------------------------------------------
   |                       |                            | 
CalcAverageIncome       CalcPercentPoverty       CalcMedianIncome    
Conf : householdArray   Conf : householdArray    Conf : householdSortArray
       numRecords              numRecords               numRecords
Ref  : None             Ref  : None              Ref  : None
*/

/* THE ALGORITHM:
  1. Set up variables for household item type array and household item type sorted array, 
     number of records, good data flag, and error message, 
  2. Call GetDataFromFile() to read data from the input file, set householdArray[],
     check its validation, and get the number of elements in the array.
  3. If it is not good data, print an error message and exit.
  4. Copy the elements of householdArray[] to the elements of householdSortArray[] and 
     call SortData() to sort data in householdSortArray[].
  5. Use a while loop to check whether the user wants to quit or execute options again.
  6. Call PrintMenu() to show a menu of options.
  7. Get the user's input to determine what options should be executed.
     A - call PrintData(), B - call CalcAverageIncome(), C - call CalcPercentPoverty(),
     D - call PrintData() by householdSortArray, E - call CalcMedianIncome(), and
     F - exit.
*/

/* The PSEUDOCODE:
   Purpose of the program:  
   Gets the information from a file and then presents a MENU of options available to the user. 
   Input or given data: 
   input.txt   - the name of input file
   inputValue  - the user's input

   Processing:
   ---------------------------------------------------
   main() -
   ---------------------------------------------------
   isGoodData = GetDataFromFile()
   if (!isGoodData)
       print error message and exit

   copy householdArray[] to householdSortArray[]
   SortData();

   while (!isQuit)
       call PrintMenu()
       inputValue = cin
       switch (inputValue)
           case 'A' or 'a': call PrintData()
           case 'B' or 'b': call CalcAverageIncome()
           case 'C' or 'c': call CalcPercentPoverty()
           case 'D' or 'd': call PrintData() by householdSortArray[]
           case 'E' or 'e': call CalcMedianIncome
           case 'F' or 'f': set isQuit = true 
           default        : print "Invaild choice!"    

   ---------------------------------------------------
   GetDataFromFile() -
   ---------------------------------------------------   
   inFile.open();
   if (!inFile)
       set errorMsg
       isGoodData = false
       return isGoodData

   while ((count < arraySize) && 
            !inFile.eof() && 
            isGoodData)
       hh[count].id = inFile   
       check hh[count].id is 4-byte

       hh[count].income = inFile
       check hh[count].income is valid and not less than 0

       hh[count].num = inFile
       check hh[count].num is valid and not less than 1
       count++

   set numRecords = count
   check numRecords is less than arraySize
   inFile.close()
   return isGoodData  

   ---------------------------------------------------
   SortData() - Refer to bubble sort algorithm in <<5 Bubble Sort PDF.pdf>>
   ---------------------------------------------------
   do
   {
     Swap = 0;
     for (int Count = 0; Count < (numRecords - 1); Count++)
       if (hh[Count].income > hh[Count + 1].income)
          Temp = hh[Count]
          hh[Count] = hh[Count + 1]
          hh[Count + 1] = Temp
          Swap = 1
   } while (Swap != 0)

   ---------------------------------------------------
   PrintMenu() -
   ---------------------------------------------------
   print "---------------- MENU ----------------------"
   print "A) Print all the input data."
   print "B) Calculate and print the data greater than the average income."
   print "C) Determine the percentage of households in poverty."
   print "D) Print all the sorted input data."
   print "E) Calculate and print the median household income."
   print "F) Exit."

   ---------------------------------------------------
   PrintData() -
   ---------------------------------------------------
   print "ID         Income          number"
   for (i = 0; i < numRecords; i++)
       print "hh[i].id   hh[i].income    hh[i].num"

   ---------------------------------------------------
   CalcAverageIncome() -
   ---------------------------------------------------
   for (i = 0; i < numRecords; i++)
       totalIncome += hh[i].income
   avgIncome = totalIncome / numRecords
   print "The average household income is avgIncome ."
   print "The input data is greater than the average income:"
   for (i = 0; i < numRecords; i++)
       if (hh[i].income > avgIncome) 
           print "hh[i].id  hh[i].income" 

   ---------------------------------------------------
   CalcPercentPoverty() -  
   ---------------------------------------------------
   for (i = 0; i < numRecords; i++) 
       povertyIncome = 8000 + 500 * (hh[i].num - 2)
       if (hh[i].income < povertyIncome)
           povertyNum++;
   print "The percentage of households having an income below the poverty level is "; 
          (povertyNum) / (numRecords) * 100 "%."

   ---------------------------------------------------
   CalcMedianIncome() - 
   ---------------------------------------------------
   if numRecords is odd
       medianIncome = hh[numRecords/2].income;
   else 
       medianIncome = (hh[numRecords/2].income + hh[(numRecords/2) - 1].income) / 2;
   print "The median household income is medianIncome."  

   Output:
   File "input.txt" opened successfully.

   ---------------- MENU ------------------------------------------
   A) Print all the input data.
   B) Calculate and print the data greater than the average income.
   C) Determine the percentage of households in poverty.
   D) Print all the sorted input data.
   E) Calculate and print the median household income.
   F) Exit.
   Enter choice: a
   All the input data:
      ID      Income  number
    WHVC    34000.00       5
    AAAA    10500.00       8
*/

// Levi Hung
// Section 22855
// Lab 8A
// Day             : 05/12/23
// Time            : 11:00 PM
// This program gets the information from a file and then presents a MENU of options 
// available to the user. 
// The options include print all of the input data, 
// calculate and print the data that is greater than the average household income, 
// determine the percentage of households having an income below the poverty level, 
// print all of the input data sorted by income, and 
// calculate and print the median household income. 

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct householdItemType {
    char  id[4];
    float income;
    int   num;
};

bool GetDataFromFile(string, householdItemType [], int, int &, string &);
void SortData (householdItemType [], int);
void PrintMenu();
void PrintData(householdItemType [], int);

void CalcAverageIncome (householdItemType [], int);
void CalcPercentPoverty(householdItemType [], int);
void CalcMedianIncome  (householdItemType [], int);

int CS_116_Lab_8_Structures_Household_Income() 
{
  char inputValue;
  bool isQuit = false;
  bool isGoodData = true;
  const string INPUT_FILENAME = "input.txt";
  const int MAX_NUM_RECORD = 20;
  householdItemType householdArray[MAX_NUM_RECORD];
  householdItemType householdSortArray[MAX_NUM_RECORD];
  int    numRecords;
  string errorMsg;
  int    i;

  isGoodData = GetDataFromFile(INPUT_FILENAME, 
                               householdArray, 
                               MAX_NUM_RECORD, 
                               numRecords, errorMsg);
  if (!isGoodData) {
     cout << "Error! The records in file \" " << INPUT_FILENAME << 
              "\" are invalid. " << endl << errorMsg << endl;  
     cout << "Process failed." << endl;
     exit(1);
  }

  for (i = 0; i < numRecords; i++) {
    householdSortArray[i] = householdArray[i];
  }
  SortData(householdSortArray, numRecords);

  while (!isQuit)
  {
      PrintMenu();
      cout << "Enter choice: ";
      cin >> inputValue;
      switch (inputValue) 
      {
          case 'A': 
          case 'a':
              cout << "All the input data:" << endl;
              PrintData(householdArray, numRecords);
              break;

          case 'B': 
          case 'b':
              CalcAverageIncome(householdArray, numRecords);
              break;

          case 'C': 
          case 'c':
              CalcPercentPoverty(householdArray, numRecords);
              break;

          case 'D': 
          case 'd':
              cout << "All the sorted input data:" << endl;
              PrintData(householdSortArray, numRecords);
              break;

          case 'E': 
          case 'e':
              CalcMedianIncome(householdSortArray, numRecords);
              break;

          case 'F': 
          case 'f':
              isQuit = true;
              break;

          default:
              cout << "Invalid choice! The choice must be A, B, C, D, E, or F." << endl;
              break;
        }
    } while (!isQuit);

  cout << "Program exit." << endl;
  return 0;
}

void PrintMenu()
{

  cout << endl << "---------------- MENU ------------------------------------------" << endl;
  cout << "A) Print all the input data." << endl;
  cout << "B) Calculate and print the data greater than the average income." << endl;
  cout << "C) Determine the percentage of households in poverty." << endl;
  cout << "D) Print all the sorted input data." << endl;
  cout << "E) Calculate and print the median household income." << endl;
  cout << "F) Exit." << endl;
}

bool GetDataFromFile(string fileName, householdItemType hh[], 
                     int arraySize, int & numRecords, string & errorMsg)
{
  ifstream inFile;
  bool isGoodData = true;
  int  count = 0;
  string idStr;
  int i;

  inFile.open(fileName);
  if (!inFile)
  { 
     errorMsg = "Cannot open file \"";
     errorMsg += fileName;
     errorMsg += "\", terminating program";
     isGoodData = false;
     return isGoodData;
  }
  cout << "File \"" << fileName << "\" opened successfully." << endl;

  while ((count < arraySize) && 
         !inFile.eof() && 
         isGoodData)
  {  
     inFile >> idStr;
     if (idStr.size() != 4) 
     {
       isGoodData = false;
       errorMsg = "The data on line \"";
       errorMsg += to_string(count+1);
       errorMsg += "\" is invalid. ";
     } 
     else 
     {
        for(i = 0; i < 4; i++)
        {
           hh[count].id[i] = idStr.at(i);
        }
     }

     inFile >> hh[count].income;
     if (!inFile || hh[count].income < 0) 
     {
       isGoodData = false;
       errorMsg = "The data on line \"";
       errorMsg += to_string(count+1);
       errorMsg += "\" is invalid. ";
     } 

     inFile >> hh[count].num;
     if (!inFile || hh[count].num < 1) 
     {
       isGoodData = false;
       errorMsg = "The data on line \"";
       errorMsg += to_string(count+1);
       errorMsg += "\" is invalid. ";
     } 

     count ++;    
  }

  numRecords = count;

  if (count >= arraySize) {
     if (!inFile.eof()) 
     {
        isGoodData = false;
        errorMsg = "The number of records exceeds the size of the array.";   
     }
  }

  inFile.close();

  return isGoodData;  
}

void SortData(householdItemType hh[], int numRecords)
{
  int Swap;
  householdItemType Temp;
  do
  {
     Swap = 0;
     for (int Count = 0; Count < (numRecords - 1); Count++)
     {
       if (hh[Count].income > hh[Count + 1].income)
       {
          Temp = hh[Count];
          hh[Count] = hh[Count + 1];
          hh[Count + 1] = Temp;
          Swap = 1;
       }
     }
  } while (Swap != 0);
}

void PrintData(householdItemType hh[], int numRecords)
{
  int i;

  cout << setw(5)  << "ID" << 
          setw(12) << "Income" << 
          setw(8)  << "number" << endl;
  cout << fixed << setprecision(2);
  for (i = 0; i < numRecords; i++)
  {
     cout << setw(5)  << hh[i].id << 
             setw(12) << hh[i].income << 
             setw(8)  << hh[i].num << endl; 
  }
}

void CalcAverageIncome(householdItemType hh[], int numRecords)
{
  float avgIncome = 0;
  float totalIncome = 0;
  int i;

  for (i = 0; i < numRecords; i++) {
    totalIncome += hh[i].income;
  }
  avgIncome = totalIncome / numRecords;

  cout << fixed << setprecision(2);
  cout << "The average household income is " << avgIncome << "." << endl;
  cout << "The input data is greater than the average income:" << endl;
  cout << setw(5)  << "ID" << setw(12) << "Income" << endl;
  for (i = 0; i < numRecords; i++)
  {
     if (hh[i].income > avgIncome) 
     {
        cout << setw(5)  << hh[i].id << setw(12) << hh[i].income << endl; 
     }
  }
}

void CalcPercentPoverty(householdItemType hh[], int numRecords)
{
  float povertyIncome;
  int povertyNum = 0;
  int i;

  for (i = 0; i < numRecords; i++) 
  {
    povertyIncome = 8000 + 500 * (hh[i].num - 2);
    if (hh[i].income < povertyIncome)
    {
       povertyNum++;
    }
  }

  cout << "The percentage of households having an income below the poverty level is "; 
  cout << static_cast<float> (povertyNum) / (numRecords) * 100 << "%." << endl;

}

void CalcMedianIncome(householdItemType hh[], int numRecords)
{
  float medianIncome;

  if (numRecords % 2 == 1) 
  {
     medianIncome = hh[numRecords/2].income;
  }
  else 
  {
     medianIncome = (hh[numRecords/2].income + hh[(numRecords/2) - 1].income) / 2;
  }

  cout << "The median household income is " << medianIncome << "." << endl;  
}

/* Sample Run:
File "input.txt" opened successfully.

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: a
All the input data:
   ID      Income  number
 WHVC    34000.00       5
 AAAA    10500.00       8
 BURB    23500.00       2
 CCCC    15000.00       4
 DATA     8000.00       3
 EEEE    36000.00       5
 FADE     8500.00       4
 GATE    25000.00       1
 HILO     3000.00       1
 JURY   100000.00       5
 KNEL    80000.00       4
 LIST    41000.00       3
 MEMM     5000.00       2
 PQRS    18000.00       2
 RELM    27500.00       4
 SOLD    22100.00       2

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: d
All the sorted input data:
   ID      Income  number
 HILO     3000.00       1
 MEMM     5000.00       2
 DATA     8000.00       3
 FADE     8500.00       4
 AAAA    10500.00       8
 CCCC    15000.00       4
 PQRS    18000.00       2
 SOLD    22100.00       2
 BURB    23500.00       2
 GATE    25000.00       1
 RELM    27500.00       4
 WHVC    34000.00       5
 EEEE    36000.00       5
 LIST    41000.00       3
 KNEL    80000.00       4
 JURY   100000.00       5

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: b
The average household income is 28568.75.
The input data is greater than the average income:
   ID      Income
 WHVC    34000.00
 EEEE    36000.00
 JURY   100000.00
 KNEL    80000.00
 LIST    41000.00

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: c
The percentage of households having an income below the poverty level is 31.25%

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: e
The median household income is 22800.00

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: g
Invalid choice! The choice must be A, B, C, D, E, or F.

---------------- MENU ------------------------------------------
A) Print all the input data.
B) Calculate and print the data greater than the average income.
C) Determine the percentage of households in poverty.
D) Print all the sorted input data.
E) Calculate and print the median household income.
F) Exit.
Enter choice: f
Program exit.
*/