#ifndef CONTACT
#define CONTACT
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Contact
{
public:
	string phoneNumber;
	string firstName;
	string lastName;
	string address;
	string emailAddress;

	Contact()
	{
	}
	Contact(string phoneNumber, string firstName, string lastName, string address, string emailAddress)
	{
		this->phoneNumber = phoneNumber;
		this->firstName = firstName;
		this->lastName = lastName;
		this->address = address;
		this->emailAddress = emailAddress;
	}

	string getPhoneNumber()
	{
		return this->phoneNumber;
	}
	string getFirstName()
	{
		return this->firstName;
	}
	string getLastName()
	{
		return this->lastName;
	}
	string getAddress()
	{
		return this->address;
	}
	string getEmailAddress()
	{
		return this->emailAddress;
	}

	void setPhoneNumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setEmailAddress(string emailAddress)
	{
		this->emailAddress = emailAddress;
	}

	friend ostream &operator<<(ostream &output, const Contact &contact)
	{
		output << "Contact " << endl;
		output << "Phone number: " << contact.phoneNumber << endl;
		output << "First name: " << contact.firstName << endl;
		output << "Last name: " << contact.lastName << endl;
		output << "Address: " << contact.address << endl;
		output << "Email address: " << contact.emailAddress << endl;
		return output;
	}
	friend istream &operator>>(istream &input, Contact &contact)
	{
		cout << "Enter the phone number: ";
		input >> contact.phoneNumber;
		cout << "Enter the first name: ";
		input >> contact.firstName;
		cout << "Enter the last name: ";
		input >> contact.lastName;
		cout << "Enter the address: ";
		input >> contact.address;
		cout << "Enter the email address: ";
		input >> contact.emailAddress;
		return input;
	}

	string tostring()
	{
		stringstream buffer;
		buffer << this->phoneNumber << ";" << this->firstName << ";" << this->lastName << ";" << this->address << ";" << this->emailAddress << endl;
		return buffer.str();
	}
};

#endif