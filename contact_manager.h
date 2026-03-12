#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include<vector>
#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

class Contact{
public:
    string name;
    string phone;
    string email;
    string address;

};
class Contact_Manager{
public:
    vector<Contact> contacts;
    int success = 0;
    int failure = -1;
    void Start();
    int Load_Contact();
    void User_inputs();
    void Add_Contact();

};

#endif