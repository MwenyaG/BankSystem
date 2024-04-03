// Bank account system
#include <iostream>
#include "BankAccount.h" // Header for BankAccount
#include "SavingAccount.h" // Saving account class SavingAccount functionality
#include "CheckingAccount.h" // Checking account class for CheckingAccount functionality
#include <time.h>//to let the program sleep for a period of time
#include <vector> // To function as a vector array


using namespace std;

//Interface functions
int checkingvalidity(int, int, int);// checks if variable input is correct
void depositToAccount(); // when called allows user to deposit funds
void withdrawFromAccount();// when call it allows the user to withdraw funds from account
void showAllAccount();
void sim_Monthlyprocessing();
void createAccount();// creates a bank account to be saved in vector
void showAccountStatus();// displays the Account status either active or unactive
void Mainmenu();// displays the main menu
void subMenu();// Displays the submenu

void delay();// delay function to make the program sleep for some time

// initialization of vectors to save account details
vector<SavingAccount> s_accounts; // this vector stores all the saving account details
vector<CheckingAccount> c_accounts; // this vector stores all the checking account details

int main()
{
    //initialize two accounts saving and checking account and save them into vectors.
    SavingAccount demo_saving_account(0.05, 123456, "Pearly Teoh");
    s_accounts.push_back(demo_saving_account);
    CheckingAccount demo_checking_account(0.05, 111111, "Chen Jia");
    c_accounts.push_back(demo_checking_account);

    // Starts by calling the mainmenu
    Mainmenu();

    return 0;
}
// this function creates a time delay
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

// Function that validates input contains integer and is within the given range attribute
int checkingvalidity(int input, int beginRange, int endRange){
    cin >> input;
    if(input > endRange || input < beginRange){
        cin.clear();
       cout << "Invalid Input! Please Try Again after two seconds. ";
       delay(2);
       return 0;
    }else
    {
    return input; // returns the input value (int)
    }
}

// Function that generates the main menu form, allow users to interact with
void Mainmenu(){
    int input;

    system("CLS"); // Clear Console Screen
    cout << " _______________________________________________________\n"
         << "|\t\tWelcome to TAM Bank                     |\n"
         << "|_______________________________________________________|\n";
    cout << "|   Main Menu                                           |\n"
         << "|1. Check Account Status                                |\n"
         << "|2. Create New Account                                  |\n"
         << "|3. Deposit                                             |\n"
         << "|4. Withdraw                                            |\n"
         << "|5. Show All Existing Accounts                          |\n"
         << "|6. Monthly Processing and statistics (All Accounts)    |\n"
         << "|7. Exit                                                |\n"
         << "|_______________________________________________________|\n"
         << "                                 Enter your Option here:";
    input = checkingvalidity(input, 1, 7);
    switch(input){
        case 1:
            showAccountStatus();
        break;
        case 2:
            createAccount();
        break;
        case 3:
            depositToAccount();
        break;
        case 4:
            withdrawFromAccount();
        break;
        case 5:
            showAllAccount();
        break;
        case 6:
            sim_Monthlyprocessing();
        break;
        case 7:
            cout << "\nThank you. Have a great day.\n";
            return;
        break;
        default:
            cout << "The the option you entered is invalid"<<endl;
            cout << "please try again after 2 seconds, you will be returned to the main menu. \n";
            delay(2);
            Mainmenu();
    }
}

// Function that allows user to return to the main menu or exit the program. Placed at the end of each sub menu
void subMenu(){
    int input;
    cout << "\nSelect an Option\n"
         << "1. Return to Main Menu\n"
         << "2. Exit\n\nOption: ";
    input = checkingvalidity(input, 1, 2);
    if(input == 1){
      Mainmenu();
    } else if(input == 0){
    subMenu();
    }
    else if(input == 2){
        cout << "\nThank you. Have a great day.\n";
        return;
    }
}

