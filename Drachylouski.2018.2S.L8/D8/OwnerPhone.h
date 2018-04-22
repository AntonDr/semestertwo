#pragma once

#include "StringLibrary.h"

class OwnerPhone
{
public:

	OwnerPhone(const char*,const char *,const char *,const char *);

	OwnerPhone(const OwnerPhone &);

	OwnerPhone();
	
	~OwnerPhone();

	char * GetFirstName() const;

	char * GetLastName() const;

	char * GetPhoneNumber() const;

	char * GetAddress() const;


private:
	String * firstName;
	String * lastName;
	String * phoneNumber;
	String * address;
	
};

