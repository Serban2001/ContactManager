#ifndef CONTACTLIST
#define CONTACTLIST

#include "Contact.h"
#include <iostream>
#include <fstream>
#include <vector>

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}

class ContactList
{
public:
    vector<Contact> contactList;

    ContactList()
    {
        string v;
        ifstream fin("ContactList.txt");
        while (getline(fin, v))
        {
            Contact c;
            vector<string> rez = tokenize(v, ';');
            c.phoneNumber = rez[0];
            c.firstName = rez[1];
            c.lastName = rez[2];
            c.address = rez[3];
            c.emailAddress = rez[4];
            this->contactList.push_back(c);
        }
        fin.close();
    }
    vector<Contact> get()
    {
        return this->contactList;
    }

    int search(string s)
    {
        for (int i = 0; i < this->contactList.size(); i++)
        {
            if (this->contactList[i].getPhoneNumber() == s)
            {
                return i;
            }
        }
        return -1;
    }
    int search2(string s)
    {
        for (int i = 0; i < this->contactList.size(); i++)
        {
            if (this->contactList[i].getPhoneNumber() == s || this->contactList[i].getFirstName() == s ||
                this->contactList[i].getLastName() == s || this->contactList[i].getAddress() == s ||
                this->contactList[i].getEmailAddress() == s)
                return i;
        }
        return -1;
    }
    void add(Contact &c)
    {
        this->contactList.push_back(c);
    }
    void save()
    {
        ofstream fout("ContactList.txt");
        for (Contact a : this->contactList)
        {
            fout << a.tostring();
        }
        fout.close();
    }
    void remove(int index)
    {
        this->contactList.erase(this->contactList.begin() + index);
    }
};

#endif