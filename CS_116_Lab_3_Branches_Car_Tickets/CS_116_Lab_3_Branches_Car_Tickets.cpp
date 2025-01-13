/*Professor, Why did I add getline() after cin(carNum) and cin.get(carType)? Because I want to check the redundancy of input, such as carNum is 1a or carType is Cc. I think I can check the redundancy until next input. So I've already removed them.*/

/*Again, you have overly complicated the problem.  Lines 218 thru 227 don't work.  Note that I added a debug line (Me  Me) to show you that the getline gets NOTHING.  Also, I think lines 175 to 180 is overkill.  I would remove these and just check for C, c, T, t.....etc. in the program.*/

/* Professor, I added some error numbers in my program when somebody gave bad data. */

/* Professor, I simplified my program. I have a question. 
If somebody gave bad data and the program printed some error messages, should the main function return an error number? */

/*This program works, but you have overly complicated the problem.  Using getline and .size to take in simple numbers does not buy you much.  A simple cin with a check for numbers between 0 and 16 would do the same job at much less code.  Try to see if you can simplify this program.*/

#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

/* THE ALGORITHM:
  1. Set up variables for car number, car type, parking hours, parking minutes, 
     total parking hours, and total charge.
  2. Set up constant characters for car, truck and senior citizen.
  3. Set up constant variables for 
     Short-term  maximun parking hours           (2 hours for cars and trucks),
     Medium-term maximum parking hours for cars  (5 hours for cars)
     Medium-term maximum parking hours for trucks(4 hours for trucks)
     Long-term   maximum parking hours           (16 hours for cars and trucks),
     Short-term  charge                          (it's free for cars and trucks),
     Medium-term charging rate for cars          ($1.00 per hour),
     Long-term   charging rate for cars          ($0.50 per hour),
     Medium-term charging rate for trucks        ($2.00 per hour),
     Long-term   charging rate for trucks        ($1.00 per hour),
     Medium-term maximum charge for cars         ($3.00),
     Medium-term maximum charge for trucks       ($4.00),
     Charge for senior citizens                  (it's free),
     and over minutes full hour                  (any minutes over 30 is a full hour), 
  4. Ask the user for car number and store it.
     If user enter invalid car number, 
     the program outputs "Error! Invalid car number." and exit.
  5. Ask the user for car type (C - Car, T: Truck, or S - Senior citizen) and store it.
     If user enter invalid car type, 
     the program outputs "Error! Invalid rate designation." and exit.
  6. Ask the user for parking hours and minutes and store it.
     If user enter invalid hours and minutes, 
     The program outputs "Error! Invalid parking hours and minutes." and exit.
  7. Determine whether the vehicle was not parked more than 16 hours.
     If the parking hours is greater than 16 hours or 
     the parking hours is equal to 16 hours and parking minutes is greater than 0, 
     The program outputs "Error! Invalid parking hours" and exit. 
  8. Calculate the total parking number of hours.
     If the parking minutes is greater than 30,
     total parking hours = parking hours + 1.
     Otherwise total parking hours = parking hours.
  9. Calculate the total charge when the car type is senior citizens, 
     total charge is 0.
 10. Calculate the total charge when the car type is car. 
     If the total parking hours is small than or equal to 2, 
     total charge = 0;
     If the total parking hours is small than or equal to 5,
     total charge = (total parking hours - 2) * medium-term charging rate for cars
     otherwise, 
     total charge = Medium-term maximum charge for cars + 
                    (total parking hours - 5) * long-term charging rate for cars
 11. Calculate the total charge when the car type is truck. 
     If the total parking hours is small than or equal to 2, 
     total charge = 0;
     If the total parking hours is small than or equal to 4,
     total charge = (total parking hours - 2) * medium-term charging rate for trucks
     otherwise, 
     total charge = Medium-term maximum charge for cars + 
                    (total parking hours - 4) * long-term charging rate for trucks
 12. Output car number, rate designation, hours, minutes and total charge. 
*/

