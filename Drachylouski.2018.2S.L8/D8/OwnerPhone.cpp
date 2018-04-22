#include "OwnerPhone.h"



OwnerPhone::OwnerPhone(const char * firstName,const char * lastName,const char * phoneNumber,const char * address)
{
	this->firstName = new String(firstName);
	this->lastName = new String(lastName);
	this->phoneNumber = new String(phoneNumber);
	this->address = new String(address);
}

OwnerPhone::OwnerPhone(const OwnerPhone & obj)
{
	this->firstName = new String(obj.GetFirstName());
	this->lastName = new String(obj.GetLastName());
	this->phoneNumber = new String(obj.GetPhoneNumber());
	this->address = new String(obj.GetAddress());
}

OwnerPhone::OwnerPhone()
{
}

OwnerPhone::~OwnerPhone()
{
	delete firstName;
	delete lastName;
	delete phoneNumber;
	delete address;
}

char * OwnerPhone::GetFirstName() const
{
	return firstName->GetString();
}

char * OwnerPhone::GetLastName() const
{
	return lastName->GetString();
}

char * OwnerPhone::GetPhoneNumber() const
{
	return phoneNumber->GetString();
}

char * OwnerPhone::GetAddress() const
{
	return address->GetString();
}
