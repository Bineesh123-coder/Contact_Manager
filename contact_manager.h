#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include<vector>
#include <fstream>
#include <exception>
#include <iostream>
#include <algorithm>

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
    void Show_Contacts();
    void Search_Contact();
    void Update_Contact();
    void Sort_Contacts();
    void Save_Contacts();
    void Delete_Contact();

};

#endif