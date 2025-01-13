/* Professor, I moved all output statements to the Send Data module and added a Send Data To Error File module. The main() looks simple. Thank you.*/

/*Great start. I would prefer that all those output statements for the headings be in the Print Bill module. I try to keep main as simple as possible.*/

/* THE PROGRAM STRUCTURE:
                                          Main
                                            |
     -----------------------------------------------------------------------------
     |                          |                         |                      |
GetData               CalcIntExtCost         CalcTotalCostAndSendData    SendDataToErrorFile
Copy: None            Copy: intSqft          Copy: customerID             Copy: customerID      
                            intCostPerSqft         customerNum                  customerNum
Ref:  customerID            extSqft                intSqft                      intSqft
      customerNum           extCostPerSqft         intCostPerSqft               intCostPerSqft
      intSqft                                      extSqft                      extSqft
      intCostPerSqft  Ref:  intCost                extCostPerSqft               extCostPerSqft
      extSqft               extCost                intCost                      errorMsg
      extCostPerSqft                               extCost                             
      inFile                                       discount                Ref: errorFile
      isDataGood                                   totalCost                    isErrorFileEmpty
      errorMsg                                     
                                             Ref:  outFile
                                                   isOutputFileEmpty
*/ 

/* THE ALGORITHM:
  1. Set up variables for input file, output file, error file, customerID, customerNum,  
     intSqft, intCostPerSqft, extSqft, extCostPerSqft, intCost, extCost, discount, totalCost,   
     isDataGood and errorMsg.
  2. Open input.txt file and check the file is a good file.
  3. Open output.txt file.
  4. Use a while-loop to check the end of file.
  5. Call GetData() to read data from input file, check its validation,
  6. If it is not good data, open error.txt file (for the first time), and 
     call SendDataToErrorFile() to write the data and the reason causes the error to the error file. 
     Go to step 4.
  7. If it is good data, Call CalcIntExtCost() to calculate 
     the interior total cost and exterior total cost. 
  8. Call CalcTotalCostAndSendData() to calculte the discount and total cost. 
     Output the labels and write them to output.txt file (for the first time).
     Print out the bill. 
     Write all data (customer initials, customer account number, interior square feet, 
     cost per interior square feet, exterior square feet, cost per exterior square feet, 
     total interior cost, total exterior cost, any discount, and total cost) to the output file.
  9. Go to step 4 until the end of file.
 10. Close input.txt, output.txt, and error.txt(if exsits).
*/

/* The PSEUDOCODE:
   Purpose of the program:  
   This program that contains two or more functions calculates painting costs. 
   All data will be input from a file. Label and output all data to an output file. 
   If any data record contains an error, output the data to an error file with 
   a message indicating what caused the error.

   Input or given data: 
   input.txt   - the name of input file
   infile      - input file

   Processing:
   main() -
   infile.open("input.txt")
   if (!infile) 
      print error message and exit program.

   outFile.open("output.txt")

   while (!inFile.eof())
   {
     isDataGood = true
     errorMsg = ""
     GetData()
     if (isDataGood) 
     {
        CalcIntExtCost()
        CalcTotalCostAndSendData()       
     } 
     else 
     {
       if error file is not open
           errorFile.open("error.txt")
       SendDataToErrorFile()
     }
   }

   infile.close()
   outfile.close()
   error.close()

   GetData() - 
   customerID     = infile
   customerNum    = infile
   intSqft        = infile
   intCostPerSqft = infile
   extSqft        = infile
   extCostPerSqft = infile
   if it is not a good data  
      isDataGood = false
      errorMsg = The reason caused the error.

   CalcIntExtCost() -
   intCost = intSqft * intCostPerSqft;
   extCost = extSqft * extCostPerSqft;

   CalcTotalCostAndSendData() -
   if ((intCost + extCost) > 1000)
      discount = (intCost + extCost) * 0.1
   else 
      discount = 0
   totalCost = (intCost + extCost) - discount

   print "The bill in record:"
   outFile = ID Num intSqft intCostPerSqft extSqft extCostPerSqft 
             Interior cost Exterior cost Total Cost Discount

   print "Customer ID"   customerID
   print "Customer Num"  customerNum 
   print "Interior cost" intCost
   print "Exterior cost" extCost 
   print "Discount"      discount
   print "Total Cost"    totalCost
   print "-----------------------"

   outFile = customerID  customerNum  intSqft  intCostPerSqft intSqft  
             extCostPerSqft  intCost  extCost  discount  totalCost


   SendDataToErrorFile() -
   errorFile = Data error in record:
   errorFile = customerID customerNum intSqft intCostPerSqft extSqft extCostPerSqft
   errorFile = errorMsg    

   Output:
   output.txt - the name of output file
   error.txt  - the name of error file
*/

