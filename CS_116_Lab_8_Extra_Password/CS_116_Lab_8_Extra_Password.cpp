// Levi Hung
// Section 22855
// Lab Extra cread--Password
// Day             : 05/17/23
// Time            : 09:00 AM
// This program checks whether user's password is good or bad.
// Password Policy:
// 1. It should be at least 8, but no more than 32 characters.
// 2. It should contain one uppercase letter.
// 3. It should contain one lowercase letter.
// 4. It should contain one number digit.
// 5. It should contain at least one special character.
// 6. 

#include <iostream>
#include <cctype>
using namespace std;

int CS_116_Lab_8_Extra_Password() 
{
  string pwdStr;
  const int MIN_LEN_PASSWORD = 8;
  const int MAX_LEN_PASSWORD = 32;
  bool isGoodPwd = false;
  char inputKey;
  string errorMsg;
  int i;
  int numUppercase;
  int numLowercase;
  int numDigit;
  int numSpecial;

  do {
      cout << "Enter your password: ";
      getline(cin, pwdStr);

      errorMsg = "";
      numUppercase = 0;
      numLowercase = 0;
      numDigit     = 0;
      numSpecial   = 0;

      if (pwdStr.length() < MIN_LEN_PASSWORD || 
          pwdStr.length() > MAX_LEN_PASSWORD)
      {
          isGoodPwd = false;
          errorMsg = "The password should be at least 8, but no more than 32 characters.\n";
      }  
      else 
      {
          for (i = 0; i < pwdStr.length(); i++)
          {
              if (isupper(pwdStr.at(i))) 
              {
                  numUppercase++;
              }
              else if (islower(pwdStr.at(i)))
              {
                  numLowercase++;                
              }
              else if (isdigit(pwdStr.at(i)))
              {
                  numDigit++;
              } 
              else
              {
                  numSpecial++;
              }
          }

          if ((numUppercase > 0) && 
              (numLowercase > 0) && 
              (numDigit     > 0) && 
              (numSpecial   > 0))
          {            
              isGoodPwd = true;
          }
          else 
          {
              if (numUppercase == 0) 
              {
                  errorMsg += "The password should contain one uppercase letter.\n";  
              }
              if (numLowercase == 0) 
              {
                  errorMsg += "The password should contain one lowercase letter.\n";  
              }
              if (numDigit == 0) 
              {
                  errorMsg += "The password should contain one number digit.\n";  
              }
              if (numSpecial == 0) 
              {
                  errorMsg += "The password should contain at least one special character.\n";  
              }

              isGoodPwd = false;
          }
      }

      cout << "Your Password \"" << pwdStr << "\" is "  << 
              (isGoodPwd? "good": "bad") << "."<< endl <<
              errorMsg << endl;

      cout << "Would you like to enter password again (Y/N):  ";
      cin >> inputKey;
      cin.ignore(200, '\n');
      cout << endl;
  } while (inputKey == 'Y' || inputKey == 'y');

  cout << "Goodbye!" << endl;
  return 0;
}

/* Sample Run:
Enter your password: abc
Your Password "abc" is bad.
The password should be at least 8, but no more than 32 characters.

Would you like to enter password again (Y/N):  y

Enter your password: abcEFG123.
Your Password "abcEFG123." is good.

Would you like to enter password again (Y/N):  y  

Enter your password: ABC123.,
Your Password "ABC123.," is bad.
The password should contain one lowercase letter.

Would you like to enter password again (Y/N):  y

Enter your password: abc123. 
Your Password "abc123. " is bad.
The password should contain one uppercase letter.

Would you like to enter password again (Y/N):  y

Enter your password: ABCdef./
Your Password "ABCdef./" is bad.
The password should contain one number digit.

Would you like to enter password again (Y/N):  y

Enter your password: ABCdef123
Your Password "ABCdef123" is bad.
The password should contain at least one special character.

Would you like to enter password again (Y/N):  n

Goodbye!
*/