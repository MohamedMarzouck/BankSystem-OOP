
#pragma once
#include <iostream>
using namespace std;


class clsPerson
{
private:
	string _ID;
	string _Name;
	string _Phone;
	string _Email;
	string _Address;

public:
	clsPerson();
	clsPerson(string ID, string Name, string Phone, string Email, string Address);

	void SetName(string Name);
	void SetPhone(string Phone);
	void SetEmail(string Email);
	void SetAddress(string Address);
	string GetID()const;           // OnlyGetter
	string GetName()const;
	string GetPhone()const;
	string GetEmail()const;
	string GetAddress()const;
	__declspec(property(get = GetID)) string ID;
	__declspec(property(get = GetName, put = SetName)) string Name;
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	__declspec(property(get = GetAddress, put = SetAddress)) string Address;


};