// Function that shows the account status of a specified account
void showAccountStatus(){
    // Local variable
    int num, type;
    bool found = false;

    system("CLS"); // Clear Console Screen
    cout << " _______________________________________________________\n"
         << "|\t\t Account Status                         |\n"
         << "|_______________________________________________________|\n";

    do{
    cout << "|Select from the following Account Type:                |\n"
         << "| 1. Saving status                                      |\n"
         << "| 2. Checking status                                    |\n"
         << "| 3. Return to Main Menu                                |\n"
         << "|_______________________________________________________|\n";
    cout << "                                      Enter your Option: ";
        type = checkingvalidity(type, 1, 3);
        if(type == 3){ // Returns to main menu, exit current function
            Mainmenu();
            return;
        }else if (type == 0){
        showAccountStatus();
        }
        cout << "Enter Your Account Number: ";
        num = checkingvalidity(num, 100000, 999999);
        if(num == 0){
            showAccountStatus();
        }
        if(type == 1){ // Saving Account
            for(int i = 0; i < s_accounts.size(); i++){ // Loops through vector of Saving accounts
                if(s_accounts[i].getAccountNum() == num){ // Account number matches
                    found = true;
                    s_accounts[i].accountStatus();
                    s_accounts[i].getMonthlyStatistics();
                    break;
                };
            }
        }else if(type == 2){ // Checking Account
            for(int i = 0; i < c_accounts.size(); i++){ // Loops through vector of Checking accounts
                if(c_accounts[i].getAccountNum() == num){
                    found = true;
                    c_accounts[i].accountStatus();
                    c_accounts[i].getMonthlyStatistics();
                    break;
                };
            }
        }
        if(!found){ // Error handling if no account is found
            cout << "Unable to locate a valid Account. Please Try Again.\n";
        }
    }while(!found); // Loop if no account is found, ask user for new input until account is found

    subMenu();
}

// Function to create a new Saving or Checking Account
void createAccount(){
    // Local variable
    int type, num;
    double amount;
    string name;

    // Local Function Declaration
    bool isSavingAccExist(int);
    bool isCheckingAccExist(int);

    system("CLS"); // Clear Console Screen
    cout << " _______________________________________________________ \n"
         << "|\tCreate New Account                              |\n"
         << "|_______________________________________________________|\n";

    cout << "|Select from the following Account Type:                |\n"
         << "| 1. Create Savings account                             |\n"
         << "| 2. Create Checking account                            |\n"
         << "| 3. Return to Main Menu                                |\n"
         << "|_______________________________________________________|\n";
    cout << "                                      Enter your Option: ";
    type = checkingvalidity(type, 1, 3);
    if(type == 3){ // Returns to menu, exit current function
        Mainmenu();
        return;
    }else if(type == 0){
    createAccount();
    }
    cout << "Enter Account Number (100000 - 999999): ";
    do{
        if(isSavingAccExist(num) || isCheckingAccExist(num))
      cout << "Error! An Account with that number already exist! Please Try Again.\nEnter Account Number (100000 - 999999): ";
        num = checkingvalidity(num, 100000, 999999);
        if(num == 0){
            createAccount();
        }
    }while(isSavingAccExist(num) || isCheckingAccExist(num));
    cout << "Enter Account Holder Name: ";
    cin >> name;
    while(cin.get() != '\n') continue;

    if(type == 1){ // Saving Account
        SavingAccount s_account(0.05, num, name); // Create a new SavingAccount class object
        cout << "You have Successfully Created A savings account!\n";
        cout << "A minimum deposit of RM25.00 is required in order to activate the account.\n";
        cout << "Enter Deposit Amount (min RM25.00): RM";
        while(!(cin >> amount) || amount <= 25){ // Input validation for Deposit Amount
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Invalid Input! Amount must be over RM25.00. Please Try Again.\nAmount: RM";
        }
        s_account.depositAmount(amount);
        s_accounts.push_back(s_account); // Push object to the vector array which stores all Saving Account
    }else{ // Checking Account
        CheckingAccount c_account(0.05, num, name); // Create a new CheckingAccount class object
        cout << "Checking Account Successfully Created!\n";
        cout << "Deposit any amount to activate the account.\n";
        cout << "Enter Deposit Amount: RM";
        while(!(cin >> amount) || amount < 0){ // Input validation for Deposit Amount
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Invalid Input! Please Try Again.\nAmount: RM";
        }
        c_account.depositAmount(amount);
        c_accounts.push_back(c_account); // Push object to the vector array which stores all Checking Account
    }

    subMenu();//calls subMenu
}

