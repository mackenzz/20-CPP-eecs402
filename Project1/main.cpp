//
//  main.cpp
//  Project1
//
//  Created by Zijin Zhang on 9/16/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
using namespace std;
const double MINIMUM_INTEREST_RATE = 0.0015;
const double STANDARD_INTEREST_RATE = 0.00225;
const double MAXIMUM_INTEREST_RATE = 0.004;
const double LOW_BALANCE_LEVEL = 1000;
const double HIGH_BALANCE_LEVEL = 15000;

bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    );
bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             );


int main(int argc, const char * argv[])
{
    double initial_balanceAmt;
    int numMonths;
    char isPrint;
    bool doPrintEachMonth = false;
    
    cout << "Enter the initial balance of the account: ";
    cin >> initial_balanceAmt;
    cout << "Enter the number of months to accrue interest: ";
    cin >> numMonths;
    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    cin >> isPrint;
    
    if(isPrint == 'y')
    {
        doPrintEachMonth = true;
    }
    accrueInterest(initial_balanceAmt, numMonths, doPrintEachMonth);
    
    return 0;
}




bool accrueInterest(
                    double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
                    )
{
    double initial_balance = balanceAmt;
    for(int i = 0; i < numMonths; i++)
    {
        accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
    }
    double total_interest_accrued = balanceAmt - initial_balance;
    
    cout << "Interest accrued for " << numMonths << " months!" << endl << endl;
    cout << "Initial balance: " << initial_balance << endl;
    cout << "Total interest accrued: " << total_interest_accrued << endl;
    cout << "Final balance: " << balanceAmt << endl;
    
    return true;
}



bool accrueOneMonthsInterest(
                             double &balanceAmt,
                             const bool doPrintInfo
                             )
{
    if(balanceAmt < 0)
    {
        return false;
    }
    double initial_rate = 0;
    double interest_accrued = 0;
    
    if(balanceAmt < LOW_BALANCE_LEVEL)
    {
        initial_rate = MINIMUM_INTEREST_RATE;
    }
    else if(balanceAmt >= HIGH_BALANCE_LEVEL)
    {
        initial_rate = MAXIMUM_INTEREST_RATE;
    }
    else
    {
        initial_rate = STANDARD_INTEREST_RATE;
    }

    cout << "Accruing interest for 1 month:" << endl;
    cout << "  Initial balance: " << balanceAmt << endl;
    cout << "  Initial rate: " << initial_rate << endl;
    
    interest_accrued = initial_rate * balanceAmt;
    balanceAmt += interest_accrued;
    
    cout << "  Interest accrued: " << interest_accrued << endl;
    cout << "  New balance: " << balanceAmt << endl;

    return true;
}

