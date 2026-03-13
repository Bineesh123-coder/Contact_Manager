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
        fast_search[c.name] = c.phone;
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
    //cin.ignore();
    getline(cin, c.phone);

    for(auto  &e : contacts)
    {
        if(e.phone == c.phone)
        {
            cout<<"this phone number already exit  please verify number"<<endl;
            return;
        }
    }
    
    cout<<"Enter Emial:";
    //cin.ignore();
    getline(cin, c.email);
    cout<<"Enter Address:";
    //cin.ignore();
    getline(cin, c.address);

    
    
    ofstream My_file("contact.txt", std::ios::app);
    My_file<<"\n"<<c.name<<" "<<c.phone<<" "<<c.email<<" "<<c.address<<"\n";
    My_file.close();

    contacts.push_back(c);
    fast_search[c.name] = c.phone;
    cout<<"Added Contact successfully"<<endl;

}

void Contact_Manager::Show_Contacts()
{
    try{
        cout<<"---------All contacts--------"<<endl;
        for(auto &e: contacts)
        {
            cout<<e.name<<" "<<e.phone<<" "<<e.email<<" "<<e.address<<endl;
        }
        

    }
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Show_Contacts()"<<e.what()<<endl;
    }

}

void Contact_Manager:: Fast_Search_Contact()
{
    try{

        cout<<"Enter contact Name:";
        string f_name;
        cin.ignore();
        getline(cin, f_name);

        if(fast_search.find(f_name) != fast_search.end())
        {
            cout<<"Contact found in list\n"<<f_name<<" "<<fast_search[f_name]<<endl;
            return;
        }

        cout<<f_name<<""<<"Contact not found in list"<<endl;
    }
    catch(const exception &e)
    {
        cout<<"ERROR:Contact_Manager::Fast_Search_Contact()"<<e.what()<<endl; 
    }
}

void Contact_Manager:: Partial_Search()
{
    try{

        cout<<"Enter contact Name:";
        string search_word;
        cin.ignore();
        getline(cin, search_word);
        bool  found = false;

        for(auto &e :contacts)
        {
            if(e.name.find(search_word) == 0)
            {
                found = true;
                cout<<"Contact found in list\n"<<e.name<<" "<<e.phone<<endl; 
            }
        }
        if(!found)
        {
            cout<<search_word<<""<<"Contact not found in list"<<endl;
        }
        
    }
    catch(const exception &e)
    {
        cout<<"ERROR:Contact_Manager::Partial_Search()"<<e.what()<<endl; 
    }
}

void Contact_Manager:: Search_Name_and_phone()
{
     try{
        cout<<"Search Contact\n1 Name\n2 phone No\n Enter choice:";
        int op;
        cin>>op;
        switch(op)
        {
            case 1:
            {
                cout<<"Enter contact Name:";
                string s_name;
                cin.ignore();
                getline(cin, s_name);
                bool found = false;
                for(size_t i = 0; i < contacts.size();i++)
                {
                    if(contacts[i].name == s_name)
                    {
                        found = true;
                        cout<< contacts[i].name<<" "<<contacts[i].phone<<" "<<contacts[i].email<<" "<<contacts[i].address<<endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout<<"Contact Name  no found"<<endl;
                }
                break;
            }
            case 2:
            {
                cout<<"Enter contact Phone no:";
                string s_phone;
                cin.ignore();
                getline(cin, s_phone);
                bool found = false;
                for(size_t i = 0; i < contacts.size();i++)
                {
                    if(contacts[i].phone == s_phone)
                    {
                        found = true;
                        cout<< contacts[i].name<<" "<<contacts[i].phone<<" "<<contacts[i].email<<" "<<contacts[i].address<<endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout<<"Contact phone number no found"<<endl;
                }
                break;
            }
            default:
            {
                cout<<"Please enter valid option"<<endl;
                break;
            }
        }
        
    }
    catch(const exception &e)
    {
        cout<<"ERROR:Contact_Manager::Search_Name_and_phone()"<<e.what()<<endl; 
    }
}
void Contact_Manager:: Search_Contact()
{   
    try{

        cout<<"Search Contact\n1 Search by Name(fast search)\n2 Search by Name or Phone\n3 Partial Search (first letters)\n4 Back\nEnter choice:";
        int option;
        cin>>option;
        switch(option)   
        {
            case 1:
            {   
                Fast_Search_Contact();
                break;
            }
            case 2:
            {
                Search_Name_and_phone();
                break;
            }
            case 3:
            {
                Partial_Search();
                break;
            }
            case 4:
            {
                cout<<"Back to Main"<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid option Back to Main"<<endl;
                break;
            }
        }
    }         
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Search_Contact()"<<e.what()<<endl;
    }

}

void Contact_Manager:: Update_Contact()
{
    try{
        cout<<"Enter Update Contact Name:"<<endl;
        string s_name;
        cin.ignore();
        getline(cin, s_name);

        
        bool found = false;
        for(size_t i = 0; i < contacts.size();i++)
        {
            if(contacts[i].name == s_name)
            {
                found = true;
                cout<< contacts[i].name<<" "<<contacts[i].name<<" "<<contacts[i].email<<" "<<contacts[i].address<<endl;
                cout<<"1 Update Name\n2 Update Phone\n3 Update Email\n4 Update Address\nEnter choice:"<<endl;
                int option;
                cin>>option;

                switch(option)
                {
                    case 1:
                    {
                        cout<<"Enter Update Name:";
                        string u_name;
                        cin.ignore();
                        getline(cin, u_name);

                        contacts[i].name == u_name;
                        cout<<"Update Name successfully"<<endl;
                        break;

                    }
                    case 2:
                    {
                        cout<<"Enter Update Phone No:";
                        string u_phone;
                        cin.ignore();
                        getline(cin, u_phone);

                        contacts[i].phone == u_phone;
                        cout<<"Update Phone No successfully"<<endl;
                        break;

                    }
                    case 3:
                    {
                        cout<<"Enter Update email:";
                        string u_email;
                        cin.ignore();
                        getline(cin, u_email);

                        contacts[i].email == u_email;
                        cout<<"Update email successfully"<<endl;
                        break;

                    }
                    case 4:
                    {
                        cout<<"Enter Update Address:";
                        string u_address;
                        cin.ignore();
                        getline(cin, u_address);

                        contacts[i].address == u_address;
                        cout<<"Update Address successfully"<<endl;
                        break;

                    }
                    default:
                    {
                        cout<<"please Enter valid update option"<<endl;
                        break;
                    }
                }
                cout<< contacts[i].name<<" "<<contacts[i].name<<" "<<contacts[i].email<<" "<<contacts[i].address<<endl;
                break;
            }
        }
        if(!found)
        {
            cout<<"Contact no found in list"<<endl;
        }
        

    }
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Search_Contact()"<<e.what()<<endl;
    }

}

