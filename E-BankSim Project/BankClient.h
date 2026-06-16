#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "String.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData = clsString::Split(Line, Separator);

        return clsBankClient(UpdateMode,
            vClientData[0],
            vClientData[1],
            vClientData[2],
            vClientData[3],
            vClientData[4],
            vClientData[5],
            stof(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string Line = "";

        Line += Client.FirstName + Separator;
        Line += Client.LastName + Separator;
        Line += Client.Email + Separator;
        Line += Client.Phone + Separator;
        Line += Client.AccountNumber() + Separator;
        Line += Client.PinCode + Separator;
        Line += to_string(Client.AccountBalance);

        return Line;
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        string DataLine;
        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDelete() == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
    }

    void _AddNew()
    {

        
        _AddDataLineToFile(_ConvertClientObjectToLine(*this)); 

    }

    void _AddDataLineToFile(string stDataLine)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();

        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
    }
    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
        string UserName, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("TransfersLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }


public:

    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;

    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber,
        string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }
    bool MarkedForDelete()
    {

        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

  
    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    enum enSaveResults{svFailedEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

    enSaveResults Save()
    {
        switch (_Mode)
        {
           case enMode::EmptyMode:
           {
               if (IsEmpty())
               {
                 return enSaveResults::svFailedEmptyObject;
               }
               break;
           }
           case enMode::UpdateMode:
           {
               _Update();
               return enSaveResults::svSucceeded;
               break;
           }
           case enMode::AddNewMode:
           {

               if (clsBankClient::IsClientExist(_AccountNumber))
               {
                   return enSaveResults::svFaildAccountNumberExists;

              
               }
               else
               {

                _AddNew();
                 _Mode = enMode::UpdateMode;
                 return enSaveResults::svSucceeded;
                 
               }
               break;

           }
           
        }


        return svFailedEmptyObject;
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;

                _SaveClientsDataToFile(_vClients);
                *this = _GetEmptyClientObject();

                return true;
            }
        }
        return false;
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {

        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    static vector <clsBankClient> GetClientsList()
    {

        return _LoadClientsDataFromFile();

    }
    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalance = 0;

        for (clsBankClient Clinet : vClients)
        {

            TotalBalance += Clinet.AccountBalance;

        }

        return TotalBalance;
    }
    void Deposit(double Amount)
    {

        _AccountBalance += Amount;
        Save();

    }
    bool Withdraw(double Amount)
    {
        if (Amount > AccountBalance)
            return false;

        AccountBalance -= Amount;
        Save();

        return true;
    }
    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }
    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;


    }
};