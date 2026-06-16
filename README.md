# **E-BankSim v2.0**

**E-BankSim** is a complete console-based banking management system developed in **C++**. The project simulates real-world banking operations such as client management, user authentication, transactions, transfers, permission control, login tracking, and currency exchange.

The application was originally developed using a procedural programming approach and later completely refactored into a full **Object-Oriented Programming (OOP)** architecture to improve maintainability, scalability, and code organization.

---

# **Table of Contents**

1. Features
2. Login Information
3. Permission System
4. Database Structure
5. How It Works
6. Project Structure
7. System Architecture
8. System Diagrams
9. Learning Goals
10. Changes from Previous Version
11. Author

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
* Find currencies by code
* Find currencies by country
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

### Default Administrator Account

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

All records are stored using the custom delimiter:

```cpp
#//#
```

---

# **How It Works**

1. The application loads data from text files into memory.
2. Users authenticate through the login system.
3. Permissions are validated before opening protected screens.
4. Operations are executed through a structured menu system.
5. Changes are saved immediately back to text files.
6. Login activities and transfers are logged automatically.

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

# **System Diagrams**

## 1. Complete System Architecture

```mermaid
flowchart TD
    App["E-BankSim.cpp<br/>main()"] --> Login["clsLoginScreen<br/>Login Screen"]

    Login --> Auth{"Valid username<br/>and password?"}
    Auth -- "No<br/>3 failed tries" --> Exit["Exit Application"]
    Auth -- "Yes" --> CurrentUser["CurrentUser<br/>Global Object"]

    CurrentUser --> Main["clsMainScreen<br/>Main Menu"]

    Main --> ClientModule["Client Management"]
    Main --> TransactionModule["Transactions"]
    Main --> UserModule["Manage Users"]
    Main --> LoginRegisterModule["Login Register"]
    Main --> CurrencyModule["Currency Exchange"]
    Main --> Logout["Logout"]

    ClientModule --> ClientList["clsClientListScreen<br/>List Clients"]
    ClientModule --> AddClient["clsAddNewClientScreen<br/>Add Client"]
    ClientModule --> DeleteClient["clsDeleteClientScreen<br/>Delete Client"]
    ClientModule --> UpdateClient["clsUpdateClientScreen<br/>Update Client"]
    ClientModule --> FindClient["clsFindClientScreen<br/>Find Client"]

    TransactionModule --> Deposit["clsDepositScreen<br/>Deposit"]
    TransactionModule --> Withdraw["clsWithdrawScreen<br/>Withdraw"]
    TransactionModule --> TotalBalance["clsTotalBalanceScreen<br/>Total Balances"]
    TransactionModule --> Transfer["clsTransferScreen<br/>Transfer Money"]
    TransactionModule --> TransferLog["clsTransferLogScreen<br/>Transfer Log"]

    UserModule --> UsersList["clsUsersListScreen<br/>List Users"]
    UserModule --> AddUser["clsAddNewUserScreen<br/>Add User"]
    UserModule --> DeleteUser["clsDeleteUserScreen<br/>Delete User"]
    UserModule --> UpdateUser["clsUpdateUserScreen<br/>Update User"]
    UserModule --> FindUser["clsFindUserScreen<br/>Find User"]

    LoginRegisterModule --> RegisterScreen["clsRegisterLoginScreen<br/>Show Login History"]

    CurrencyModule --> CurrencyList["clsCurrenciesListScreen<br/>List Currencies"]
    CurrencyModule --> FindCurrency["clsFindCurrencyScreen<br/>Find Currency"]
    CurrencyModule --> UpdateCurrency["clsUpdateCurrencyRateScreen<br/>Update Rate"]
    CurrencyModule --> CurrencyCalculator["clsCurrencyCalculatorScreen<br/>Currency Calculator"]

    ClientList --> BankClient["clsBankClient"]
    AddClient --> BankClient
    DeleteClient --> BankClient
    UpdateClient --> BankClient
    FindClient --> BankClient
    Deposit --> BankClient
    Withdraw --> BankClient
    TotalBalance --> BankClient
    Transfer --> BankClient
    TransferLog --> BankClient

    Login --> User["clsUser"]
    UsersList --> User
    AddUser --> User
    DeleteUser --> User
    UpdateUser --> User
    FindUser --> User
    RegisterScreen --> User

    CurrencyList --> Currency["clsCurrency"]
    FindCurrency --> Currency
    UpdateCurrency --> Currency
    CurrencyCalculator --> Currency

    BankClient --> ClientsFile[("Clients.txt")]
    BankClient --> TransferFile[("TransferLog.txt")]
    User --> UsersFile[("Users.txt")]
    User --> LoginFile[("LoginRegister.txt")]
    Currency --> CurrencyFile[("Currencies.txt")]

    Screen["clsScreen<br/>Base Screen Class"] --> Login
    Screen --> Main
    Screen --> ClientModule
    Screen --> TransactionModule
    Screen --> UserModule
    Screen --> CurrencyModule

    Person["clsPerson<br/>Base Person Class"] --> BankClient
    Person --> User

    Interface["clsInterfaceCommunication<br/>Interface"] --> Person

    Input["clsInputValidate"] --> Login
    Input --> Main
    Input --> ClientModule
    Input --> TransactionModule
    Input --> UserModule
    Input --> CurrencyModule

    Date["clsDate"] --> Screen
    Date --> User
    Util["clsUtil"] --> User
    Util --> TotalBalance
    String["clsString"] --> User
    String --> BankClient
    String --> Currency
```

