
#include "clsPerson.h"

clsPerson::clsPerson() : _Name(""), _Phone(""), _Email(""), _Address("") {}
clsPerson::clsPerson(string Name, string Phone, string Email, string Address) : _Name(Name), _Phone(Phone), _Email(Email), _Address(Address) {}


void clsPerson::SetName(string Name)
{
	_Name = Name;
}
void clsPerson::SetPhone(string Phone)
{
	_Phone = Phone;
}
void clsPerson::SetEmail(string Email)
{
	_Email = Email;
}
void clsPerson::SetAddress(string Address)
{
	_Address = Address;
}


string clsPerson::GetName() const
{
	return _Name;
}
string clsPerson::GetPhone() const
{
	return _Phone;
}
string clsPerson::GetEmail() const
{
	return _Email;
}
string clsPerson::GetAddress() const
{
	return _Address;
}
