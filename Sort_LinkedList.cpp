#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *ptr;
};
typedef struct Node node;


class Sort
{
    node *list,*first,*current,*curr2,*temp_address;
    int min,temp;
    public:
    void input();
    void sort();
    void display();
};


void Sort::input()
{
    first = nullptr;
    char choice;
    do
    {
        list = new node;
        cout<<"Enter the data: ";
        cin>>list->data;
        list->ptr = nullptr;
        if(first == nullptr)
         first = current = list;
        else
        {
            current->ptr = list;
            current = current->ptr;
        }
        cout<<"Again: ";
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');
}


void Sort::sort()
{
   for(current = first;current->ptr !=  nullptr;current = current->ptr)
    {
        min = current->data;
        temp_address = current;
        for(curr2=current->ptr;curr2 != nullptr;curr2 = curr2->ptr)
        {
            if(min > curr2->data)
            {
             min = curr2->data;
             temp_address = curr2;
            }
        }
        temp = current->data;
        current->data = min;
        temp_address->data = temp;
    } 
}


void Sort::display()
{
    cout<<"\nSorted elements: \n";
    for(current = first;current != nullptr;current = current->ptr)
     cout<<current->data<<'\t';
}


int main()
{
    Sort obj;
    obj.input();
    obj.sort();
    obj.display();
    return 0;
}