// Levi Hung
// Section 22855
// Lab 6B
// Day             : 04/19/23
// Time            : 02:00 PM
// This program calculate painting costs for customers of Top Quality Home Painting Service. 
// All data will be input from a file. Label and output all data to an output file. 
// If any data record contains an error, output the data to an error file with a message indicating what caused the error. 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void GetData(string &, int &, int &, float &, int &, float &, ifstream &, bool &, string &);
void CalcIntExtCost(int, float, int, float, float &, float &);
void CalcTotalCostAndSendData(string, int, int, float, int, float, float, 
                              float, float , float , ofstream &, bool &);

void SendDataToErrorFile(string, int, int, float, int, float, string, ofstream &, bool &);

int CS_116_Lab_6_Functions_Painting_Costs() 
{
  ifstream inFile;
  ofstream outFile; 
  ofstream errorFile; 

  bool   isErrorFileOpen;
  bool   isOutputFileEmpty;
  bool   isErrorFileEmpty;

  string customerID;
  int    customerNum;
  int    intSqft;
  float  intCostPerSqft;
  int    extSqft;
  float  extCostPerSqft; 
  bool   isDataGood;
  float  intCost;
  float  extCost;
  float  discount = 0.0;
  float  totalCost = 0.0;
  string errorMsg;

  isErrorFileOpen   = false;
  isOutputFileEmpty = true;
  isErrorFileEmpty  = true;

  inFile.open ("input.txt");
  if (!inFile)
  { 
     cout << "Cannot open file \"input.txt\", terminating program"<< endl;
     exit (1);
  }
  cout << "File \"input.txt\" opened successfully." << endl;

  outFile.open ("output.txt");
  cout << "File \"output.txt\" opened." << endl;

  while (!inFile.eof()) {
     isDataGood = true;
     errorMsg = "";

     GetData (customerID, customerNum, intSqft, intCostPerSqft, 
              extSqft, extCostPerSqft, inFile, isDataGood, errorMsg);

     if (isDataGood) {
        CalcIntExtCost(intSqft, intCostPerSqft, extSqft, extCostPerSqft, 
                       intCost, extCost);

        CalcTotalCostAndSendData(customerID, customerNum, intSqft, intCostPerSqft, 
                                  extSqft, extCostPerSqft, intCost, extCost, 
                                  discount, totalCost, outFile, isOutputFileEmpty);


     } else {
        if (!isErrorFileOpen) {
           isErrorFileOpen = true;
           errorFile.open ("error.txt");
        }

        SendDataToErrorFile(customerID, customerNum, intSqft, intCostPerSqft, extSqft, 
                          extCostPerSqft, errorMsg, errorFile, isErrorFileEmpty); 
     }
  }

  inFile.close();
  outFile.close();
  if (isErrorFileOpen == true) 
  {
      cout << "File \"error.txt\" opened." << endl;
      errorFile.close();
  }

  cout << "Process completed." << endl;

  return 0;  
}

void GetData(string & customerID, int & customerNum, 
             int & intSqft, float & intCostPerSqft, 
             int & extSqft, float & extCostPerSqft, 
             ifstream & inFile,
             bool & isDataGood, string & errorMsg) {
  string tmpMsg;

  inFile >> customerID;
  inFile >> customerNum;
  inFile >> intSqft;
  inFile >> intCostPerSqft;
  inFile >> extSqft;
  inFile >> extCostPerSqft;

  if (intSqft < 0) 
  {
     isDataGood = false;
     errorMsg = "interior Square Feet \"";    
     errorMsg += to_string(intSqft);
     errorMsg += "\" is negative. ";
  }

  if (intCostPerSqft < 0) 
  {
     isDataGood = false;
     errorMsg += "cost per interior square feet \"";
     tmpMsg    = to_string(intCostPerSqft);
     errorMsg += tmpMsg.substr(0, tmpMsg.find(".") + 3);
     errorMsg += "\" is negative. ";
  }

  if (intSqft > 0 && intCostPerSqft == 0)
  {
     isDataGood = false;
     errorMsg += "cost per interior square feet \"";
     tmpMsg    = to_string(intCostPerSqft);
     errorMsg += tmpMsg.substr(0, tmpMsg.find(".") + 3);
     errorMsg += "\" is zero. ";
  } 

  if (extSqft < 0)
  {
     isDataGood = false;
     errorMsg += "exterior square feet \"";
     errorMsg += to_string(extSqft);
     errorMsg += "\" is negative. ";
  } 

  if (extCostPerSqft < 0) 
  {
     isDataGood = false;
     errorMsg += "cost per exterior square feet \"";
     tmpMsg    = to_string(extCostPerSqft);
     errorMsg += tmpMsg.substr(0, tmpMsg.find(".") + 3);
     errorMsg += "\" is negative. ";
  } 

  if (extSqft > 0 && extCostPerSqft == 0) 
  {
     isDataGood = false;
     errorMsg += "cost per exterior square feet \"";
     tmpMsg    = to_string(extCostPerSqft);
     errorMsg += tmpMsg.substr(0, tmpMsg.find(".") + 3);
     errorMsg += "\" is zero. ";
  }
}