// Function that identifies whether a saving account exist (from vector array in this case)
bool isSavingAccExist(int input){
    for(int i = 0; i < s_accounts.size(); i++){
        if(s_accounts[i].getAccountNum() == input) return true; // returns true if found Saving Account with the same number
    }
    return false;
}

// Function that identifies whether a checking account exist (from vector array in this case)
bool isCheckingAccExist(int input){

    for(int i = 0; i < c_accounts.size(); i++){
        if(c_accounts[i].getAccountNum() == input) return true; // returns true if found Checking Account with the same number
    }
    return false;
}

// Function that allows user to deposit funds into the specified account
void depositToAccount(){
    // Local variable
    int type, num;
    string name;
    double amount;
    bool found = false;

    system("CLS"); // Clear Console Screen
    cout << " _______________________________________________________ \n"
         << "|\t\tDeposit                                 |\n"
         << "|_______________________________________________________|\n";

    do{
    cout << "|Select from the following Account Type:                |\n"
         << "| 1. Deposit into Saving account                        |\n"
         << "| 2. Deposit into Checking account                      |\n"
         << "| 3. Return to Main Menu                                |\n"
         << "|_______________________________________________________|\n";
    cout << "                                      Enter your Option: ";
        type = checkingvalidity(type, 1, 3);
        if(type == 3){ // Returns to menu, exit current function
            Mainmenu();
            return;
        } else if(type == 0){
        depositToAccount();
        }
        cout << "Enter Your Account Number: ";
        num = checkingvalidity(num, 100000, 999999);
        cout << "Enter Account Title :";
        cin >> name;
        if(num == 0){
            depositToAccount();
        }
        if(type == 1){ // Saving Account
            for(int i = 0; i < s_accounts.size(); i++){
                if(s_accounts[i].getaccountname() == name){
                if(s_accounts[i].getAccountNum() == num){
                    found = true;
                    cout << "Enter Deposit Amount: RM";
                    while(!(cin >> amount) || amount < 0){ // Input validation for amount, ensure it is not negative value
                        cin.clear();
                        while(cin.get() != '\n') continue;
                        cout << "Invalid Input! Please Try Again.\nAmount: RM";
                    }
                    s_accounts[i].depositAmount(amount);
                    break;
                };
                }

            }

        }else{ // Checking Account
            for(int i = 0; i < c_accounts.size(); i++){
                if(c_accounts[i].getaccountname() == name){
                if(c_accounts[i].getAccountNum() == num){
                    found = true;
                    cout << "Enter Deposit Amount: RM";
                    while(!(cin >> amount) || amount < 0){ // Input validation for amount, ensure it is not negative value
                        cin.clear();
                        while(cin.get() != '\n') continue;
                        cout << "Invalid Input! Please Try Again.\nAmount: RM";
                    }
                    c_accounts[i].depositAmount(amount);
                    break;
                };
                }

            }
        }
        if(!found){
            cout << "Unable to locate a valid Account. Please Try Again.\n";
        }
    }while(!found);

    subMenu();
}