## 2. UML Class Diagram

```mermaid
classDiagram

    class clsInterfaceCommunication {
        <<interface>>
        +SendEmail(string Title, string Body)
        +SendFax(string Title, string Body)
        +SendSMS(string Title, string Body)
    }

    class clsPerson {
        -string FirstName
        -string LastName
        -string Email
        -string Phone
        +FullName() string
        +SendEmail(string Title, string Body)
        +SendFax(string Title, string Body)
        +SendSMS(string Title, string Body)
    }

    class clsBankClient {
        -string AccountNumber
        -string PinCode
        -float AccountBalance
        -bool MarkedForDelete
        +Find(string AccountNumber) clsBankClient
        +Find(string AccountNumber, string PinCode) clsBankClient
        +IsClientExist(string AccountNumber) bool
        +GetAddNewClientObject(string AccountNumber) clsBankClient
        +Save() enSaveResults
        +Delete() bool
        +Deposit(double Amount)
        +Withdraw(double Amount) bool
        +Transfer(float Amount, clsBankClient DestinationClient, string UserName) bool
        +GetClientsList() vector~clsBankClient~
        +GetTotalBalances() double
        +GetTransfersLogList() vector~stTransferLogRecord~
    }

    class clsUser {
        -string UserName
        -string Password
        -int Permissions
        -bool MarkedForDelete
        +Find(string UserName) clsUser
        +Find(string UserName, string Password) clsUser
        +IsUserExist(string UserName) bool
        +GetAddNewUserObject(string UserName) clsUser
        +Save() enSaveResult
        +Delete() bool
        +CheckAccessPermission(enPermission Permission) bool
        +RegisterLogIn()
        +GetUsersList() vector~clsUser~
        +GetLoginRegisterList() vector~stLoginRegisterRecord~
    }

    class clsCurrency {
        -string Country
        -string CurrencyCode
        -string CurrencyName
        -float Rate
        +FindByCode(string CurrencyCode) clsCurrency
        +FindByCountry(string Country) clsCurrency
        +IsCurrencyExist(string CurrencyCode) bool
        +UpdateRate(float NewRate)
        +ConvertToUSD(float Amount) float
        +ConvertToOtherCurrency(float Amount, clsCurrency Currency2) float
        +GetCurrenciesList() vector~clsCurrency~
    }

    class clsScreen {
        +_DrawScreenHeader(string Title, string SubTitle)
        +CheckAccessRights(clsUser::enPermission Permission) bool
        +_DrawScreenHeaderMain()
        +IsNowUser()
        +PrintCurrentDateTime()
    }

    class clsDate {
        -short Day
        -short Month
        -short Year
        +GetSystemDate() clsDate
        +GetSystemDateTimeString() string
        +DateToString() string
        +IsValidDate(clsDate Date) bool
    }

    class clsString {
        -string Value
        +Split(string Text, string Delim) vector~string~
        +UpperAllString(string Text) string
        +LowerAllString(string Text) string
        +Trim(string Text) string
    }

    class clsInputValidate {
        +ReadString() string
        +ReadShortNumber() short
        +ReadIntNumber() int
        +ReadDblNumber() double
        +ReadFloatNumber() double
        +ReadShortNumberBetween(short From, short To) short
        +ReadIntNumberBetween(int From, int To) int
    }

    class clsUtil {
        +RandomNumber(int From, int To) int
        +GenerateKey() string
        +NumberToText(int Number) string
        +EncryptText(string Text) string
        +DecryptText(string Text) string
    }

    clsInterfaceCommunication <|.. clsPerson
    clsPerson <|-- clsBankClient
    clsPerson <|-- clsUser

    clsBankClient ..> clsString
    clsBankClient ..> clsDate
    clsUser ..> clsString
    clsUser ..> clsDate
    clsUser ..> clsUtil
    clsCurrency ..> clsString
    clsScreen ..> clsUser
    clsScreen ..> clsDate
```