void Contact_Manager::Sort_Contacts()
{
    try{

        sort(contacts.begin(), contacts.end(),
        [](Contact a, Contact b){
            return a.name < b.name;
        });
        
        cout<<"sorted contacts successfully"<<endl;

    }
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Show_Contacts()"<<e.what()<<endl;
    }

}

void Contact_Manager::Save_Contacts()
{
    

    ofstream My_file("contact.txt");
    
    
    for(auto &e : contacts)
    {
        My_file<<"\n"<<e.name<<" "<<e.phone<<" "<<e.email<<" "<<e.address<<"\n";
    }

    My_file.close();
    

}

void Contact_Manager:: Delete_Contact()
{
    try{
        cout<<"Enter contact Name:";
        string s_name;
        cin.ignore();
        getline(cin, s_name);
        bool found = false;
        for(size_t i = 0; i < contacts.size();i++)
        {
            if(contacts[i].name == s_name)
            {
                found = true;
                cout<< contacts[i].name<<" "<<contacts[i].phone<<" "<<contacts[i].email<<" "<<contacts[i].address<<endl;
                contacts.erase(contacts.begin()+i);
                cout<<"Delete contact sucessfully"<<endl;
                Save_Contacts();
                break;
            }
        }
        if(!found)
        {
            cout<<"Contact no found to delete"<<endl;
        }
        
        
    }
    catch(const exception &e )
    {
        cout<<"ERROR:Contact_Manager::Search_Contact()"<<e.what()<<endl;
    }

}
void Contact_Manager::User_inputs()
{
    int input;
    do{
        cout<<" \n1 Add Contact\n2 Show Contacts\n3 Search Contact\n4 Update Contact\n5 Sort Contacts\n6 Save Contacts\n7 Delete Contacts\n8 Exit\nEnter choice:";
        cin>>input;
        switch (input)
        {
        case 1:
        {
            
            Add_Contact(); 
            break;
        }
        case 2:
        {
            Show_Contacts();
            break;
        }
        case 3:
        {
            Search_Contact();
            break;
        }
        case 4:
        {
            Update_Contact();
            break;
        }
        case 5:
        {
            Sort_Contacts();
            Show_Contacts();
            break;
        }
        case 6:
        {
           Save_Contacts();
            break;
        }
        case 7:
        {
           Delete_Contact();
           break;
        }
        case 8:
        {
           cout<<"EXIT\n";
           break;
        }
            
        default:
            cout<<"Please Enter valid input"<<endl;
            break;
        }

    }while(input != 8);
}