/* The PSEUDOCODE:
   Purpose of the program:  
   Computes the charges for each vehicle that uses the Pentagon Parking lot during the day.

   Input or given data: 
   carNum     - car number, 
   carType    - rate designation, 
   parkingHrs - parking hours, 
   parkingMin - parking hours,

   Processing: 
   Delcare all variables.

   cin(carNum)
   if (carNum < 0 || carNum != digit)
      print "Error! Invalid car number." and exit.

   cin.get(carType)
   if (carType != "C" or "c" or "T" or "t" or "S" or "s")
      print "Error! Invalid rate designation." and exit

   cin(parkingHrs)
   cin(parkingMin)
   if (parkingHrs < 0 || parkingMin < 0 || parkingHrs != digit || parkingMin != digit)
      print "Error! Invalid parking hours and minutes." and exit

   parkingHrs += parkingMin / 60
   parkingMin  = parkingMin % 60
   if ((parkingHrs > 16) || ((parkingHrs == 16) && (parkingMin > 0)))
      print "Error! Invalid parking hours." and exit

   if (parkingMin > 30)
      totalParkingHrs = parkingHrs + 1
   else
      totalParkingHrs = parkingHrs

   if (carType == "S" or "s")
      totalCharge = 0
   else if (carType == "C" or "c"))
      if (totalParkingHrs <= 2)
         totalCharge = 0
      else if (totalParkingHrs <= 5)
         totalCharge = (totalParkingHrs - 2) * 1.00
      else
         totalCharge = (5 - 2) * 1.00 + (totalParkingHrs - 5) * 0.50
   else
      if (totalParkingHrs <= 2)
         totalCharge = 0
      else if (totalParkingHrs <= 4)
         totalCharge = (totalParkingHrs - 2) * 2.00
      else
         totalCharge = (4 - 2) * 2.00 + (totalParkingHrs - 4) * 1.00

   print "**********************************" 
   print "Car No.                     carNum"
   print "Rate designation           carType"     
   print "Hours                   parkingHrs"
   print "Minutes                 parkingMin"
   if (totalCharge == 0) 
      print "Your total charge is free."
   else 
      print "Your total charge is $totalCharge."

   Output:
   ********************************** 
   Car No.                     carNum
   Rate designation           carType     
   Hours                   parkingHrs
   Minutes                 parkingMin

   Your total charge is free.
   or 
   Your total charge is $totalCharge.
   or
   Error! Invalid car number.
   or
   Error! Invalid rate designation.
   or
   Error! Invalid parking hours and minutes.
   or 
   Error! Invalid parking hours.      
*/

// Levi Hung
// Section 22855
// Lab 3
// Due Date        : 03/12/23
// Day             : 03/01/23
// Time            : 11:50 PM
// Program listing : input.txt
// Program output  : output.txt
// This program computes the charges for each vehicle that uses the Pentagon Parking lot during the day.

