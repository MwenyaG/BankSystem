#include <iostream>
#include "BankAccount.h"
#include <iomanip>// to set a fixed precision
#include <vector>// to store the amount of deposits


using namespace std;
vector <double> initialAccountBalance;
BankAccount::BankAccount(double rate){// Initializing BankAccount constructor
    account_balance = 0;
    annualRate = rate;
    total_deposits = 0;
    total_withdraws = 0;
    monthly_deposits = 0;
    monthly_withdraws = 0;
    service_charges = 0;
}

void BankAccount::depositAmount(double amount){
    initialAccountBalance.push_back(account_balance); // push_bank function is required to push the elements into the vector
    account_balance += amount;
    accountbalance.push_back(account_balance);
    depositcash.push_back(amount);
    withdrawcash.push_back(0);
    total_deposits += 1;
    monthly_deposits += 1;
    cout << "The Money has Successfully been deposited into your account.\n";
}

void BankAccount::withdrawAmount(double amount)
    {
    initialAccountBalance.push_back(account_balance);
    if(amount > account_balance)
    {
     cout << " Your Withdraw Request has been denied due to Insufficient Account funds.\n";
    }
    else{
        account_balance -= amount;
        accountbalance.push_back(account_balance);
        withdrawcash.push_back(amount);
        depositcash.push_back(0);
        total_withdraws += 1;
        monthly_withdraws += 1;
        cout << "Your Withdrawal request was Successful.\n";
    }
}

void BankAccount::calculateInterest(){
    double monthlyRate = annualRate/12;
    account_balance += account_balance * monthlyRate;
}

//the monthlyProcessing function subtracts service charges from the account balance
void BankAccount::monthlyProcessing(){
    account_balance -= service_charges;
    calculateInterest();
    getMonthlyStatistics();
    monthly_deposits = 0;
    monthly_withdraws = 0;
}

void BankAccount::getMonthlyStatistics(){
    cout << setprecision(2) << fixed;
    cout << "\n____________________________________________________\n"
         << "\t\tMonthly Statistics\n\n"
         << "  Account Balance: RM" << account_balance << endl
         << "  Number of Deposits this month: " << monthly_deposits << endl
         << "  Number of Withdrawals this month: " << monthly_withdraws << endl
         << "\n  Total Deposits: " << total_deposits << endl
         << "  Total Withdrawals: " << total_withdraws << endl;
    cout << "________________________________________________________" <<endl;
    cout << "\t\t Monthly Statistics flow \n\n";
    cout << "Account Balance \t" << "Withdraws\t" << "Deposits"<<endl;
            for(int x=0;x < total_deposits+total_withdraws;++x){
    cout << accountbalance[x] << "                  " << withdrawcash[x] << "                 " << depositcash[x] <<endl;
            }
    cout << "This is a computer generated statement";
    cout << "\n_____________________________________________________\n";
}