void CalcIntExtCost(int intSqft, float intCostPerSqft, int extSqft, 
                    float extCostPerSqft, float & intCost, float & extCost) 
{
  intCost = intSqft * intCostPerSqft;
  extCost = extSqft * extCostPerSqft;
}

void CalcTotalCostAndSendData(string customerID, int customerNum, int intSqft, 
                              float intCostPerSqft, int extSqft, float extCostPerSqft, 
                              float intCost, float extCost, float discount, 
                              float totalCost, ofstream & outFile, bool & isOutputFileEmpty) 
{
  if ((intCost + extCost) > 1000) 
  {
     discount = (intCost + extCost) * 0.1;
  } 
  else 
  {
     discount = 0;
  }
  totalCost = (intCost + extCost) - discount;

  if (isOutputFileEmpty) {
     isOutputFileEmpty = false;
     cout << fixed << setprecision(2);
     cout << "The bill in record:" << endl;

     outFile << fixed << setprecision(2);
     outFile << setw(5)  << "ID" << 
                setw(5)  << "Num" << 
                setw(8)  << "intSqft" << 
                setw(16) << "intCostPerSqft" << 
                setw(8)  << "extSqft" << 
                setw(16) << "extCostPerSqft" << 
                setw(16) << "Interior cost" << 
                setw(16) << "Exterior cost" << 
                setw(12) << "Discount" << 
                setw(12) << "Total Cost" << endl;
  }

  cout << setw(15) << left  << "Customer ID"   << 
          setw(8)  << right << customerID  << endl; 
  cout << setw(15) << left  << "Customer Num"  << 
          setw(8)  << right << customerNum << endl;
  cout << setw(15) << left  << "Interior cost" << 
          setw(8)  << right << intCost << endl; 
  cout << setw(15) << left  << "Exterior cost" << 
          setw(8)  << right << extCost << endl;
  cout << setw(15) << left  << "Discount"      << 
          setw(8)  << right << discount << endl;
  cout << setw(15) << left  << "Total Cost"    << 
          setw(8)  << right << totalCost << endl;
  cout << setw(23) << left  << "-----------------------" << endl;

  outFile << setw(5)  << customerID << 
             setw(5)  << customerNum << 
             setw(8)  << intSqft << 
             setw(16) << intCostPerSqft << 
             setw(8)  << intSqft << 
             setw(16) << extCostPerSqft << 
             setw(16) << intCost << 
             setw(16) << extCost << 
             setw(12) << discount << 
             setw(12) << totalCost << endl;
}

void SendDataToErrorFile(string customerID, int customerNum, int intSqft, 
                       float intCostPerSqft, int extSqft, float extCostPerSqft, 
                       string errorMsg, ofstream & errorFile, bool & isErrorFileEmpty) 
{
  if (isErrorFileEmpty) {
     isErrorFileEmpty = false;
     errorFile << fixed << setprecision(2);
     errorFile << "Data error in record: " << endl; 
  }

  errorFile << setw(3) << customerID     << " " << 
               setw(5) << customerNum    << " " <<
               setw(5) << intSqft        << " " << 
               setw(5) << intCostPerSqft << " " << 
               setw(5) << extSqft        << " " << 
               setw(5) << extCostPerSqft << ", ";

  errorFile << errorMsg << endl;       
}


/* Sample Run:
File "input.txt" opened successfully.
File "output.txt" opened.
The bill in record:
Customer ID         ABC
Customer Num       1234
Interior cost   1400.00
Exterior cost   4675.00
Discount         607.50
Total Cost      5467.50
-----------------------
Customer ID         DEF
Customer Num       1345
Interior cost    525.00
Exterior cost    550.00
Discount         107.50
Total Cost       967.50
-----------------------
Customer ID         GHI
Customer Num       2346
Interior cost   2000.00
Exterior cost      0.00
Discount         200.00
Total Cost      1800.00
-----------------------
Customer ID         JKL
Customer Num       4567
Interior cost   1500.00
Exterior cost    200.00
Discount         170.00
Total Cost      1530.00
-----------------------
Customer ID         PQR
Customer Num        679
Interior cost      0.00
Exterior cost    350.00
Discount           0.00
Total Cost       350.00
-----------------------
File "error.txt" opened.
Process completed.
*/