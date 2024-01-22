#ifndef SET_H
#define SET_H

template <class T>               //This set ADT implemented using Template because it contain Single type of data
class set                       // Implementation of the set using the list
{
    public:
        set();
        virtual ~set();
        void add(T x);           // Add data in set without duplication
        void remove(T x);       // Remove data from set
        void display();        // Display the data in the set

    private:
        struct node             // Set data node
        {
            T element;
            node* next;
        };
        node* head;
        bool contain(T x);      // This function give SET property(uniqueness) to link-list

};

#endif // SET_H
