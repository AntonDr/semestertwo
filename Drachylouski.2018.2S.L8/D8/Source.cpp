#include "OwnerPhone.h"

using namespace std;

OwnerPhone * ArrayOfOwnerPhone(int);

void DisplayArrayOfOwnerPhone(OwnerPhone*,int);

int main()
{
	OwnerPhone obj("Anton", "Drachylouski", "+375257757834", "231300,Belarus,Minsk,Oct,10A,1001A");
	
	system("pause");
	return 0;
}

OwnerPhone * ArrayOfOwnerPhone(int n)
{
	OwnerPhone * objArray = new OwnerPhone[n];

	char * firstName = {};
	char * lastName = {};
	char * phoneNumber = {};
	char * address = {};

	for (int i = 0; i < n; i++)
	{
		cout << "Enter first name:" << endl;
		cin.getline(firstName, 20);

		cout << "Enter last name:" << endl;
		cin.getline(lastName, 20);
		
		cout << "Enter phone number:" << endl;
		cin.getline(phoneNumber, 20);
		
		cout << "Enter address:" << endl;
		cin.getline(address, 20);

		objArray[i] = OwnerPhone(firstName, lastName, phoneNumber, address);

		system("cls");
	}

	return objArray;
}

void DisplayArrayOfOwnerPhone(OwnerPhone * obj,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << obj[i].GetFirstName() << endl;
		cout << obj[i].GetLastName() << endl;
		cout << obj[i].GetPhoneNumber() << endl;
		cout << obj[i].GetAddress() << endl;

		cout << endl;
	}
}
