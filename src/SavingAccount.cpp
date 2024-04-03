#include <iostream>
#include "SavingAccount.h"

using namespace std;

string showStatus(bool);

const int SERVICE_CHARGE = 1;

// Derived Class of Base Class BankAccount
SavingAccount::SavingAccount(double rate, int accNum, string name)
:BankAccount(rate){
    if(account_balance > 25) active = true;
    else active = false;
    withdrawsWithFees = 0;
    accountNum = accNum;
    accountName = name;
}

void SavingAccount::depositAmount(double amount){
    if(active) BankAccount::depositAmount(amount);
    else{
        BankAccount::depositAmount(amount);
        if(account_balance > 25){
            cout << "Your Account was Activated successfully!.\n";
            active = true;
        }
        else active = false;
    }
}

void SavingAccount::withdrawAmount(double amount){
    if(active){
        BankAccount::withdrawAmount(amount);
        if(monthly_withdraws > 4 && amount >= 4 && amount <= account_balance){
            withdrawsWithFees++;
        }
        if(account_balance> 25) active = true;
        else{
            cout << "Warning! Your Account has been Frozen. Account Balance is below the standard RM20.00.\n"
                 << "You will not be able to perform any withdrawal request until RM20.00 is deposited into account.\n";
            active = false;
        }
    }else{
        cout << "Your Account is Inactive! Unable to Proceed with Request.\n";
    }
}

void SavingAccount::monthlyProcessing(){
    if(monthly_withdraws > 4){
        service_charges = SERVICE_CHARGE * withdrawsWithFees; // Calculates and set service charges
        BankAccount::monthlyProcessing(); // calls the monthly processing function
        if(account_balance > 25) active = true;
        else{
            cout << "Warining! your Account has been Frozen. Your account balance is not exceeding RM20.00.\n"
                 << "You will not be able to perform any withdrawal request until RM20.00 is deposited into account.\n";
            active = false;
        }
    }else{
        BankAccount::monthlyProcessing(); // Process + Interest Rate
        if(account_balance > 25) active = true;
        else active = false;
    }
    withdrawsWithFees = 0; // Resets monthly withdraw amount of charge-able fees (Above RM4 and after 4 withdraws)
}

void SavingAccount::accountStatus(){
    cout << "\n--------------------------------------------------\n"
         << "\t\tAccount Status\n\n"
         << "-  Account Type: Saving Account\n"
         << "-  Account Number: " << accountNum << endl
         << "-  Account Holder-Name: " << accountName << endl
         << "-  Account Status: " << showStatus(active) << endl
         << "\n--------------------------------------------------\n";
}

int SavingAccount::getAccountNum(){
    return accountNum;
}
string SavingAccount:: getaccountname(){
 return accountName;
}
string showStatus(bool condition){
    if(condition) return "Active";
    else return "Inactive (Frozen)";
}