## 3. Screens Inheritance Diagram

```mermaid
classDiagram
    class clsScreen {
        +_DrawScreenHeader()
        +CheckAccessRights()
    }

    class clsLoginScreen
    class clsMainScreen
    class clsClientListScreen
    class clsAddNewClientScreen
    class clsDeleteClientScreen
    class clsUpdateClientScreen
    class clsFindClientScreen
    class clsTransactionsScreen
    class clsDepositScreen
    class clsWithdrawScreen
    class clsTotalBalanceScreen
    class clsTransferScreen
    class clsTransferLogScreen
    class clsManageUsers
    class clsUsersListScreen
    class clsAddNewUserScreen
    class clsDeleteUserScreen
    class clsUpdateUserScreen
    class clsFindUserScreen
    class clsRegisterLoginScreen
    class clsCurrencyMainScreen
    class clsCurrenciesListScreen
    class clsFindCurrencyScreen
    class clsUpdateCurrencyRateScreen
    class clsCurrencyCalculatorScreen

    clsScreen <|-- clsLoginScreen
    clsScreen <|-- clsMainScreen
    clsScreen <|-- clsClientListScreen
    clsScreen <|-- clsAddNewClientScreen
    clsScreen <|-- clsDeleteClientScreen
    clsScreen <|-- clsUpdateClientScreen
    clsScreen <|-- clsFindClientScreen
    clsScreen <|-- clsTransactionsScreen
    clsScreen <|-- clsDepositScreen
    clsScreen <|-- clsWithdrawScreen
    clsScreen <|-- clsTotalBalanceScreen
    clsScreen <|-- clsTransferScreen
    clsScreen <|-- clsTransferLogScreen
    clsScreen <|-- clsManageUsers
    clsScreen <|-- clsUsersListScreen
    clsScreen <|-- clsAddNewUserScreen
    clsScreen <|-- clsDeleteUserScreen
    clsScreen <|-- clsUpdateUserScreen
    clsScreen <|-- clsFindUserScreen
    clsScreen <|-- clsRegisterLoginScreen
    clsScreen <|-- clsCurrencyMainScreen
    clsScreen <|-- clsCurrenciesListScreen
    clsScreen <|-- clsFindCurrencyScreen
    clsScreen <|-- clsUpdateCurrencyRateScreen
    clsScreen <|-- clsCurrencyCalculatorScreen
```

## 4. Navigation Flow

