#ifndef BST_H
#define BST_H
#include <string>
#include <set.h>

using namespace std;
class BST                     //This BST is specific for the phone directory so its structure node is modified so template can't be used
{
    public:

        //BST ADT  (Phone Directory Interface)
        BST();
        virtual ~BST();
        void search_contact(string ContactName);
        void insert_contact(string ContactName,string ContactCity ,set<long long> phone_list);
        void remove_contact(string ContactName);
        void print_contacts();


    private:
        struct node
        {
            string name;
            set<long long> phone_store;
            string city;
            node* left;
            node* right;
        };
        node*root;

        //Functions to create the layer of Abstraction
        void  remove_node( string name,node*& root);
        node* search_node(string name,node*& root);
        node* findMin(node* root);
        void insert_node(string name,string city,set<long long> phone_store,node*& root);
        void InorderTraversal(node*& root);
        void delete_nodes(node*& root);     // to free up space
};

#endif // BST_H
