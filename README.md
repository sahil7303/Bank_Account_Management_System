# Bank Account Management System

This is a console-based **Bank Account Management System** built using C++. This project allows users to manage their accounts, transfer funds, deposit and withdraw money, check balances, and securely update account information. Administrators can also view account details and analyze the total number of accounts. The system ensures user data security through PIN protection and supports both single-holder and joint-holder accounts.

---

## Features

## User Functionality

### 1. **Account Creation**
- Single or joint holder accounts supported.
- Account types: Savings or Current.


### 2. **Account Management**
- **Deposit Funds**: Add money securely by verifying account number and PIN.
- **Withdraw Funds**: Withdraw money with checks for sufficient balance.
- **Change PIN**: Update your account's PIN securely.
- **Balance Inquiry**: View the current balance in your account.
- **Close Account**: Permanently delete an account.
- **View Account Details**: Displays all details of an account.

### 3. **Admin Features**
- View total accounts created.
- Display details of all accounts.

### 4. **Security**
- Each account is secured with a PIN.
- Access to account details and transactions requires authentication.


## Administrator Functionality

### 1. **View Total Number of Accounts**
- Display the count of all accounts in the system.

### 2. **View All Account Details**
- Display detailed information of all accounts in the system.

## How to Run

1. **Compile the Code**:  
   Use any C++ compiler, such as `g++`:
   ```bash
   g++ -o bank_system main.cpp
   ```
2. **Run the Program**:  
   
   ```bash
   g++ -o bank_system main.cpp
   ```
3. **Follow the on-screen instructions to interact with the system.**:  


## Security Features

**PIN-Based Authentication**
Each account is secured with a PIN, which must be entered for sensitive operations like deposits, withdrawals, or PIN updates.

  
