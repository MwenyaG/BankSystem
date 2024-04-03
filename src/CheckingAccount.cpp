#include <iostream>
#include <string>
#include "CheckingAccount.h"
// Checking account
using namespace std;

// derived class from Bankaccount
CheckingAccount::CheckingAccount(double rate, int acc_num, string name):BankAccount(rate){
    account_number = acc_num;
    account_name = name;
}

void CheckingAccount::depositAmount(double deposit){
    BankAccount::depositAmount(deposit);
}

void CheckingAccount::withdrawAmount(double withdraw){
    if((account_balance - withdraw) <0){
        account_balance -= 15;
        cout << "Withdraw Request was unsuccesful. A RM15.00 service charge was deducted from your total account balance.\n";
    }else{
        BankAccount::withdrawAmount(withdraw);
    }
}

void CheckingAccount::monthlyProcessing(){
    service_charges = 5 + 0.1*monthly_withdraws; // Calculates and set service charges
    BankAccount::monthlyProcessing();// calls the monthlyProcessing function
}

void CheckingAccount::accountStatus(){
    cout << "\n--------------------------------------------------\n"
         << "\t\tAccount Status\n\n"
         << "-  Account Type: Checking Account\n"
         << "-  Account Number: " << account_number << endl
         << "-  Account Holder Name: " << account_name << endl
         << "\n--------------------------------------------------\n";
}

int CheckingAccount::getAccountNum(){
    return account_number; // returns the account number
}

string CheckingAccount:: getaccountname(){
 return account_name;
}

