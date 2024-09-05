#include <iostream>
using namespace std;


//Structure for Linked_List -Singly
struct n
{
    int data;         //Variables: data-(to store values) , ptr-(pointer to point address) 
    struct n *ptr;
};
typedef struct n node;


//Class 'Call' to perform Linked List operation
class Call
{
    node *first,*current,*list;        //Variables:  first(Points to first node) , current(Points to node has NULL in link part) , list(For the creation of nodes)
    public:
    void accept();
    void display();
    ~Call();
};


//Accept function
void Call::accept()
{
    char choice;
    first = nullptr;
    do
    {
        list = new node;
        cout<<"Enter the value: ";
        cin>>list->data;
        list->ptr = nullptr;
        list->ptr = nullptr;
        if(first == nullptr)
         first = current = list;
        else
        {
          current->ptr = list;
          current = list;
        }
        cout<<"Do you want to enter the value again(y/n): ";
        cin>>choice;
     }while(choice == 'Y' || choice == 'y');
}


//Display function
void Call::display()
{
     current = first;
     cout<<"\nElements in linked list: \n";
     while(current != nullptr)
     {
         cout<<current->data<<endl;
         current = current->ptr;
     }
}


//Deallocation function
Call::~Call()
{
    current = first;
    while(current != nullptr)
    {
        first = first->ptr;
        delete current;
        current = first;
    }
}


//Main function to execute
int main()
{
    Call obj;
    obj.accept();
    obj.display();
    return 0;
}
