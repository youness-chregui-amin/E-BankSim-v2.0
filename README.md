# **E-BankSim v2.0**

**E-BankSim** is a C++ console application that simulates a complete electronic banking system. The project evolved from a simple procedural banking application into a fully Object-Oriented Programming (OOP) system featuring authentication, permissions, transactions, transfer logs, currency exchange, and modular screen-based architecture.

---

# **Table of Contents**

1. Features
2. Login Information
3. Permission System
4. Database Structure
5. How It Works
6. Project Structure
7. System Architecture
8. Learning Goals
9. Changes from Previous Version

---

# **Features**

## **Client Management (CRUD)**

* Add new clients
* Update client information
* Delete clients
* Search clients by Account Number
* Display all clients

---

## **Transactions**

* Deposit money
* Withdraw money
* Transfer money between accounts
* Display total balances
* View transfer logs

---

## **User Management**

* Add new users
* Update users
* Delete users
* Search users
* Assign custom permissions
* Full Access / Limited Access support

---

## **Authentication & Security**

* Secure login system
* User authentication
* Permission-based access control
* Login history tracking
* Password encryption

---

## **Currency Exchange**

* List all currencies
* Find currency by code
* Find currency by country
* Update exchange rates
* Currency conversion calculator

---

## **Command-Line Interface (CLI)**

* Main Menu
* Transactions Menu
* User Management Menu
* Currency Exchange Menu
* Login Register Screen

---

# **Login Information**

### Default Admin Account

| Username | Password |
| -------- | -------- |
| Admin    | 1234     |

> The administrator account has full access to all system functionalities.

---

# **Permission System**

| Permission        | Value |
| ----------------- | ----- |
| List Clients      | 1     |
| Add Client        | 2     |
| Delete Client     | 4     |
| Update Client     | 8     |
| Find Client       | 16    |
| Transactions      | 32    |
| Login Register    | 64    |
| Manage Users      | 128   |
| Currency Exchange | 256   |
| Full Access       | -1    |

---

# **Database Structure**

### Clients.txt

Stores client information.

| Field           |
| --------------- |
| First Name      |
| Last Name       |
| Email           |
| Phone           |
| Account Number  |
| Pin Code        |
| Account Balance |

---

### Users.txt

Stores user accounts and permissions.

| Field       |
| ----------- |
| First Name  |
| Last Name   |
| Email       |
| Phone       |
| Username    |
| Password    |
| Permissions |

---

### LoginRegister.txt

Stores login history.

| Field       |
| ----------- |
| Date / Time |
| Username    |
| Password    |
| Permissions |

---

### TransferLog.txt

Stores transfer operations.

| Field                     |
| ------------------------- |
| Date / Time               |
| Source Account            |
| Destination Account       |
| Amount                    |
| Source Balance After      |
| Destination Balance After |
| User                      |

---

### Currencies.txt

Stores currency exchange rates.

| Field         |
| ------------- |
| Country       |
| Currency Code |
| Currency Name |
| Rate          |

---

> All records are stored using the custom delimiter:

```cpp
#//#
```

---

# **How It Works**

1. The application loads data from text files into memory.
2. Users authenticate through the login system.
3. Permissions are verified before opening protected screens.
4. Users perform operations through structured menus.
5. Changes are saved immediately back to the text files.
6. Login operations and transfers are logged automatically.

---

## **Main Menu**

* Show Client List
* Add New Client
* Delete Client
* Update Client
* Find Client
* Transactions
* Manage Users
* Login Register
* Currency Exchange
* Logout

---

## **Transactions Menu**

* Deposit
* Withdraw
* Total Balances
* Transfer
* Transfer Log
* Back to Main Menu

---

## **User Management Menu**

* List Users
* Add User
* Delete User
* Update User
* Find User
* Back to Main Menu

---

## **Currency Exchange Menu**

* List Currencies
* Find Currency
* Update Currency Rate
* Currency Calculator
* Back to Main Menu

---

# **Project Structure**

```text
E-BankSim.cpp

├── Core Classes
│   ├── Person.h
│   ├── User.h
│   ├── BankClient.h
│   └── Currency.h
│
├── Screens
│   ├── LoginScreen.h
│   ├── MainScreen.h
│   ├── TransactionsScreen.h
│   ├── ManageUsersLib.h
│   ├── CurrencyMainScreen.h
│   └── Other Screen Classes
│
├── Utilities
│   ├── StringLib.h
│   ├── DateLib.h
│   ├── InputValidation.h
│   ├── UtilLib.h
│   └── EncryptionLib.h
│
├── Data Files
│   ├── Clients.txt
│   ├── Users.txt
│   ├── LoginRegister.txt
│   ├── TransferLog.txt
│   └── Currencies.txt
│
└── README.md
```

---

# **System Architecture**

```text
Login System
      │
      ▼
 Main Menu
 ├── Client Management
 ├── Transactions
 ├── User Management
 ├── Login Register
 └── Currency Exchange
```

---

# **Learning Goals**

This project was created to practice and improve:

* Object-Oriented Programming (OOP)
* Inheritance
* Encapsulation
* Abstraction
* Interfaces
* File Handling
* Data Persistence
* Authentication Systems
* Permission Systems
* Banking System Simulation
* Modular Software Design

---

# **Changes from Previous Version**

| Feature                   | Previous Version       | v2.0                              |
| ------------------------- | ---------------------- | --------------------------------- |
| Programming Style         | Procedural Programming | Object-Oriented Programming (OOP) |
| Client CRUD               | ✅                      | ✅                                 |
| User Management           | ❌                      | ✅                                 |
| Authentication System     | ❌                      | ✅                                 |
| Permissions System        | ❌                      | ✅                                 |
| Login Register            | ❌                      | ✅                                 |
| Transfers                 | ❌                      | ✅                                 |
| Transfer Logs             | ❌                      | ✅                                 |
| Currency Exchange         | ❌                      | ✅                                 |
| Currency Calculator       | ❌                      | ✅                                 |
| Password Encryption       | ❌                      | ✅                                 |
| Inheritance               | ❌                      | ✅                                 |
| Interfaces                | ❌                      | ✅                                 |
| Encapsulation             | ❌                      | ✅                                 |
| Multi-Screen Architecture | ❌                      | ✅                                 |
| Documentation             | Basic                  | Professional                      |

---

# **Author**

**Youness Chergui Amin**

C++ Banking Management System Project
