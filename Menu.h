#ifndef MENU
#define MENU

#include "Contact.h"
#include "ContactList.h"
#include <iostream>
#include <vector>

ContactList list;

using namespace std;

class Menu
{
public:
	Menu()
	{
		string choice;
		cout << "Contact Manager" << endl;
		cout << endl;
		cout << "(1) Contact list" << endl;
		cout << "(2) Add a new contact" << endl;
		cout << "(3) Search for contact" << endl;
		cout << "(4) Edit a contact" << endl;
		cout << "(5) Delete a contact" << endl;
		cout << "(0) Exit" << endl;
		cout << endl;
		cout << "Enter the desired option: ";
		cin >> choice;
		if (choice == "1")
		{
			displayContactList();
			returnMenu();
		}
		if (choice == "2")
		{
			addContact();
			returnMenu();
		}
		if (choice == "3")
		{
			searchContact();
			returnMenu();
		}
		if (choice == "4")
		{
			editContact();
			returnMenu();
		}
		if (choice == "5")
		{
			removeContact();
			returnMenu();
		}
		if (choice == "0")
		{
			exit(0);
		}
		else
		{
			cout << "Please enter a valid option!\n\n";
			Menu();
		}
	}

private:
	void displayContactList()
	{
		vector<Contact> copyOfTheList = list.get();
		if (copyOfTheList.size() == 0)
		{
			cout << "There are no contacts!";
		}
		else
		{
			for (Contact a : copyOfTheList)
			{
				cout << a << endl;
			}
		}
	}
	void addContact()
	{
		Contact c;
		cin >> c;
		list.add(c);
		list.save();
	}
	void searchContact()
	{
		string s;
		Contact c;
		cout << "Enter the phone number/ first name/ last name/ address/ email address!" << endl;
		cin >> s;
		int index = list.search2(s);
		if (index == -1)
		{
			cout << "The contact was not found or does not exist!";
		}
		else
		{
			cout << list.contactList[index];
		}
	}
	void editContact()
	{
		string s;
		Contact c;
		cout << "Enter the phone number of the contact to be modified!" << endl;
		cin >> s;
		int index = list.search(s);
		if (index == -1)
		{
			cout << "The contact was not found or does not exist!";
		}
		else
		{
			cout << list.contactList[index];
			s = list.contactList[index].tostring();
			cin >> c;
			list.add(c);
			list.remove(index);
			list.save();
		}
	}
	void removeContact()
	{
		string s;
		cout << "Enter the phone number of the contact to be deleted. This process is irreversible!" << endl;
		cin >> s;
		int index = list.search(s);
		if (index == -1)
		{
			cout << "The contact was not found or does not exist!";
		}
		else
		{
			list.remove(index);
			list.save();
			cout << "The contact has been successfully removed!";
		}
	}
	void returnMenu()
	{
		char choice;
		cout << "\nYou want to return to the Main Menu? (Y/N) >> ";
		cin >> choice;
		if (tolower(choice) == 'y')
		{
			Menu();
		}
		if (tolower(choice) == 'n')
		{
			exit(0);
		}
		else
		{
			cout << "Please enter a valid option!\n";
			returnMenu();
		}
	}
};

#endif