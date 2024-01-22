#include "BST.h"
#include <iostream>
#include <string>
#include <set.h>

using namespace std;

BST::BST() {
    root = NULL;                // Initialization of BST (Phone Directory)
}

BST::~BST() {
    delete_nodes(root);        // Free up space
}

void BST::search_contact(string ContactName) {
    node* value = search_node(ContactName, root);           // Searching function will return the required person's data
    if (value == NULL) {
        cout<<"\nContact not found\n";
    } else {
        cout<<"Name : "<<root->name<<"\n";
        cout<<"City : "<<root->city;
        root->phone_store.display();                        // Display function of Set ADT that will display the data stored in set  (Phone Numbers)
        cout<<endl;

    }
}

void BST::insert_contact(string ContactName, string ContactCity,set<long long> phone_list) {
    insert_node(ContactName,ContactCity,phone_list, root);
}
void BST::print_contacts()
{
    InorderTraversal(root);
}
BST::node* BST::search_node(string ContactName, node*& root) {              // Core Searching function
    if (root == NULL) {
        return NULL;
    } else {
        if (ContactName < root->name) {                                      // Check the left subtree (eliminate half elements from searching)
            return search_node(ContactName, root->left);
        } else if (ContactName > root->name) {                               // Check the right subtree (eliminate half elements from searching)
            return search_node(ContactName, root->right);
        } else {
            return root;
        }
    }
}


void BST::insert_node(string ContactName,string ContactCity,set<long long> phone_list, node*& root) {       //Core Insertion Function
    if (root == NULL) {
        root = new node;
        root->name = ContactName;
        root->city = ContactCity;
        root->phone_store=phone_list;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (ContactName < root->name)                                                                   // insertion in the left subtree

            {
            insert_node(ContactName,ContactCity,phone_list, root->left);
            }
        else if (ContactName > root->name)                                                             // insertion in the right subtree
        {
            insert_node(ContactName,ContactCity,phone_list, root->right);
        }
    }
}

void BST::remove_contact(string ContactName) {
    remove_node(ContactName, root);
}

BST::node* BST::findMin(node* root) {                               // find the minimum element (used in remove node step)
    if (root != NULL) {
        findMin(root->left);
    } else {
        return root;
    }
}

void BST::remove_node(string ContactName, node*& root) {
    if (root != NULL) {
        if (ContactName < root->name) {                             // remove from the left sub-tree
            remove_node(ContactName, root->left);
        } else if (ContactName > root->name) {                      // remove from the right sub-tree
            remove_node(ContactName, root->right);
        } else {                                                    // Two child senario
            if (root->left != NULL && root->right != NULL) {
                root->name = findMin(root->right)->name;
                remove_node(root->name, root->right);
            } else {                                               //no child or one child senario
                node* oldNode = root;
                root = (root->left != NULL) ? root->left : root->right;
                delete oldNode;
            }
        }
    }
}

void BST::delete_nodes(node*& root) {           //delete the whole tree by recursive calls
    if (root != NULL) {
        delete_nodes(root->left);               //recursive calls
        delete_nodes(root->right);
        delete root;
    }
}
void BST::InorderTraversal(node* & x)           // Displaying data in tree in In-order traversal
{
    if (x!=NULL)
    {
        InorderTraversal(x->left);
        cout<<"NAME : "<<x->name<<endl<<"CITY : "<<x->city;
        x->phone_store.display();               //display function of set ADT to show Phone numbers
        cout<<endl<<endl;
        InorderTraversal(x->right);
    }
}