// Function that allows user to withdraw funds from the specified account
void withdrawFromAccount(){
    // Local variable
    int type, num;
    string name;
    double amount;
    bool found = false;

    system("CLS"); // Clear Console Screen
    cout << " _______________________________________________________\n"
         << "|\t\tWithdraw Fund(s)                        |\n"
         << "|_______________________________________________________|\n";

    do{
    cout << "|Select from the following Account Type:                |\n"
         << "| 1. Withdraw from Saving account                       |\n"
         << "| 2. Withdraw from Checking account                     |\n"
         << "| 3. Return to Main Menu                                |\n"
         << "|_______________________________________________________|\n";
    cout << "                                      Enter your Option: ";
        type = checkingvalidity(type, 1, 3);
        if(type == 3){ // Returns to menu, exit current function
            Mainmenu();
            return;
        }else if(type == 0){
        withdrawFromAccount();
        }
        cout << "Enter Your Account Number: ";
        num = checkingvalidity(num, 100000, 999999);
        cout << "Enter your Account Title:";
        cin >> name;
        if(num == 0){
            withdrawFromAccount();
        }
        if(type == 1){ // Saving Account
            for(int i = 0; i < s_accounts.size(); i++){
                if(s_accounts[i].getaccountname() == name){
                if(s_accounts[i].getAccountNum() == num){
                    found = true;
                    cout << "Enter Withdraw Amount: RM";
                    while(!(cin >> amount) || amount < 0){ // Input validation for amount, ensure it is not negative value
                        cin.clear();
                        while(cin.get() != '\n') continue;
                        cout << "Invalid Input! Please Try Again.\nAmount: RM";
                    }
                    s_accounts[i].withdrawAmount(amount);
                    break;
                };
                }

            }
        }else{ // Checking Account
            for(int i = 0; i < c_accounts.size(); i++){
                if(c_accounts[i].getaccountname() == name){
                if(c_accounts[i].getAccountNum() == num){
                    found = true;
                    cout << "Enter Withdraw Amount: RM";
                    while(!(cin >> amount) || amount < 0){ // Input validation for amount, ensure it is not negative value
                        cin.clear();
                        while(cin.get() != '\n') continue;
                        cout << "Invalid Input! Please Try Again.\nAmount: RM";
                    }
                    c_accounts[i].withdrawAmount(amount);
                    break;
                };
                }

            }
        }
        if(!found){
            cout << "Unable to locate a valid Account. Please Try Again.\n";
        }
    }while(!found);

    subMenu();
}

// Function that shows all current existing accounts in the bank
void showAllAccount(){
    system("CLS"); // Clear Console Screen
    cout << "\n--------------------------------------------------\n"
         << "\t\tAll Saving Accounts"
         << "\n--------------------------------------------------\n";
    for(int i = 0; i < s_accounts.size(); i++){
        cout << "\n================= Saving Account " << i + 1 << " =================\n";
        s_accounts[i].accountStatus();//retrives account status of particular saving account from vector
        s_accounts[i].getMonthlyStatistics();// Displays monthly statistics
    }
    cout << "\n__________________________________________________\n"
         << "\t\tAll Checking Accounts"
         << "\n__________________________________________________\n";
    for(int i = 0; i < c_accounts.size(); i++){
        cout << "\n================= Checking Account " << i + 1 << " =================\n";
        c_accounts[i].accountStatus();//retrives account status of particular checking account from vector
        c_accounts[i].getMonthlyStatistics();// Displays monthly statistics of particular checking account
    }

    subMenu();
}

void sim_Monthlyprocessing(){
    system("CLS"); // Clear Console Screen
    cout << "\n--------------------------------------------------\n"
         << "\tSimulating Monthly Processing"
         << "\n--------------------------------------------------\n";
    for(int y = 0; y < s_accounts.size(); y++){
        cout << "\n~~~~~~~~~~~~~~~~~~ Saving Account " << y + 1 << " ~~~~~~~~~~~~~~~~~~\n";
        s_accounts[y].monthlyProcessing();
    }
    for(int y = 0; y < c_accounts.size(); y++){
        cout << "\n~~~~~~~~~~~~~~~~~~ Checking Account " << y + 1 << " ~~~~~~~~~~~~~~~~~\n";
        c_accounts[y].monthlyProcessing();
    }

    subMenu();
}