int CS_116_Lab_3_Branches_Car_Tickets() {
  int carNum;
  char carType;
  int parkingHrs;
  int parkingMin; 
  int totalParkingHrs;
  string inputExtraStr;
  string carTypeStr;

  float totalCharge;

  const int SHORT_TERM_MAX_PARKING_HOURS        = 2;
  const int MEDIUM_TERM_MAX_PARKING_HOURS_CAR   = 5;
  const int MEDIUM_TERM_MAX_PARKING_HOURS_TRUCK = 4;
  const int LONG_TERM_MAX_PARKING_HOURS         = 16;
  const float MEDIUM_TERM_MAX_CHARGE_CAR      = 3.0; // (5 - 2) * 1.0;
  const float MEDIUM_TERM_MAX_CHARGE_TRUCK    = 4.0; // (4 - 2) * 2.0;
  const float MEDIUM_TERM_CHARGING_RATE_CAR   = 1.00;
  const float LONG_TERM_CHARGING_RATE_CAR     = 0.50;
  const float MEDIUM_TERM_CHARGING_RATE_TRUCK = 2.00;
  const float LONG_TERM_CHARGING_RATE_TRUCK   = 1.00;
  const float SHORT_TERM_CHARGE               = 0.00;
  const float CHARGE_SENIOR                   = 0.00;
  const int OVER_MINUTES_FULL_HOUR            = 30;
  const int MINUTES_PER_HOUR                  = 60;

  const int ERROR_NUMBER_INVALID_DATA        = -1;
  const int ERROR_NUMBER_NEGTIVE_INTEGER     = -2;
  const int ERROR_NUMBER_OVER_TIME_PARKING   = -3;

  cout << "Enter car number: ";
  cin >> carNum;
  if (cin.fail() == true) 
  {
    cout << "Error! Invalid car number. " << endl 
         << "A car number must be a positive integer." << endl;
    return ERROR_NUMBER_INVALID_DATA;
  }
  else if (carNum < 0) 
  {
    cout << "Error! " << "(" << carNum << 
            ") is invalid car number." << endl <<
            "A car number must be a positive integer." << endl;
    return ERROR_NUMBER_NEGTIVE_INTEGER;
  }

  cout << "Enter rate designation (C - Car, T - Truck, or S - Senior citizen): ";
  cin >> carType;
  if ((carType != 'C') && (carType != 'c') && (carType != 'T') && 
      (carType != 't') && (carType != 'S') && (carType != 's')) {
        cout << "Error! (" << carType << 
                ") is invalid rate designation. " << endl <<
                "The rate designation must be C, T, or S." << endl;
        return ERROR_NUMBER_INVALID_DATA;
    }

  cout << "Enter Parking hours and minutes (separated by space): " ;
  cin >> parkingHrs;
  cin >> parkingMin;
  if (cin.fail() == true)
  {
     cout << "Error! " << "Invalid parking hours and minutes. " << endl <<
             "Parking hours and minutes must be a positive integer separated by space." << endl;
     return ERROR_NUMBER_INVALID_DATA;

  } else if ((parkingHrs < 0) || (parkingMin < 0))   { 
     cout << "Error! " << "(" << parkingHrs << " " << parkingMin << 
            ") is invalid parking hours and minutes." << endl <<
             "Parking hours and minutes must be a positive integer separated by space." << endl;
     return ERROR_NUMBER_NEGTIVE_INTEGER;
  }

  parkingHrs += parkingMin / MINUTES_PER_HOUR;
  parkingMin  = parkingMin % MINUTES_PER_HOUR;

  if ((parkingHrs > LONG_TERM_MAX_PARKING_HOURS) || 
      ((parkingHrs == LONG_TERM_MAX_PARKING_HOURS) && (parkingMin > 0))) {
     cout << "Error! " << "(" << parkingHrs << " " << parkingMin << 
             ") is invalid parking hours." << endl <<
             "A car may not be parked more than 16 hours." << endl;   
     return ERROR_NUMBER_OVER_TIME_PARKING;
  }

  if (parkingMin > OVER_MINUTES_FULL_HOUR) 
  {
     totalParkingHrs = parkingHrs + 1;  
  } 
  else 
  {
     totalParkingHrs = parkingHrs;
  }

  if ((carType == 'S') || (carType == 's')) 
  {
    totalCharge = CHARGE_SENIOR;
    carTypeStr  = "Senior citizen";
  }
  else if ((carType == 'C') || (carType == 'c')) 
  {
     if (totalParkingHrs <= SHORT_TERM_MAX_PARKING_HOURS) 
     {
        totalCharge = SHORT_TERM_CHARGE;
     } 
     else if (totalParkingHrs <= MEDIUM_TERM_MAX_PARKING_HOURS_CAR) 
     {
        totalCharge = (totalParkingHrs - SHORT_TERM_MAX_PARKING_HOURS) *
                      MEDIUM_TERM_CHARGING_RATE_CAR;
     } 
     else 
     {
        totalCharge = MEDIUM_TERM_MAX_CHARGE_CAR + 
                      (totalParkingHrs - MEDIUM_TERM_MAX_PARKING_HOURS_CAR) * 
                      LONG_TERM_CHARGING_RATE_CAR;
     }
     carTypeStr  = "Car";
  }
  else 
  {
     if (totalParkingHrs  <= SHORT_TERM_MAX_PARKING_HOURS) 
     {
        totalCharge = SHORT_TERM_CHARGE;
     } 
     else if (totalParkingHrs <= MEDIUM_TERM_MAX_PARKING_HOURS_TRUCK) 
     {
        totalCharge = (totalParkingHrs - SHORT_TERM_MAX_PARKING_HOURS) *
                      MEDIUM_TERM_CHARGING_RATE_TRUCK;
     } 
     else 
     {
        totalCharge = MEDIUM_TERM_MAX_CHARGE_TRUCK +
                      (totalParkingHrs - MEDIUM_TERM_MAX_PARKING_HOURS_TRUCK) * 
                      LONG_TERM_CHARGING_RATE_TRUCK;
     }
     carTypeStr  = "Truck";

  }

  /* Output */
  cout << setw(35) << setfill('*') << "" << endl;
  cout << setfill(' ');

  cout << fixed << setprecision (2);
  cout << setw(20) << left  << "Car number";
  cout << setw(15) << right << carNum << endl;

  cout << setw(20) << left  << "Rate designation";
  cout << setw(15) << right << carTypeStr << endl;
  cout << setw(20) << left  << "Parking hours";
  cout << setw(15) << right << parkingHrs << endl;
  cout << setw(20) << left  << "Parking minutes";
  cout << setw(15) << right << parkingMin << endl << endl;


  if (totalCharge == 0)
  {
    cout << "Your total charge is free." << endl;
  }
  else
  {
     cout << "Your total charge is $" << totalCharge << "." << endl;

  }

  return 0;
}
/*
Sample Run 1:
Enter car number: 1
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): C
Enter Parking hours and minutes (separate by space): 4 45
***********************************
Car number                        1
Rate designation                Car
Parking hours                     4
Parking minutes                  45

Your total charge is $3.00.

Sample Run 2:
Enter car number: 2
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): C
Enter Parking hours and minutes (separate by space): 0 35
***********************************
Car number                        2
Rate designation                Car
Parking hours                     0
Parking minutes                  35

Your total charge is free.

Sample Run 3:
Enter car number: 3
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): C
Enter Parking hours and minutes (separate by space): 8 15
***********************************
Car number                        3
Rate designation                Car
Parking hours                     8
Parking minutes                  15

Your total charge is $4.50.

Sample Run 4:
Enter car number: 4
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): T
Enter Parking hours and minutes (separate by space): 2 10
***********************************
Car number                        4
Rate designation              Truck
Parking hours                     2
Parking minutes                  10

Your total charge is free.

Sample Run 5:
Enter car number: 5
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): T
Enter Parking hours and minutes (separate by space): 10 32
***********************************
Car number                        5
Rate designation              Truck
Parking hours                    10
Parking minutes                  32

Your total charge is $11.00.

Sample Run 6:
Enter car number: 6
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): S
Enter Parking hours and minutes (separate by space): 5 20
***********************************
Car number                        6
Rate designation     Senior citizen
Parking hours                     5
Parking minutes                  20

Your total charge is free.

Sample Run 7:
Enter car number: 7
Enter rate designation (C - Car, T - Truck, or S - Senior citizen): C
Enter Parking hours and minutes (separate by space): 20 0
Error! (20 0) is invalid parking hours.
A car may not be parked more than 16 hours.
exit status 253
*/
