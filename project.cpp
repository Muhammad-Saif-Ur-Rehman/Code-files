#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 10;

struct BankAccount {
    string accountHolder;
    double balance;
    int pin;
};


void createAccount(BankAccount accounts[], int& numAccounts) {
    if (numAccounts < MAX_ACCOUNTS) {
        cout << "Enter Account Id: ";
        cin >> accounts[numAccounts].accountHolder;

        // Request and save PIN
        cout << "Create a 4-digit PIN: ";
        cin >> accounts[numAccounts].pin;
        cout<<endl;

        accounts[numAccounts].balance = 0.0;
        numAccounts++;

        cout << "Account created successfully.\n";
        cout<<"------------------------------------------------------------"<<endl;
        cout<<endl;
    } else {
        cout << "Cannot create more accounts. Maximum limit reached.\n";
    }
}

int findAccountIndex(BankAccount accounts[], int numAccounts, string name, int pin) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountHolder == name && accounts[i].pin == pin) {
            return i;
        }
    }
    return -1; // Account not found
}

void deposit(BankAccount accounts[], int& numAccounts) {
    string name;
    int pin;

    cout << "Enter your Account Id: ";
    cin >> name;

    cout << "Enter your 4-digit PIN: ";
    cin >> pin;

    int accountIndex = findAccountIndex(accounts, numAccounts, name, pin);

    if (accountIndex != -1) {
        double depositAmount;
        cout << "Enter deposit amount: $";
        cin >> depositAmount;
        cout<<endl;

        accounts[accountIndex].balance += depositAmount;
        cout << "Deposit of $" << depositAmount << " successful.\n";
        cout<<endl;
    } else {
        cout << "Invalid Account Id or PIN.\n";
        cout<<endl;
    }
}

void sendMoney(BankAccount accounts[], int& numAccounts) {
    string name;
    int pin;

    cout << "Enter your Account Id: ";
    cin >> name;

    cout << "Enter your 4-digit PIN: ";
    cin >> pin;
    cout<<endl;

    int accountIndex = findAccountIndex(accounts, numAccounts, name, pin);

    if (accountIndex != -1) {
        double sendMoneyamount;
        double senderaccountName;
        cout << "Enter amount to send: $";
        cin >> sendMoneyamount;

        if (sendMoneyamount <= accounts[accountIndex].balance) {
            accounts[accountIndex].balance -= sendMoneyamount;
            cout<<"Enter AccountNumber Whom you want to send: ";
            cin>>senderaccountName;
            cout << "Amount of $ send" << sendMoneyamount << " successful.\n";
            cout << "Current Balance: $" << accounts[accountIndex].balance << "\n";
        } else {
            cout << "Insufficient funds to send.\n";
        }
    } else {
        cout << "Invalid Account Id or PIN.\n";
    }
}
void withdraw(BankAccount accounts[], int& numAccounts) {
    string name;
    int pin;

    cout << "Enter your Account Id: ";
    cin >> name;

    cout << "Enter your 4-digit PIN: ";
    cin >> pin;
    cout<<endl;

    int accountIndex = findAccountIndex(accounts, numAccounts, name, pin);

    if (accountIndex != -1) {
        double withdrawalAmount;
        cout << "Enter withdrawal amount: $";
        cin >> withdrawalAmount;

        if (withdrawalAmount <= accounts[accountIndex].balance) {
            accounts[accountIndex].balance -= withdrawalAmount;
            cout << "Withdrawal of $" << withdrawalAmount << " successful.\n";
            cout << "Current Balance: $" << accounts[accountIndex].balance << "\n";
        } else {
            cout << "Insufficient funds for withdrawal.\n";
        }
    } else {
        cout << "Invalid Account Id or PIN.\n";
    }
}

void displayBalance(BankAccount accounts[], int& numAccounts) {
    string name;
    int pin;

    cout << "Enter your Account Id: ";
    cin >> name;

    cout << "Enter your 4-digit PIN: ";
    cin >> pin;

    int accountIndex = findAccountIndex(accounts, numAccounts, name, pin);

    if (accountIndex != -1) {
        cout << "Account Holder: " << accounts[accountIndex].accountHolder << "\n";
        cout << "Current Balance: $" << accounts[accountIndex].balance << "\n";
    } else {
        cout << "Invalid Account Id or PIN.\n";
    }
}

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    cout<<"------------------------------------------------------------"<<endl;

    cout << "\t\tWelcome To Our Halal Bank\n";
    cout<<"------------------------------------------------------------"<<endl;

    do {
        // Create account
        createAccount(accounts, numAccounts);

        char choice;
        cout << "Do you want to create more accounts? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }

    } while (true);

    while (true) {


    cout<<"------------------------------------------------------------"<<endl;

    cout << "\t\tBank Management System\n";
    cout<<"------------------------------------------------------------"<<endl;
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. send money\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:\n ";
        

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                deposit(accounts, numAccounts);
                break;

            case 2:
                withdraw(accounts, numAccounts);
                break;

            case 3:
                displayBalance(accounts, numAccounts);
                break;
            case 4:
                sendMoney(accounts,numAccounts);

            case 5:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}