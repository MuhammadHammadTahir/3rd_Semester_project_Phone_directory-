#include <iostream>
#include <string.h>
#include <cstdlib>
#include <BST.h>
#include <set.h>

using namespace std;

int main()
{
    BST PhoneDirectory;                               //BST object created
    char opt, op='1';
    string ContactName,ContactCity;
    long long phoneno;
    while(1)
    {
        cout<<"\n********************MAIN MENU********************\n";
        cout<<"1. ADD CONTACT.\n2. SEARCH CONTACT.\n3. REMOVE CONTACT.\n4. PRINT ALL CONTACTS.\n5. EXIT.\n";
        cout<<"\nOption : ";
        cin>>opt;
        cout<<endl;
        set<long long> phone_list;
        switch(opt)
        {
        case '1' :
            cout<<"Name : ";
            cin.ignore();                                // To clear the Input stream
            std::getline(std::cin, ContactName);         //To take the Full name (multiple strings as input)
            cout<<"City : ";
            cin>>ContactCity;
            while(op!='2')
            {
                cout<<"Phone NO : ";
                cin>>phoneno;
                phone_list.add(phoneno);
                cout<<"\nDo You Want To Add Another Number ?    (Press 1 For Yes) : (Press 2 For NO) ";
                cin>>op;
                cout<<endl;
            }
            PhoneDirectory.insert_contact(ContactName,ContactCity,phone_list);     //Insertion In BST
            op='1';
            break;
        case '2' :
            cout<<"Name : ";
            cin>>ContactName;
            cout<<endl;
            PhoneDirectory.search_contact(ContactName);       //Searching in BST
            break;
        case '3' :
            cout<<"Name : ";
            cin>>ContactName;
            PhoneDirectory.remove_contact(ContactName);       // Deletion in BST
            break;
        case '4' :
            PhoneDirectory.print_contacts();                //Print Tee
            break;
        case '5' :
            exit(0);
        }
    }
}
