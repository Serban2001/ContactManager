# ContactManager

This is a simple contact management system implemented in C++. It allows users to perform various operations on a list of contacts, such as viewing, adding, searching, editing, and deleting contacts.

<img width="573" alt="meniu" src="https://github.com/Serban2001/ContactManager/assets/127775479/0cf531f7-224c-40a9-94c6-5fb67efd5f31">

## Features

1. View the list of contacts
2. Add a new contact
3. Search for a contact by phone number, first name, last name, address, or email address
4. Edit an existing contact
5. Delete a contact
6. Save the contact list to a file for future use

## Getting Started

To run the program, you will need a C++ compiler installed on your system. Simply compile and execute the main.cpp file.

```zsh
g++ -o App App.cpp
```
```zsh
./App
```

## Usage

Follow the on-screen instructions to navigate through the menu and perform various operations on the contact list.

## File Structure

**main.cpp:** The entry point of the program. It contains the main function that initializes the menu.

**Menu.h:** Header file for the Menu class.

**Contact.h:** Header file for the Contact class, which represents a single contact.

**ContactList.h:** Header file for the ContactList class, which manages a list of contacts.

**ContactList.txt:** File used to persistently store the contact list.
