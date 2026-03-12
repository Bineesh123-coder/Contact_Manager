#include <iostream>
#include "contact_manager.h"
using namespace std;
int main()
{

    try{
        Contact_Manager ms;
        ms.Start();
    }
    catch(const exception &e)
    {
        cout<<"ERROR: Start Contact Manger"<<e.what()<<endl;
    }
    return 0;
}