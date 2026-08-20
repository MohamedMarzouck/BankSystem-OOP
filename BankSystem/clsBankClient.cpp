
#include "clsBankClient.h"

string clsBankClient::_ConvertClientObjectToLine(const clsBankClient& Client, const string& Seperator)
{
    string ClienttData = "";
    ClienttData += Client.AccNumber + Seperator;
    ClienttData += Client.PinCode + Seperator;
    ClienttData += Client.Name + Seperator;
    ClienttData += Client.Email + Seperator;
    ClienttData += Client.Phone + Seperator;
    ClienttData += Client.Address + Seperator;
    ClienttData += to_string(Client.AccBalance) + Seperator;

    return ClienttData;
}
void clsBankClient::_AddDataLineToFile(const string& FileName, const string& Line)
{
    fstream myFile;
    myFile.open(FileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        myFile << Line << endl;
        myFile.close();
    }
}
clsBankClient clsBankClient::_ConvertLineDataToClientObject(string Line)
{
    vector<string> vClient = clsString::_Split(Line, "#||#");

    if (vClient.size() < 7)
        return _GetEmptyClientObject();

    return clsBankClient
    (
        enMode::UpdateMode,
        vClient[0],
        vClient[1],
        vClient[2],
        vClient[3],
        vClient[4],
        vClient[5],
        stod(vClient[6])
    );
}
vector<clsBankClient> clsBankClient::_LoadClientsObjectFromFile(const string& FileName)
{
    vector<clsBankClient> vClients;
    fstream myFile;
    myFile.open(FileName, ios::in);

    if (myFile.is_open())
    {
        string Line;
        clsBankClient Client;
        while (getline(myFile, Line))
        {
            Client = _ConvertLineDataToClientObject(Line);
            vClients.push_back(Client);
        }
        myFile.close();
    }
    return vClients;
}
void clsBankClient::_SaveClientsObjectInFile(const string& FileName, vector<clsBankClient>& vClients)
{
    fstream myFile;
    myFile.open(FileName, ios::out);

    if (myFile.is_open())
    {
        for (clsBankClient& C : vClients)
        {
            if (C._MarkClientByAccNumber == false)
                myFile << _ConvertClientObjectToLine(C) << endl;
        }

        myFile.close();
    }
}
clsBankClient clsBankClient::_GetEmptyClientObject()
{
    return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
}

string clsBankClient::_GetClientFile()
{
    return ClienttsFileName;
}

void clsBankClient::_AddNewClient()
{
    _AddDataLineToFile(GetClientFile(), _ConvertClientObjectToLine(*this));
}

void clsBankClient::_Update()
{
    vector<clsBankClient> vClients = clsBankClient::ListClients();
    for (clsBankClient& C : vClients)
        if (C.AccNumber == _AccNumber)  // -> The open object in memory;
            C = *this;

    _SaveClientsObjectInFile(GetClientFile(), vClients);
}





clsBankClient::clsBankClient() : _Mode(enMode::EmptyMode), _AccNumber(""), _PinCode(""), clsPerson("", "", "", ""),_AccBalance(0) {}

clsBankClient::clsBankClient(enMode Mode, string AccNumber, string PinCode, string Name, string Email, string Phone, string Address,double AccBalance)
    : _Mode(Mode), _AccNumber(AccNumber), _PinCode(PinCode), clsPerson(Name, Email, Phone, Address),_AccBalance(AccBalance) {}

void clsBankClient::SetAccNumber(string AccNumber)
{
    _AccNumber = AccNumber;
}
void clsBankClient::SetPinCode(string PinCode)
{
    _PinCode = PinCode;
}
void clsBankClient::SetAccBalance(double AccBalance)
{
    _AccBalance = AccBalance;
}
string clsBankClient::GetAccNumber() const
{
    return _AccNumber;
}
string clsBankClient::GetPinCode() const
{
    return _PinCode;
}
double clsBankClient::GetAccBalance() const
{
    return _AccBalance;
}

string clsBankClient::GetClientFile()
{
    return _GetClientFile();
}

vector<clsBankClient> clsBankClient::ListClients()
{
    vector<clsBankClient> vClients = _LoadClientsObjectFromFile(GetClientFile());
    return vClients;
}

bool clsBankClient::IsEmpty()
{
    return _Mode == enMode::EmptyMode;
}

bool clsBankClient::IsClientExist(const string& AccountNumber)
{
    clsBankClient Client = Find(AccountNumber);
    return !Client.IsEmpty();
}

clsBankClient clsBankClient::Find(const string& AccountNumber)
{
    fstream myFile;
    myFile.open(GetClientFile(), ios::in);

    if (myFile.is_open())
    {
        string Line;
        clsBankClient Client;
        while (getline(myFile, Line))
        {
            Client = _ConvertLineDataToClientObject(Line);
            if (Client.AccNumber == AccountNumber)
            {
                myFile.close();
                return Client;
            }
        }
        myFile.close();
    }
    
    return _GetEmptyClientObject();
}

bool clsBankClient::Find(const string& AccountNumber, const string& pCode)
{
    clsBankClient Client = Find(AccountNumber);
    if (Client.PinCode == pCode && !Client.IsEmpty())
        return true;

    return false;
}

clsBankClient clsBankClient::GetAddNewClientObject(const string& AccountNumber)
{
    return clsBankClient(enMode::AddNewMode, AccountNumber, "", "", "", "", "", 0);
}

void clsBankClient::Print()
{
    cout << "\n   Client Card:";
    cout << "\n___________________";
    cout << "\nAcc. Number: " << _AccNumber;
    cout << "\nPincode    : " << _PinCode;
    cout << "\nFull Name  : " << Name;
    cout << "\nEmail      : " << Email;
    cout << "\nPhone      : " << Phone;
    cout << "\nAddress    : " << Address;
    cout << "\nAcc. Balance: " << _AccBalance;
    cout << "\n___________________\n";
}

clsBankClient::enSaveResult clsBankClient::Save()
{
    switch (_Mode)
    {
    case enMode::EmptyMode:
        return enSaveResult::svFailedEmptyMode;

    case enMode::UpdateMode:
        _Update();
        return enSaveResult::svSucceeded;

    case enMode::AddNewMode:
        if (this->IsEmpty())
            return enSaveResult::svFailedClientExists;
        else
        {
            _AddNewClient();
            _Mode = enMode::UpdateMode;      // First Save, Then Change Mode;
            return enSaveResult::svSucceeded;
        }
    }
}

void clsBankClient::deleteClient()
{
    _MarkClientByAccNumber = true;
    Save();
    *this = _GetEmptyClientObject();
}
