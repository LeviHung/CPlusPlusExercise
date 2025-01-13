/*Looks good.  Glad you modified it*/

/*Professor, I modified PrintThreeArrays to PrintArray to complete your demand in class. */

/*Nice work.  I will give out an extra credit with arrays on Monday if you are interested.*/

/* THE PROGRAM STRUCTURE:
                               Main
                                 |
   ---------------------------------------------------------
   |                             |                         |
GetDataToTwoArraysFromFile  MultiplyTwoArrays         PrintArray
Copy: None                  Copy: None                Copy: None

Ref:  firstArray            Ref:  firstArray          Ref:  Array
      firstArraySize              firstArraySize            ArraySize
      secondArray                 secondArray
      secondArraySize             secondArraySize
      inFile                      thirdArray
      numRecords                  thirdArraySize  
      errorMsg
*/ 

/* THE ALGORITHM:
  1. Set up variables for first array, second array, third array, number of records,
     input file, good data flag, and error message, 
  2. Open input.txt file and check the file is a good file.
  3. Call GetDataToTwoArraysFromFile() to read data from the input file, 
     check its validation, store it into two arrays by turn, 
     and get the number of elements in the array.
  4. If it is not good data, print an error message. Goto Step 7.
  5. If it is good data, Call MultiplyTwoArrays(). According to the total number of 
     elements in the array, multiply the elements with the same index in each array  
     and store the product in the third array with the same index.
  6. Call PrintArray() three times to label and output all three arrays.
  7. Close input.txt.
 */

/* The PSEUDOCODE:
   Purpose of the program:  
   This program utilizie arrays to get records from a file and multiply the elements 
   to store the product in a array. It Labels and outputs all arrays.    

   Input or given data: 
   input.txt   - the name of input file
   infile      - input file

   Processing:
   main() -
   infile.open("input.txt")
   if (!infile) 
      print error message and exit program.

   isGoodData = GetDataToTwoArraysFromFile()
   if (!isGoodData)
       print error message.
   else 
       call MultiplyTwoArrays()
       call PrintArray() by the first array
       call PrintArray() by the second array
       call PrintArray() by the third array

   infile.close()

   GetDataToTwoArraysFromFile() - 
   while (count < arrayASize) && 
          !inFile.eof() && 
          isDataGood)
   {
      arrayA[count] = inFile
      if (!inFile) 
         isDataGood = false;
         Set errorMsg 

      arrayB[count] = inFile
      if (!inFile) 
         isDataGood = false;
         Set errorMsg
      count ++;    
   }

   numRecords = count;
   if (count >= arrayASize)
      isDataGood = false
      Set errorMsg

   return isDataGood

   MultiplyTwoArrays() -
   for (i = 0; i < numRecords; i++) 
   {
     arrayC[i] = arrayA[i] * arrayB[i];
   }

   PrintArray() -
   for (i = 0; i < numRecords; i++) 
      print i     array[i]

   Output:
   File "input.txt" opened successfully.
   The First Array:
   Index     Value
       0         3
       1        82
       2         6
       ...
      27       834

   The Second Array:
   Index     Value
       0       130
       1        90
       2       117
       ...
      27       369

   The Third Array: (The product of the arrays)
   Index     Value
       0       390
       1      7380
       2       702
       ...
      27    307746
   */

// Levi Hung
// Section 22855
// Lab 7A
// Day             : 04/27/23
// Time            : 11:00 PM
// This program utilizie arrays to get records from a file and multiply the elements 
// to store the product in a array. It Labels and outputs all arrays. 

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool GetDataToTwoArraysFromFile(int [], int, int [], int, 
                                ifstream &, int &, string &);
void MultiplyTwoArrays(int [], int, int [], int, int [], int);
void PrintArray (int [], int);

