#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <vector>

class BankAccount
{
    public:
        BankAccount(double = 0.05); // Constructor
        virtual void depositAmount(double); // declaration of virtual depositAmount function so that it can be overloaded and accessed by other derived classes
        virtual void withdrawAmount(double);// declaration of virtual withdrawAmount function so that it can be overloaded and accessed by other derived classes
        virtual void calculateInterest();
        virtual void monthlyProcessing();// calculates monthly process function
        void getMonthlyStatistics();

    protected:
        int total_deposits, total_withdraws, monthly_deposits, monthly_withdraws; // declaration of interger variables
        double account_balance, annualRate, service_charges; // declaration of service charges
        std::vector <double> depositcash,withdrawcash,accountbalance;
};

#endif // BANKACCOUNT_H
