//Program Name: Concatenation of string using Linked List
#include <iostream>
using namespace std;


//For Linked list structures -  node & node2
struct n
{
 char data;
 struct n *ptr;
};
typedef struct n node;
struct n2
{
 char data2;
 struct n2 *ptr2;
};
typedef struct n2 node2;


class Concat
{
    char choice;
    node *first,*current,*list;
    node2 *first2,*current2,*list2;
    public:
    void input();
    void attach();
    void display();
};


void Concat::input()
{
    first = nullptr;
    first2 = nullptr;
    //Accepts characters for First linked_list
    do
    {
        list = new node;
        cout<<"Enter the character: ";
        cin>>list->data;
        list->ptr = nullptr;
        if(first == nullptr)
         first = current = list;
        else
        {
            current->ptr = list;
            current = list;
        }
        cout<<"Do you want to enter again: ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    
    //Accepts characters for Second linked_list
    cout<<"\nFor second string\n";
    do
    {
        list2 = new node2;
        cout<<"Enter the character: ";
        cin>>list2->data2;
        list2->ptr2 = nullptr;
        if(first2 == nullptr)
         first2 = current2 = list2;
        else
        {
            current2->ptr2 = list2;
            current2 = list2;
        }
        cout<<"Do you want to enter again: ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}


void Concat::attach()
{
    current2 = first2;
    
    //To attach Linked lists node & node2 for concatenation
    while(current2 != nullptr)
    {
        list = new node;
        current->ptr = list;
        current = list;
        list->data = current2->data2;
        current2 = current2->ptr2;
    }
    current = first;
}


//To diplay concatenated string(Without space)
void Concat::display()
{
    cout<<"\nConcatenated String: \n";
    while(current != nullptr)
    {
        cout<<current->data;
        current = current->ptr;
    }
    current = first;
    current2 = first2;
}


//Main Function starts
int main()
{
 Concat obj;
 obj.input();
 obj.attach();
 obj.display();
 return 0;
}