int CS_116_Lab_7_Arrays_Multiply_the_Elements() {
  ifstream inFile;
  bool isDataGood;
  string errorMsg = "";

  const int MAX_SIZE_ARRAY = 27;
  int firstArray [MAX_SIZE_ARRAY] = {0};
  int secondArray[MAX_SIZE_ARRAY] = {0};
  int thirdArray [MAX_SIZE_ARRAY] = {0};
  int numRecords = 0;

  inFile.open ("input.txt");
  if (!inFile)
  { 
     cout << "Cannot open file \"input.txt\", terminating program"<< endl;
     exit (1);
  }
  cout << "File \"input.txt\" opened successfully." << endl;

  isDataGood = GetDataToTwoArraysFromFile(firstArray, MAX_SIZE_ARRAY, 
                                          secondArray, MAX_SIZE_ARRAY, 
                                          inFile, numRecords, errorMsg);
  if (!isDataGood) 
  {
     cout << "Error! The records in file \"input.txt\" are invalid. " <<
              endl << errorMsg << endl;  
     cout << "Process failed." << endl;
  } 
  else 
  {
     MultiplyTwoArrays(firstArray,  numRecords, 
                       secondArray, numRecords, 
                       thirdArray,  numRecords);

     cout << "The First Array:" << endl;
     PrintArray(firstArray,  numRecords);

     cout << "The Second Array:" << endl;
     PrintArray(secondArray, numRecords); 

     cout << "The Third Array: (The product of the arrays)" << endl;
     PrintArray(thirdArray,  numRecords);

     cout << "Process completed." << endl;
  }

  inFile.close();

  return 0;
}

bool GetDataToTwoArraysFromFile(int arrayA[], int arrayASize, 
                                int arrayB[], int arrayBSize, 
                                ifstream & inFile, int & numRecords,
                                string & errorMsg)
{
  bool isDataGood = true;
  int  count = 0;

  while ((count < arrayASize) && 
         !inFile.eof() && 
         isDataGood)
  {
     inFile >> arrayA[count];
     if (!inFile) 
     {
       isDataGood = false;
       errorMsg = "The data of arrayA[";
       errorMsg += to_string(count);
       errorMsg += "] is invalid. ";
     }

     inFile >> arrayB[count];
     if (!inFile) 
     {
       isDataGood = false;
       errorMsg += "The data of arrayB[";
       errorMsg += to_string(count);
       errorMsg += "] is invalid. ";
     }

     count ++;    
  }

  numRecords = count;

  if (count >= arrayASize) {
     if (!inFile.eof()) 
     {
         isDataGood = false;
         errorMsg = "The number of records exceeds the size of the arrays.";
     }
  }

  return isDataGood;
}

void MultiplyTwoArrays(int arrayA[], int arrayASize, 
                       int arrayB[], int arrayBSize, 
                       int arrayC[], int arrayCSize)
{
  int i;

  for (i = 0; i < arrayASize; i++) 
  {
    arrayC[i] = arrayA[i] * arrayB[i];
  }

}

void PrintArray(int array[], int arrayASize)
{
  int i;

  cout << fixed << setprecision(2);  
  cout << setw(5)  << "Index" << 
          setw(10) << "Value" << endl;
  for (i = 0; i < arrayASize; i++) 
  {
     cout << setw(5)  << i <<
             setw(10) << array[i] << endl;
  }
  cout << endl;
}

/* Sample Run 1:
File "input.txt" opened successfully.
The First Array:
Index     Value
    0         3
    1        82
    2         6
    3        95
    4        94
    5         4
    6       571
    7        42
    8       412
    9       263
   10       119
   11       190
   12       214
   13         2
   14        77
   15        68
   16       995
   17        74
   18         9
   19       561
   20        14
   21       466
   22        82
   23        76
   24        69
   25         6
   26        13
   27       834

The Second Array:
Index     Value
    0       130
    1        90
    2       117
    3        15
    4       126
    5       558
    6        87
    7        60
    8       721
    9        47
   10       441
   11        85
   12       509
   13        51
   14        81
   15        61
   16        93
   17       310
   18        95
   19        29
   20        28
   21        64
   22         8
   23        34
   24       151
   25        98
   26        67
   27       369

The Third Array: (The product of the arrays)
Index     Value
    0       390
    1      7380
    2       702
    3      1425
    4     11844
    5      2232
    6     49677
    7      2520
    8    297052
    9     12361
   10     52479
   11     16150
   12    108926
   13       102
   14      6237
   15      4148
   16     92535
   17     22940
   18       855
   19     16269
   20       392
   21     29824
   22       656
   23      2584
   24     10419
   25       588
   26       871
   27    307746
Process completed.

Sample Run 2:
File "input.txt" opened successfully.
Error! The records in file "input.txt" are invalid. 
The data of array[0] is invalid.
Process failed.

Sample Run 3:
File "input.txt" opened successfully.
Error! The records in file "input.txt" are invalid. 
The number of records exceeds the size of the arrays.
Process failed.
*/