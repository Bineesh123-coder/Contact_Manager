#include "contact_manager.h"

int  Contact_Manager::Load_Contact()
{   
    ifstream file("contact.txt");

    if(!file)
    {
        cout<<"ERROR: Cannot open contact.txt"<<endl;
        return failure;
    }

    Contact c;

    while(file >> c.name >> c.phone >> c.email >> c.address)
    {
        contacts.push_back(c);
    }

    file.close();

    return success;    

}

void Contact_Manager::Start()
{
    try{

       if(Load_Contact() != success)
        {
            cout<<"ERROR: Load Contact Failed"<<endl;
            return;
        }
        User_inputs();
        

    }
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Start()"<<e.what()<<endl;
    }

}
void Contact_Manager::Add_Contact()
{   

    Contact c;
    cout<<"Enter Name:";
    cin.ignore();
    getline(cin, c.name);
    cout<<"Enter phone No:";
    cin.ignore();
    getline(cin, c.phone);
    cout<<"Enter Emial:";
    cin.ignore();
    getline(cin, c.email);
    cout<<"Enter Address:";
    cin.ignore();
    getline(cin, c.address);
    
    ofstream My_file("contact.txt", std::ios::app);
    My_file<<c.name<<" "<<c.phone<<" "<<c.email<<" "<<c.address<<"\n";
    My_file.close();

    contacts.push_back(c);

}

void Contact_Manager::User_inputs()
{
    int input;
    do{
        cout<<" \n1 Add Contact\n2 Show Contacts\n3 Search Contact\n4 Update Contact\n5 Sort Contacts\n6 Save Contacts\n7 Exit\nEnter choice:";
        cin>>input;
        switch (input)
        {
        case 1:
        {
            
            Add_Contact(); 
            cout<<"Added Contact successfully"<<endl;
            break;
        }
        case 2:
        {
            
            break;
        }
        case 3:
        {
            
            break;
        }
        case 4:
        {
            
            break;
        }
        case 5:
        {
            
            break;
        }
        case 6:
        {
           
            break;
        }
        case 7:
        {
           cout<<"EXIT\n";
        }
            
        default:
            cout<<"Please Enter valid input"<<endl;
            break;
        }

    }while(input != 7);
}