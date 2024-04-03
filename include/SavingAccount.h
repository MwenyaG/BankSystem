#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "BankAccount.h"

using namespace std;

class SavingAccount:public BankAccount
{
    public:
        SavingAccount(double = 0.05, int = 0, string = ""); // Constructor
        void depositAmount(double);
        void withdrawAmount(double);
        void monthlyProcessing();
        void accountStatus();
        int getAccountNum();
        string getaccountname();

    private:
        bool active;
        int withdrawsWithFees, accountNum;
        string accountName;
};

#endif // SAVINGACCOUNT_H