```mermaid
flowchart TD
    Start((Start)) --> MainCPP["main()"]
    MainCPP --> LoginScreen["Login Screen"]

    LoginScreen --> LoginCheck{"User exists<br/>and password correct?"}

    LoginCheck -- "No" --> FailedCount{"Failed count = 3?"}
    FailedCount -- "No" --> LoginScreen
    FailedCount -- "Yes" --> End((End))

    LoginCheck -- "Yes" --> RegisterLogin["Register Login<br/>in LoginRegister.txt"]
    RegisterLogin --> MainMenu["Main Menu"]

    MainMenu --> Option{"Choose option"}

    Option --> O1["1. Show Client List"]
    Option --> O2["2. Add New Client"]
    Option --> O3["3. Delete Client"]
    Option --> O4["4. Update Client"]
    Option --> O5["5. Find Client"]
    Option --> O6["6. Transactions"]
    Option --> O7["7. Manage Users"]
    Option --> O8["8. Login Register"]
    Option --> O9["9. Currency Exchange"]
    Option --> O10["10. Logout"]

    O1 --> Back["Back to Main Menu"]
    O2 --> Back
    O3 --> Back
    O4 --> Back
    O5 --> Back
    O8 --> Back
    O9 --> Back
    Back --> MainMenu

    O6 --> TransactionsMenu["Transactions Menu"]
    TransactionsMenu --> T1["Deposit"]
    TransactionsMenu --> T2["Withdraw"]
    TransactionsMenu --> T3["Total Balances"]
    TransactionsMenu --> T4["Transfer"]
    TransactionsMenu --> T5["Transfer Log"]
    TransactionsMenu --> T6["Main Menu"]

    T1 --> TransactionsMenu
    T2 --> TransactionsMenu
    T3 --> TransactionsMenu
    T4 --> TransactionsMenu
    T5 --> TransactionsMenu
    T6 --> MainMenu

    O7 --> UsersMenu["Manage Users Menu"]
    UsersMenu --> U1["List Users"]
    UsersMenu --> U2["Add User"]
    UsersMenu --> U3["Delete User"]
    UsersMenu --> U4["Update User"]
    UsersMenu --> U5["Find User"]
    UsersMenu --> U6["Main Menu"]

    U1 --> UsersMenu
    U2 --> UsersMenu
    U3 --> UsersMenu
    U4 --> UsersMenu
    U5 --> UsersMenu
    U6 --> MainMenu

    O10 --> Logout["Clear CurrentUser"]
    Logout --> LoginScreen
```

## 5. File Storage Diagram

```mermaid
flowchart LR
    subgraph BusinessClasses["Business Classes"]
        BankClient["clsBankClient"]
        User["clsUser"]
        Currency["clsCurrency"]
    end

    subgraph TextFiles["Text Files Storage"]
        ClientsTxt[("Clients.txt<br/>Client records")]
        UsersTxt[("Users.txt<br/>User accounts")]
        LoginTxt[("LoginRegister.txt<br/>Login history")]
        TransferTxt[("TransferLog.txt<br/>Transfer operations")]
        CurrenciesTxt[("Currencies.txt<br/>Currency rates")]
    end

    BankClient -->|"Load / Save / Update / Delete"| ClientsTxt
    BankClient -->|"Register transfers"| TransferTxt

    User -->|"Load / Save / Update / Delete"| UsersTxt
    User -->|"Register login"| LoginTxt

    Currency -->|"Load / Update rates"| CurrenciesTxt
```

## 6. Permissions System

```mermaid
flowchart TD
    User["clsUser"] --> Permissions["Permissions Integer"]

    Permissions --> All["eAll = -1<br/>Full Access"]
    Permissions --> List["pListClients = 1"]
    Permissions --> Add["pAddNewClient = 2"]
    Permissions --> Delete["pDeleteClient = 4"]
    Permissions --> Update["pUpdateClients = 8"]
    Permissions --> Find["pFindClient = 16"]
    Permissions --> Transactions["pTransactions = 32"]
    Permissions --> LoginRegister["pLoginRegister = 64"]
    Permissions --> ManageUsers["pManageUsers = 128"]
    Permissions --> Currency["eCurrencyExchange = 256"]

    Screen["clsScreen::CheckAccessRights()"] --> Check{"Has permission?"}
    Check -- "Yes" --> Open["Open Screen"]
    Check -- "No" --> Denied["Access Denied"]
```

## 7. Transactions Module

