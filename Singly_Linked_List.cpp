//Under Research

/*
#include <iostream>
using namespace std;
struct n
{
    int data;
    struct n *ptr;
};
typedef struct n node;


void LinkedList();
int main()
{
    LinkedList();
    return 0;
}


//Linked list program
void LinkedList()
{
    node *list,*first,*current;
    char c;
    first = nullptr;
    do
    {
        list = new node;
        cout<<"Enter the value: ";
        cin>>list->data;
        list->ptr = nullptr;
        if(first == nullptr)
         current = first = list;
        else
        {
            current->ptr = list;
            current = list;
        }
        cout<<"Do you want to input again(y/n): ";
        cin>>c;
    }while(c == 'y' || c == 'Y');
    
    //Insertion at beginning
    do
    {
        list = new node;
        cout<<"Enter the data to insert: ";
        cin>>list->data;
        list->ptr = first;
        first = list;
        cout<<"Do you want to insert again: ";
        cin>>c;
    }while(c == 'Y' || c == 'y');
    
    //Display
    current = first;
    while(current != nullptr)
    {
        cout<<current->data<<endl;
        current = current->ptr;
    }
    
    //Deletion
    current = first;
    while(current != nullptr)
    {
        first = first->ptr;
        delete current;
        current = first;
    }
}*/



//Model 2
/*#include <iostream>
using namespace std;
struct n
{
    int data;
    struct n *ptr;
};
typedef struct n node;


void LinkedList();
int main()
{
    LinkedList();
    return 0;
}


void LinkedList()
{
    node *first,*current,*list;
    char c;
    first = nullptr;
    do
    {
        list = new node;
        cout<<"Enter here: ";
        cin>>list->data;
        list->ptr = nullptr;
        if(first == nullptr)
         first=current=list;
        else
        {
            list->ptr = first;
            first->ptr = nullptr;
            first = list;
        }
        cout<<"Do you want insert again (y/n): ";
        cin>>c;
    }while(c=='Y'||c=='y');
    
    
    current = first;
    while(current != nullptr)
    {
        first = first->ptr;
        delete current;
        current = first;
    }
}*/
