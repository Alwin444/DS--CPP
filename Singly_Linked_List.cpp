//Under Devolopment

#include <iostream>
using namespace std;


struct NODE
{
 int data;
 struct NODE *ptr;
}
typedef struct NODE node;


class Operation
{
 int count = 0;
 node *list,*first,*current;
 public:
 Operation()
 {first = nullptr;}
 void ins_beg();
 void ins_last();
 void ins_spe();
 void del_beg();
 void del_last();
 void del_spe();
 void display();
 ~Operation();
};


void Operation::ins_beg()
{
 char choice;
 do
 {
  count++;
  list = new node;
  cout<<"Enter the number: ";
  cin>>list->data;
  list->ptr = nullptr;
  if(first == nullptr)
   first = current = list;
  else
  {
   list->ptr = first;
   first = list;
  }
  cout<<"Do you want to enter again(y/n): ";
  cin>>choice;
 }while(choice == 'Y' || choice == 'y');
}


void Operation::ins_last()
{
 char choice;
 do
 {
  count++;
  list = new node;
  cout<<"Enter the number: ";
  cin>>list->data;
  list->ptr = nullptr;
  if(first == nullptr)
   first = current = list;
  else
  {
   current->ptr = list;
   current = list;
  }
  cout<<"\nDo you want to enter again(y/n): ";
  cin>>choice;
 }while(choice == 'Y' || choice == 'y');
}


void Operation::ins_spe()
{
 int pos,dup_count = 1;
 node *temp;
 if(count<1)
  cout<<"Not sufficient nodes to perform this";
 else
 {
  cout<<"Enter the position to be inserted: ";
  cin>>pos;
  if(pos<1||pos>count)
   cout<<"Only "<<count<<" nodes are present enter valid number";
  else
  {
   do
   {
    count++;
    list = new node;
    cout<<"Enter the data: ";
    cin>>list->data;
    list->ptr = nullptr;
    current = first;
    while(dup_count < pos-1)
    {  
     current = current->ptr;
     dup_count++;
    }
    temp = current->ptr;
    current->ptr = list;
    list->ptr = temp;
    current = current->ptr;
    dup_count = 1;
    while(current->ptr != nullptr)
     current = current->ptr;
    cout<<"Do you want to perform again(y/n): ";
   }while(choice == 'Y' || choice == 'y');
  }
 }
}


void Operation::del_beg()
{
 char choice;
 node *temp = nullptr;
 do
 {
  if(count<1)
   cout<<"Not enough nodes to perform operation";
  else
  {
   temp = first;
   first = first->ptr;
   delete temp;
   if(count == 1)
    first = nullptr;
   count--;
   cout<<"Do you want to perform again(y/n): ";
   cin>>choice;
  }
 }while(choice == 'y' || choice == 'Y');
}


void Operation::del_last()
{
 char choice;
 node *temp = nullptr;
 do
 {
  if(count<1)
   cout<<"Not enough nodes to perform operation";
  else
  {
   temp = first;
   while(temp->ptr != current)
    temp = temp->ptr;
   delete current;
   current = temp;
   current->ptr = nullptr;
   if(count == 1)
    first = nullptr;
   count--;
   cout<<"Do you want to perform again(y/n): ";
   cin>>choice;
  }
 }while(choice == 'Y' || choice == 'y');
}


void Operation::del_spe()
{
 char choice;
 node *temp,*del;
 int pos,dup_count = 2;
 do
 {
  if(count<1)
   cout<<"Not enough nodes to perform operation";
  else
  {
   cout<<"Enter the position to delete: ";
   cin>>pos;
   if(pos<1 || pos>count)
    cout<<"Enter valid number";
   else
   {
    temp = first;
    while(dup_count <= pos-1)
    {
     temp = temp->ptr;
     dup_count++;
    }
    del = temp->ptr;
    temp->ptr = del->ptr;
    delete del;
    if(count == 1)
     first = nullptr;
    count--;
    cout<<"Do you want to perform again(y/n): ";
    cin>>choice;
   }
  }
 }while(choice == 'Y' || choice == 'y');
}
  
  
 
 


  

 
  
 
 
