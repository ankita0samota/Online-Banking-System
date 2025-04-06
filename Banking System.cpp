#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string account_holder;
    double balance;
    vector<string> transaction_history;  // Transaction history

public:
    BankAccount(string name, double initial_balance = 0) {
        account_holder = name;
        balance = initial_balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transaction_history.push_back("Deposited " + to_string(amount));  // Add to transaction history
            cout << "Deposited " << amount << ". New balance is " << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transaction_history.push_back("Withdrew " + to_string(amount));  // Add to transaction history
            cout << "Withdrew " << amount << ". New balance is " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void check_balance() {
        cout << "Current balance is " << balance << endl;
    }

    void account_info() {
        cout << "Account Holder: " << account_holder << endl;
        cout << "Account Balance: " << balance << endl;
    }

    void transaction_history_info() {
        cout << "Transaction History for " << account_holder << ":" << endl;
        if (transaction_history.empty()) {
            cout << "No transactions yet." << endl;
        } else {
            for (const string& transaction : transaction_history) {
                cout << transaction << endl;
            }
        }
    }
};

int main() {
    string name;
    double initial_balance;

    cout << "Welcome to the Banking System!" << endl;
    cout << "Enter the account holder's name: ";
    getline(cin, name);
    cout << "Enter the initial balance: ";
    cin >> initial_balance;

    BankAccount account(name, initial_balance);

    int choice;
    while (true) {
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Account Information" << endl;
        cout << "5. View Transaction History" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            account.check_balance();
        } else if (choice == 2) {
            double deposit_amount;
            cout << "Enter deposit amount: ";
            cin >> deposit_amount;
            account.deposit(deposit_amount);
        } else if (choice == 3) {
            double withdraw_amount;
            cout << "Enter withdrawal amount: ";
            cin >> withdraw_amount;
            account.withdraw(withdraw_amount);
        } else if (choice == 4) {
            account.account_info();
        } else if (choice == 5) {
            account.transaction_history_info();
        } else if (choice == 6) {
            cout << "Thank you for using the Banking System!" << endl;
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}

