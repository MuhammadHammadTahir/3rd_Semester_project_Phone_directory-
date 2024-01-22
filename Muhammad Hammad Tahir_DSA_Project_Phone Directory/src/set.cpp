#include "set.h"
#include <iostream>

using namespace std;

template <class T>
set<T>::set()
{
    head =NULL;                  // Initialization of set
}

template <class T>
set<T>::~set()                  // Destructor to free up the space
{
    node* previous;
    node* curr = head;
    while(curr!=NULL)
    {
        previous=curr;
        curr=curr->next;
        delete previous;
    }
}

template <class T>
void set<T>::add(T x)               // Implementation of insertion function in the set ADT   (maintaining the set property)
{
    if(!contain(x))                 // This will give the set property (uniqueness) by preventing duplication
    {
        node* new_node= new node;
        new_node->element=x;

        if(head==NULL)
        {
            new_node->next=NULL;
            head=new_node;
        }
        else
        {
            node* curr = head;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            new_node->next=NULL;
            curr->next=new_node;
        }
    }
    else
    {
      cout<<"\n!!!!!!!!!! You Entered Duplicate Number !!!!!!!!!\n";
    }
}

template <class T>
void set<T>::remove(T x)            // Implementation of deletion function in the set ADT
{
    node* previous;
    node* curr=head;
    while(curr!=NULL && curr->element!=x)       // Check for the required object is found that is to be removed
    {
        previous=curr;
        curr=curr->next;;
    }
    if(curr!=NULL)
    {
        previous->next=curr->next;
        delete curr;
    }
}

template <class T>
void set<T>::display()                      // Display data stored in set
{

    int i=1;
    node* curr=head;
    while(curr!=NULL)
    {
        cout<<endl<<"Phone No "<<i<<": "<<curr->element;        // i is specifically used for the case of Phone Directory to show the sequence of phone numbers
        curr=curr->next;
        i++;
    }
}

template <class T>
bool set<T>::contain(T x)                   // The core function that will grant the set property (uniqueness) by checking already present data
{
    node* curr =head;
    while(curr!=NULL && curr->element!=x)
    {
        curr=curr->next;
    }
    if(curr!=NULL)
    {
        return true;
    }
    else
        return false;
}