```mermaid
flowchart TD
    Transactions["clsTransactionsScreen"] --> Deposit["clsDepositScreen"]
    Transactions --> Withdraw["clsWithdrawScreen"]
    Transactions --> Total["clsTotalBalanceScreen"]
    Transactions --> Transfer["clsTransferScreen"]
    Transactions --> Log["clsTransferLogScreen"]

    Deposit --> FindClient1["Find client by account number"]
    FindClient1 --> AddAmount["Add amount to balance"]
    AddAmount --> SaveClient1["Save to Clients.txt"]

    Withdraw --> FindClient2["Find client by account number"]
    FindClient2 --> CheckBalance{"Enough balance?"}
    CheckBalance -- "Yes" --> SubAmount["Subtract amount"]
    SubAmount --> SaveClient2["Save to Clients.txt"]
    CheckBalance -- "No" --> Error["Insufficient balance"]

    Total --> LoadClients["Load all clients"]
    LoadClients --> SumBalances["Calculate total balances"]

    Transfer --> Source["Find source client"]
    Transfer --> Destination["Find destination client"]
    Source --> AmountCheck{"Amount <= source balance?"}
    AmountCheck -- "Yes" --> DoTransfer["Withdraw from source<br/>Deposit to destination"]
    DoTransfer --> SaveBoth["Save both clients"]
    SaveBoth --> RegisterTransfer["Write transfer log"]

    Log --> ReadLog["Read TransferLog.txt"]
```

## 8. Currency Exchange Module

```mermaid
flowchart TD
    CurrencyMain["clsCurrencyMainScreen"] --> List["clsCurrenciesListScreen"]
    CurrencyMain --> Find["clsFindCurrencyScreen"]
    CurrencyMain --> Update["clsUpdateCurrencyRateScreen"]
    CurrencyMain --> Calculator["clsCurrencyCalculatorScreen"]

    List --> LoadCurrencies["Load all currencies<br/>from Currencies.txt"]

    Find --> FindChoice{"Find by"}
    FindChoice --> Code["Currency Code"]
    FindChoice --> Country["Country Name"]
    Code --> FindByCode["clsCurrency::FindByCode()"]
    Country --> FindByCountry["clsCurrency::FindByCountry()"]

    Update --> ReadCode["Read currency code"]
    ReadCode --> CheckExist{"Currency exists?"}
    CheckExist -- "Yes" --> NewRate["Read new rate"]
    NewRate --> SaveRate["Update Currencies.txt"]
    CheckExist -- "No" --> TryAgain["Ask again"]

    Calculator --> From["Currency From"]
    Calculator --> To["Currency To"]
    From --> Amount["Read amount"]
    Amount --> USD["Convert to USD"]
    USD --> Other["Convert USD to target currency"]
```

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

| Feature                   | v0.1                   | v2.0                              |
| ------------------------- | ---------------------- | --------------------------------- |
| Programming Style         | Procedural Programming | Object-Oriented Programming (OOP) |
| Client CRUD               | Available              | Refactored using Classes          |
| User Management           | Available              | Improved & Refactored             |
| Permissions System        | Available              | Improved                          |
| Authentication System     | Basic Login            | Enhanced Authentication           |
| Transfers                 | Available              | Improved & Refactored             |
| Transfer Logs             | Available              | Improved Logging Structure        |
| Currency Exchange         | Not Available          | Added                             |
| Currency Calculator       | Not Available          | Added                             |
| Password Encryption       | Not Available          | Added                             |
| Inheritance               | Not Available          | Added                             |
| Interfaces                | Not Available          | Added                             |
| Encapsulation             | Not Available          | Added                             |
| Multi-Screen Architecture | Limited                | Fully Modular                     |
| Code Organization         | Procedural             | OOP Architecture                  |
| Documentation             | Basic                  | Professional                      |

### **Major Improvements in v2.0**

* Refactored the entire project from Procedural Programming to Object-Oriented Programming (OOP).
* Introduced core classes such as `clsPerson`, `clsUser`, `clsBankClient`, and `clsCurrency`.
* Added inheritance, encapsulation, and interface-based design.
* Added Currency Exchange and Currency Calculator modules.
* Added password encryption for user credentials.
* Improved authentication and permission handling.
* Reorganized the project into modular screen classes.
* Improved maintainability, scalability, and code readability.

---

# **Author**

**Youness Chergui Amin**

C++ Banking Management System Project
