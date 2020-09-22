//
//  EECS402: Project1
//  Purpose: This program will implement functionality to accrue interest
//  for an investment account. Results of Initial balance, Interest
//  accrued every month and Final balance will be printed for every
//  months as well as the whole period
//
//  Created by Zijin Zhang (UMID: 40703833) on 9/16/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
using namespace std;
const double MINIMUM_INTEREST_RATE = 0.0015;
const double STANDARD_INTEREST_RATE = 0.00225;
const double MAXIMUM_INTEREST_RATE = 0.004;
const double LOW_BALANCE_LEVEL = 1000;
const double HIGH_BALANCE_LEVEL = 15000;
const double BALANCE_LOWER_BOUND = 0;
const int MONTH_LOWER_BOUND = 0;

//  Function: The function will accrue interest for the whole period.
//  The function will return true when input values are valid and can be
//  successfully calculated. Results of balance amount and interest
//  accrued will be printed for each month when requested.
bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    );

//  Function: The function will accrue interest for one month.
//  The funtion will return true when input balance amount is valid
//  and the interest can be successfully calculated. Results of balance
//  amount and interest accrued will be printed when requested.
bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             );

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
//  Main: Main will request user to enter initial balance amount, number of
//  months to accrued and whether the balance details are expected to be
//  printed for each month. Results of balance amount and interest accrued
//  for each month will be printed when requested. Results for whole period
//  will be printed when input values are valid.
int main(int argc, const char * argv[])
{
    double balanceAmt = 0;
    int numMonths = 1;
    char inputRequest = 'y';
    bool doPrintEachMonth = false;

    // request user to enter input intial balance and number of months
    cout << "Enter the initial balance of the account: ";
    cin >> balanceAmt;
    cout << "Enter the number of months to accrue interest: ";
    cin >> numMonths;
    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    cin >> inputRequest;

    if (inputRequest == 'y')
    {
        doPrintEachMonth = true;
    }

    double balanceAmtInitial = balanceAmt;
    bool isSuccessBuild = false;

    // Call the funnction accrueInterest()
    isSuccessBuild = accrueInterest(balanceAmt, numMonths, doPrintEachMonth);

    // Print the balance and interest for whole period when there is no error
    if (isSuccessBuild == true)
    {
        // Interested accrued is equal to final balance minus intial balance
        double interestAccrued = balanceAmt - balanceAmtInitial;

        cout << "Interest accrued for " << numMonths << " months!" << endl;
        cout << endl << "Initial balance: " << balanceAmtInitial << endl;
        cout << "Total interest accrued: " << interestAccrued << endl;
        cout << "Final balance: " << balanceAmt << endl;
    }

    return 0;
}
#endif


bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    )
{
    bool isSuccessful = false;  // value to return
    // Check if the input balance and number of months are valid
    if (balanceAmt < BALANCE_LOWER_BOUND || numMonths <= MONTH_LOWER_BOUND)
    {
        if (balanceAmt < BALANCE_LOWER_BOUND)
        {
            cout << "ERROR in accrueOneMonthsInterest:";
            cout << "balanceAmt must be >= 0, but the value ";
            cout << balanceAmt << " was provided!" << endl;
        }
        else
        {
            cout << "ERROR in accrueInterest: numMonths must be > 0, ";
            cout << "but the value " << numMonths << " was provided!" << endl;
        }
        cout << "Sorry, an error was detected. ";
        cout << "Unable to provide results!" << endl;
        return isSuccessful;
    }
    
    // Call the function accrueOneMonthsInterest() for each month
    for(int i = 0; i < numMonths; i++)
    {
        accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
    }
    
    isSuccessful = true;
    return isSuccessful;
}


bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             )
{
    bool isSuccessful = false;  // value to return
    
    // Check if the input balance amount is valid
    if (balanceAmt < BALANCE_LOWER_BOUND)
    {
        return isSuccessful;
    }
    
    double initialRate = 0;
    double interestAccrued = 0;
    
    // Initiate the interest rate according to the intial balance
    if (balanceAmt < LOW_BALANCE_LEVEL)
    {
        initialRate = MINIMUM_INTEREST_RATE;
    }
    else if (balanceAmt >= HIGH_BALANCE_LEVEL)
    {
        initialRate = MAXIMUM_INTEREST_RATE;
    }
    else
    {
        initialRate = STANDARD_INTEREST_RATE;
    }
    
    // Print the details when user requests
    if (doPrintInfo == true)
    {
        cout << "Accruing interest for 1 month:" << endl;
        cout << "  Initial balance: " << balanceAmt << endl;
        cout << "  Initial rate: " << initialRate << endl;
    }
    
    // Calculate interest accrued and add it to balance to update it
    interestAccrued = initialRate * balanceAmt;
    balanceAmt += interestAccrued;
    
    if (doPrintInfo == true)
    {
        cout << "  Interest accrued: " << interestAccrued << endl;
        cout << "  New balance: " << balanceAmt << endl;
    }

    isSuccessful = true;
    return isSuccessful;
}

