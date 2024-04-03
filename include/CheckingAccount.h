#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

using namespace std;

class CheckingAccount:public BankAccount
{
    public:
        CheckingAccount(double = 0.05, int = 0, string = ""); // Checking account Constructor
        void depositAmount(double);
        void withdrawAmount(double);
        void monthlyProcessing();
        void accountStatus();
        int getAccountNum();
        string getaccountname();
    private:
        int account_number;
        string account_name;
};

#endif // CHECKINGACCOUNT_H
