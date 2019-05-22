#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* -----------------------------------------
 Bank Machine Program
 Date: October 16, 2018
 Author: Arian Taherzadeh
 School: Glebe Collegiate Institute, Ottawa
 Course: ISC3U
 Teacher: Mr. Giansante
 ---------------------------------------------*/
string clientName[11] = {"", "BOB", "CATHERINE", "JOE", "SALLY", "JIMOTHY", "HENRY", "THOMAS", "JILL", "MARY", "ARIAN"};
int PIN[11] = {0, 1234, 2345, 3456, 4567, 5678, 6789, 7890, 8901, 9012, 1000};
float balance[11];
int currentClient;
string enterName;
int enterPIN;
char options;
int input;
bool overDraft;
bool invalidInput;

void accessGranted() { // Validates user's name and PIN
    currentClient = 1;
    do {
        // Greeeting Statements
        if (currentClient == 0) {
            cout << "\nAccess Denied! Invalid user name and PIN. Please try again.\n";
        } else {
            cout << "Welcome! Please enter your name followed by your 4 Digit PIN code.\n";
        }
        cout << "\nName: ";
        cin >> enterName;
        cout << "PIN: ";
        cin >> enterPIN;
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Value is invalid! Input must be an integer\n\n";
                cout << "PIN: ";
                cin >> enterPIN;
                
            } else {break;}
        }
        
        // Converts name to uppercase
        for (int i = 0; i < enterName.length(); i++) {
            enterName.at(i) = toupper(enterName.at(i));
        }
        
        // Scans through array of names and PINs to find a match
        for (int i = 1; i <= 10; i++) {
            if (enterName == clientName[i] && enterPIN == PIN[i]) {
                currentClient = i;
                break;
            } else {
                currentClient = 0;
            }
        }
    } while (currentClient == 0);
}
void withdrawMoney() { // Withdraw Money Feature
    
    int withdraw;
    input = 0;
    
    // Displays current balance
    cout << "\nYour current balance is $" << fixed << setprecision(2) << balance[currentClient] << "\n";
    // Prompts user with Quick Cash options and other option for other amounts
    cout << "[1] $20\n";
    cout << "[2] $40\n";
    cout << "[3] $60\n";
    cout << "[4] $100\n";
    cout << "[5] $200\n";
    cout << "[6] other\n";
    cout << "\nPlease select a withdrawal amount from the list above: ";
    cin >> input;
    cout << "\n\n";
    
    do {
        overDraft = false;
        
        // Keeps prompting user until input is valid
        if (invalidInput == true) {
            cout << "\nPlease select a withdrawal amount from the list above: ";
            cin >> input;
        }
        invalidInput = false;
        
        // Runs user input
        switch (input) {
            case 1:
                if (20 > balance[currentClient]) {
                    overDraft = true;
                } else {
                    balance[currentClient] = balance[currentClient] - 20;
                    cout << "\n--------------------------------------";
                    cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];                    cout << "\n--------------------------------------\n\n";
                }
                break;
            case 2:
                if (40 > balance[currentClient]) {
                    overDraft = true;
                } else {
                    balance[currentClient] = balance[currentClient] - 40;
                    cout << "\n--------------------------------------";
                    cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
                    cout << "\n--------------------------------------\n\n";
                }
                break;
            case 3:
                if (60 > balance[currentClient]) {
                    overDraft = true;
                } else {
                    balance[currentClient] = balance[currentClient] - 60;
                    cout << "\n--------------------------------------";
                    cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
                    cout << "\n--------------------------------------\n\n";
                }
                break;
            case 4:
                if (100 > balance[currentClient]) {
                    overDraft = true;
                } else {
                    balance[currentClient] = balance[currentClient] - 100;
                    cout << "\n--------------------------------------";
                    cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
                    cout << "\n--------------------------------------\n\n";
                }
                break;
            case 5:
                if (200 > balance[currentClient]) {
                    overDraft = true;
                } else {
                    balance[currentClient] = balance[currentClient] - 200;
                    cout << "\n--------------------------------------";
                    cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
                    cout << "\n--------------------------------------\n\n";
                }
                break;
            case 6:
                cout << "Please enter an amount under $500 in increments of 20 to withdraw: ";
                cin >> withdraw;
                while (true) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(80, '\n');
                        cout << "Value is invalid! Input must be an integer\n\n";
                        cout << "\nPlease enter an amount under $500 in increments of 20 to withdraw: ";
                        cin >> withdraw;
                    } else {
                        break;
                    }
                }
                do {
                    if (withdraw % 20 == 0 && withdraw <= 500 && withdraw <= balance[currentClient] && withdraw >= 0) {
                        balance[currentClient] = balance[currentClient] - withdraw;
                        cout << "\n--------------------------------------";
                        cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
                        cout << "\n--------------------------------------\n\n";
                        break;
                        // Checks for overdraft
                    } else if (withdraw > balance[currentClient]) {
                        cout << "\nError! You cannot withdraw more than what you currently possess in your account. \nPlease select from the list of commands again: ";
                        cin >> withdraw;
                        // Checks for invalid entry
                    } else if (withdraw % 20 != 0 || withdraw > 500) {
                        cout << "\nError! Please enter a number that is under $500 and is a multiple of 20: ";
                        cin >> withdraw;
                    }
                } while (true);
                break;
            default:
                invalidInput = true;
                break;
        }
        // Checks for overdraft
        if (overDraft == true) {
            cout << "\nError! You cannot withdraw more than what you currently possess in your account. \nPlease select from the list of commands again: ";
            cin >> input;
        }
    } while (overDraft == true || invalidInput == true);
    
}
void depositMoney() { // Deposit Money Feature
    float enterDeposit;
    input = 0;
    
    // Displays current balance
    cout << "\nYour current balance is $" << fixed << setprecision(2) << balance[currentClient];
    cout << "\nPlease enter the amount you would like to deposit: ";
    cin >> enterDeposit;
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Value is invalid! Input must be an integer\n\n";
            cout << "\nPlease enter the amount you would like to deposit: ";
            cin >> enterDeposit;
            
        } else {
            break;
        }
    }
    
    do { // Runs user input
        if (enterDeposit > 0) { // Generates new balance
            balance[currentClient] = balance[currentClient] + enterDeposit;
            cout << "\n--------------------------------------";
            cout << "\nYour new balance is $" << fixed << setprecision(2) << balance[currentClient];
            cout << "\n--------------------------------------\n\n";
            break;
        } else { // Checks for invalid entry
            cout << "\nError! Please enter a number greater than 0: ";
            cin >> enterDeposit;
        }
    } while (true);
}
void checkBalance() { // Check Balance Feature
    // Displays current balance
    cout << "\n--------------------------------------";
    cout << "\nYour current balance is $" << fixed << setprecision(2) << balance[currentClient];
    cout << "\n--------------------------------------\n\n";
}
void changePIN() { // Change PIN Feature
    
    int checkPIN[2] = {0, 0};
    
    cout << "\nPlease enter your current PIN: ";
    cin >> enterPIN;
    // Checks to see if PIN is correct
    while (enterPIN != PIN[currentClient]) {
        cout << "\nIncorrect PIN. Please try again.\n";
        cout << "\nPlease enter your current PIN: ";
        cin >> enterPIN;
    }
    
    if (enterPIN == PIN[currentClient]) {
        do {
            // Prompts user to enter new PIN twice
            cout << "\nPlease enter your new PIN: ";
            cin >> checkPIN[0];
            cout << "Please re-enter your new PIN: ";
            cin >> checkPIN[1];
            
            // Updates PIN
            if (checkPIN[0] == checkPIN[1] && checkPIN[1] > 999 && checkPIN[1] < 10000) {
                PIN[currentClient] = checkPIN[1];
                cout << "\nPIN successfully updated.\n\n";
                break;
            }
            // Checks to see if PINs match
            if (checkPIN[0] != checkPIN[1]) {
                cout << "\nPasswords do not match. Please try again.\n";
            }
            // Ensures that PIN is 4 digits long
            if (checkPIN[1] < 1000 || checkPIN[1] > 9999) {
                cout << "\nThe PIN must be 4 digits. Please try again.";
            }
            
        } while (true);
    }
}
int main(int argc, const char * argv[]) {
    
    bool validInput;
    
    // Generates default user balance
    balance[0] = 0;
    for (int i = 1; i <= 10; i++) {
        balance[i] = 100;
    }
    
    
    do { // Runs program loop
        accessGranted(); // Validates user name and PIN
        
        cout << "\n--------------\n";
        cout << "Access Granted\n";
        cout << "--------------\n\n";
        
        do {
            cout << "[W] To Withdraw Money\n";
            cout << "[D] To Deposit Money\n";
            cout << "[B] To Check Balance\n";
            cout << "[C] To Change PIN\n";
            cout << "[Q] To Quit\n\n";
            do {
                validInput = false;
                cout << "Please select a command from the list above: ";
                cin >> options;
                options = toupper(options);
                switch (options) {
                    case 'W':
                        withdrawMoney();
                        break;
                    case 'D':
                        depositMoney();
                        break;
                    case 'B':
                        checkBalance();
                        break;
                    case 'C':
                        changePIN();
                        break;
                    case 'Q':
                        cout << "\nThank you!\n\n";
                        break;
                    default:
                        cout << "Invalid input. Please try again.\n\n";
                        validInput = true;
                        break;
                }
            } while (validInput == true);
        } while(options != 'Q');
    } while (true);
    
    return 0;
}

