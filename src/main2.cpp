#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

int total_saving_accounts = 0;
int total_current_accounts = 0;

class account {
public:
    string name_of_account_holder;
    string name_of_joint_account_holder;
    long long int account_number;
    int balance;
    string type_of_account;
    string pin;

    account(string accholdername, int bal, string typeofacc, string pc)
        : name_of_account_holder(accholdername),
          name_of_joint_account_holder("No Joint Holder in this account"),
          balance(bal),
          type_of_account(typeofacc),
          pin(pc) {
        account_number = rand() % 100000 + 1000000000;
    }

    account(string accholdername, string jointholdername, int bal, string typeofacc, string pc)
        : name_of_account_holder(accholdername),
          name_of_joint_account_holder(jointholdername),
          balance(bal),
          type_of_account(typeofacc),
          pin(pc) {
        account_number = rand() % 100000 + 1000000000;
    }
};

vector<account> accts;

void save_accounts_to_file() {
    ofstream file("accounts.txt");
    for (const auto& acc : accts) {
        file << acc.account_number << " " << acc.name_of_account_holder << " "
             << acc.name_of_joint_account_holder << " " << acc.balance << " "
             << acc.type_of_account << " " << acc.pin << endl;
    }
    file.close();
}

void load_accounts_from_file() {
    ifstream file("accounts.txt");
    if (!file) return; // If file doesn't exist, return

    while (!file.eof()) {
        account acc("", "", 0, "", "");
        file >> acc.account_number >> acc.name_of_account_holder >>
            acc.name_of_joint_account_holder >> acc.balance >>
            acc.type_of_account >> acc.pin;

        if (!file.fail()) accts.push_back(acc);
    }
    file.close();
}

void display_details(long long int accnum) {
    bool acc_exists = false;
    for (const auto& it : accts) {
        if (it.account_number == accnum) {
            acc_exists = true;
            cout << "\nAccount Number: " << it.account_number;
            cout << "\nAccount Holder Name: " << it.name_of_account_holder;
            cout << "\nJoint Holder Name: " << it.name_of_joint_account_holder;
            cout << "\nBalance: " << it.balance;
            cout << "\nType of Account: " << it.type_of_account << endl;
        }
    }
    if (!acc_exists) {
        cout << "Account doesn't exist with the given Account Number.\n";
    }
}

bool create_account() {
    string accholder_name;
    cout << "\nENTER YOUR DETAILS HERE: ";
    cout << "\nName of Account Holder: ";
    cin >> accholder_name;

    string str;
    cout << "\nDo you want to have a joint holder account? Type YES/NO: ";
    cin >> str;

    string joint_holder;
    if (str == "YES") {
        cout << "Enter the name of Joint Holder: ";
        cin >> joint_holder;
    }

    string pin;
    cout << "\nEnter the pin: ";
    cin >> pin;

    string typeofacc;
    int choice;
    cout << "\nEnter the type of account (1-Savings, 2-Current): ";
    cin >> choice;

    if (choice == 1)
        typeofacc = "Savings";
    else
        typeofacc = "Current";

    int balance;
    cout << "\nEnter the initial balance: ";
    cin >> balance;

    if (typeofacc == "Current" && balance < 10000) {
        cout << "INSUFFICIENT BALANCE for a Current Account.\n";
        return false;
    }

    if (str == "YES") {
        account ob(accholder_name, joint_holder, balance, typeofacc, pin);
        accts.push_back(ob);
    } else {
        account ob(accholder_name, balance, typeofacc, pin);
        accts.push_back(ob);
    }

    save_accounts_to_file();
    cout << "ACCOUNT CREATED SUCCESSFULLY.\n";
    return true;
}

bool deposit_into_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto& it : accts) {
        if (it.account_number == accnum) {
            string pinfordepo;
            cout << "Enter the pin: ";
            cin >> pinfordepo;

            if (pinfordepo == it.pin) {
                int deposit_amount;
                cout << "Enter the amount you want to deposit: ";
                cin >> deposit_amount;

                it.balance += deposit_amount;
                save_accounts_to_file();
                cout << "Deposit Successful. Updated Details:\n";
                display_details(it.account_number);
                return true;
            } else {
                cout << "Invalid Pin. Try Again.\n";
                return false;
            }
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool withdraw_from_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto& it : accts) {
        if (it.account_number == accnum) {
            string pinfordepo;
            cout << "Enter the pin: ";
            cin >> pinfordepo;

            if (pinfordepo == it.pin) {
                int withdrawal_amount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawal_amount;

                if (it.balance >= withdrawal_amount) {
                    it.balance -= withdrawal_amount;
                    save_accounts_to_file();
                    cout << "Withdrawal Successful. Updated Details:\n";
                    display_details(it.account_number);
                    return true;
                } else {
                    cout << "Insufficient Balance.\n";
                    return false;
                }
            } else {
                cout << "Invalid Pin. Try Again.\n";
                return false;
            }
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

void user_menu() {
    int choice;
    do {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit_into_account(); break;
            case 3: withdraw_from_account(); break;
            case 4: exit(0);
            default: cout << "Invalid Choice. Try Again.\n";
        }
    } while (choice != 4);
}

int main() {
    load_accounts_from_file();
    user_menu();
    return 0;
}
