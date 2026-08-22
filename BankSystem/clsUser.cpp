
#include "clsUser.h"

string clsUser::_ConvertUserObjectToLine(const clsUser& User, const string& Seperator)
{
    string UserData = "";
    UserData += User.Name + Seperator;
    UserData += User.Email + Seperator;
    UserData += User.Phone + Seperator;
    UserData += User.Address + Seperator;
    UserData += User.UserName + Seperator;
    UserData += User.Password + Seperator;
    UserData += to_string(User.Permissions);

    return UserData;
}
void clsUser::_AddDataLineToFile(const string& FileName, const string& Line)
{
    fstream myFile;
    myFile.open(FileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        myFile << Line << endl;
        myFile.close();
    }
}
clsUser clsUser::_ConvertLineDataToUserObject(string Line)
{
    vector<string> vUsers = clsString::_Split(Line, "#||#");

    if (vUsers.size() < 7)
        return _GetEmptyUserObject();

    return clsUser
    (
        enMode::UpdateMode,
        vUsers[0],
        vUsers[1],
        vUsers[2],
        vUsers[3],
        vUsers[4],
        vUsers[5],
        stod(vUsers[6])
    );
}
vector<clsUser> clsUser::_LoadUsersObjectFromFile(const string& FileName)
{
    vector<clsUser> vUsers;
    fstream myFile;
    myFile.open(FileName, ios::in);

    if (myFile.is_open())
    {
        string Line;
        clsUser User;
        while (getline(myFile, Line))
        {
            User = _ConvertLineDataToUserObject(Line);
            vUsers.push_back(User);
        }
        myFile.close();
    }
    return vUsers;
}
void clsUser::_SaveUsersObjectInFile(const string& FileName, vector<clsUser>& vUsers)
{
    fstream myFile;
    myFile.open(FileName, ios::out);

    if (myFile.is_open())
    {
        for (clsUser& C : vUsers)
        {
            if (C._MarkUserForDelete == false)
                myFile << _ConvertUserObjectToLine(C) << endl;
        }

        myFile.close();
    }
}
clsUser clsUser::_GetEmptyUserObject()
{
    return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
}
string clsUser::_GetUserFile()
{
    return UsersFileName;
}

short clsUser::_ReadPermissions()
{
    int Permissions = 0;

    char Answer = 'N';
    cout << "\nDo you want to give him the full access[Y, N]?   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        return -1;


    cout << "\nDo you want to give him to access to?   ";
    cout << "\nClient list[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pClientsList;

    cout << "\nAdd new client[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pAddNewClient;

    cout << "\nFind client[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pFindClient;

    cout << "\nUpdate client[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pUpdateClient;

    cout << "\nDelete client[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pDeleteClient;
    cout << "\nTransaction menu[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pTransaction;

    cout << "\nLogin Register[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pLoginRegister;

    cout << "\nDManage users[Y, N]:   ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        Permissions += enPermissions::pManageUsers;

    return Permissions;
}

void clsUser::_AddNewUser()
{
    _AddDataLineToFile(GetUserFile(), _ConvertUserObjectToLine(*this));
}

void clsUser::_Update()
{
    vector<clsUser> vUsers = clsUser::ListUsers();
    for (clsUser& U : vUsers)
        if (U.UserName == UserName)  // -> The open object in memory;
            U = *this;

    _SaveUsersObjectInFile(GetUserFile(), vUsers);
}






clsUser::clsUser() : _Mode(enMode::EmptyMode), clsPerson("", "", "", ""), _UserName(""), _Password(""), _Permissions(0)
{
}
clsUser::clsUser(enMode Mode, string Name, string Email, string Phone, string Address, string UserName, string Password, short Permissions)
    : _Mode(Mode), clsPerson(Name, Email, Phone, Address), _UserName(UserName), _Password(Password), _Permissions(Permissions)
{
}

void clsUser::SetUserName(string UserName)
{
    _UserName = UserName;
}

void clsUser::SetPassword(string Password)
{
    _Password = Password;
}

void clsUser::SetPermissions(short Permissions)
{
    _Permissions = Permissions;
}

string clsUser::GetUserName() const
{
    return _UserName;
}

string clsUser::GetPassword() const
{
    return _Password;
}

short clsUser::GetPermissions() const
{
    return _Permissions;
}



string clsUser::GetUserFile()
{
    return _GetUserFile();
}

vector<clsUser> clsUser::ListUsers()
{
    vector<clsUser> vUsers = _LoadUsersObjectFromFile(GetUserFile());
    return vUsers;
}

bool clsUser::IsEmpty()
{
    return _Mode == enMode::EmptyMode;
}

bool clsUser::IsUserExist(const string& uName)
{
    clsUser User = Find(uName);
    return !User.IsEmpty();
}

clsUser clsUser::Find(const string& uName)
{
    fstream myFile;
    myFile.open(GetUserFile(), ios::in);

    if (myFile.is_open())
    {
        string Line;
        clsUser User;
        while (getline(myFile, Line))
        {
            User = _ConvertLineDataToUserObject(Line);
            if (User.UserName == uName)
            {
                myFile.close();
                return User;
            }
        }
        myFile.close();
    }

    return _GetEmptyUserObject();
}

clsUser clsUser::Find(const string& uName, const string& Pass)
{
    clsUser User = Find(uName);
    if (User.Password == Pass && !User.IsEmpty())
        return User;

    return _GetEmptyUserObject();
}

clsUser clsUser::GetAddNewUserObject(const string& uName)
{
    return clsUser(enMode::AddNew, "", "", "", "", uName, "", 0);
}

void clsUser::Print()
{
    cout << "\n   User Card:";
    cout << "\n___________________";
    cout << "\nFull Name  : " << Name;
    cout << "\nEmail      : " << Email;
    cout << "\nPhone      : " << Phone;
    cout << "\nAddress    : " << Address;
    cout << "\nUser Name  : " << UserName;
    cout << "\nPassword   : " << Password;
    cout << "\nPermissions: " << Permissions;
    cout << "\n___________________\n";
}

clsUser::enSaveResult clsUser::Save()
{
    switch (_Mode)
    {
    case enMode::EmptyMode:
        return enSaveResult::svFailedEmptyMode;

    case enMode::UpdateMode:
        _Update();
        return enSaveResult::svSucceeded;

    case enMode::AddNew:
        if (this->IsEmpty())
            return enSaveResult::svFailedUserExists;
        else
        {
            _AddNewUser();
            _Mode = enMode::UpdateMode;      // First Save, Then Change Mode;
            return enSaveResult::svSucceeded;
        }
    }
}

void clsUser::deleteUser()
{
    _MarkUserForDelete = true;
    Save();
    *this = _GetEmptyUserObject();
}

bool clsUser::CheckAccessPermissions(enPermissions Permissions)
{
    if (this->Permissions == enPermissions::pAll) return true;
    if ((this->Permissions & Permissions) == Permissions) return true;

    return false;
}

short clsUser::ReadPermissions()
{
    return _ReadPermissions();
}

