#include <iostream>
using namespace std;

int count = 0;
int conf = 0;
struct NODE
{
 int data;
 struct NODE *ptr;
};
typedef struct NODE node;


class Operation
{
 node *list,*first,*current;
 public:
 Operation()
 {first = NULL;}
 void ins_beg();
 void ins_last();
 void ins_spe();
 void del_beg();
 void del_last();
 void del_spe();
 void display();
 ~Operation();
};
void menu(Operation &);

void Operation::ins_beg()
{
 char choice;
 do
 {
  count++;
  list = new node;
  cout<<"Enter the number: ";
  cin>>list->data;
  list->ptr = NULL;
  if(first == NULL)
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
  list->ptr = NULL;
  if(first == NULL)
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
 node *tempc;
 int pos,dup_count = 1;
 char choice;
 node *temp;
 if(count<1)
  cout<<"Not sufficient nodes to perform this";
 else
 {
   do
   {
    cout<<"Enter the position to be inserted: ";
    cin>>pos;
    if(pos<1||pos>count)
     cout<<"Only "<<count<<" nodes are present enter valid number";
    if(pos == 1)
    {
     count++;
     list = new node;
     cout<<"Enter the data: ";
     cin>>list->data;
     list->ptr = first;
     first = list;
    }
    else
    {
     count++;
     list = new node;
     cout<<"Enter the data: ";
     cin>>list->data;
     list->ptr = NULL;
     tempc = first;
     while(dup_count < pos-1)
     {  
      tempc = tempc->ptr;
      dup_count++;
     }
     temp = tempc->ptr;
     tempc->ptr = list;
     list->ptr = temp;
     dup_count = 1;
    }
    cout<<"Do you want to perform again(y/n): ";
    cin>>choice;
   }while(choice == 'Y' || choice == 'y');
 }
}


void Operation::del_beg()
{
 char choice;
 node *temp = NULL;
 do
 {
  if(count<1)
  {
   cout<<"Not enough nodes to perform operation";
   choice = 'n';
  }
  else
  {
   temp = first;
   first = first->ptr;
   delete temp;
   if(count == 1)
    first = NULL;
   count--;
   cout<<"Do you want to perform again(y/n): ";
   cin>>choice;
  }
 }while(choice == 'y' || choice == 'Y');
}


void Operation::del_last()
{
 char choice;
 node *temp = NULL;
 do
 {
  if(count<1)
  {
   cout<<"Not enough nodes to perform operation";
   choice = 'n';
  }
  else
  {
   temp = first;
   if(count > 1)
   {
    while(temp->ptr != current)
     temp = temp->ptr;
    delete current;
    current = temp;
    current->ptr = NULL;
   }
   else
   {
    delete current;
    current=temp=NULL;
   }
   if(count == 1)
    first = NULL;
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
 if(count<1)
 {
  cout<<"Not enough nodes to perform operation";
  choice = 'n';
 }
 else
 {
  do
  {
   cout<<"Enter the position to delete: ";
   cin>>pos;
   if(pos<1 || pos>count)
    cout<<"Enter valid number";
   else
   {
     temp = first;
     if(pos = 1)
     {
      first = first->ptr;
      delete temp;
     }
     else
     {
      while(dup_count < pos)
      {
       temp = temp->ptr;
       dup_count++;
      }
      del = temp->ptr;

      if(del->ptr != NULL)
      {
       temp->ptr = del->ptr;
       delete del;
      }
      else
      {
       delete del; 
       temp->ptr = NULL;
      }
        
     }
     if(count == 1)
      first = NULL;
     count--;
     dup_count = 2;
     cout<<"Do you want to perform again(y/n): ";
     cin>>choice;
   }
  }while(choice == 'Y' || choice == 'y');
 }
}


void Operation::display()
{
 node *temp;
 int dupcount = 1;
 if(count<1)
  cout<<"No nodes!";
 else
 {
  temp = first;
  while(temp != NULL)
  {
   cout<<"Node "<<dupcount<<" data: "<<temp->data<<endl;
   temp = temp->ptr;
   dupcount++;
  }
 }
}


Operation::~Operation()
{
 while(first = NULL)
 {
  current = first;
  first = first->ptr;
  delete current;
 }
}


int main()
{
 Operation obj;
 char cont;
 do
 {
  cont = 'n';
  menu(obj);
  if(conf != 1)
  {
   cout<<"\n\nDo you want to return to main menu(y/n): ";
   cin>>cont;
  }
 }while(cont == 'Y' || cont == 'y');
 return 0;
}


void menu(Operation &obj)
{
 char option;

  cout<<"\n---------------------------------Main Menu---------------------------------\n";
  cout<<"1.)Perform insertion at begining\n2.)Perform insertion at end\n3.)Perform insertion at Specified Position\n4.)Perform deletion at begining\n5.)Perform deletion at end\n6.)Perform deletion at specified position\n7.)Display elements\n8.)Quit\t\tTotal nodes: "<<count<<"\n\n";
  cout<<"Input the option: ";
  cin>>option;
  switch(option)
  {
   case '1': obj.ins_beg();
           break;
   case '2': obj.ins_last();
           break;
   case '3': obj.ins_spe();
            break;
   case '4': obj.del_beg();
            break;
   case '5': obj.del_last();
            break;
   case '6': obj.del_spe();
            break;
   case '7': obj.display();
            break;
   case '8': conf = 1;
            break;
   default: cout<<"Invalid input";
  }
}

																 
