#include <iostream>
using namespace std;
class Queue_class
{
 int queue[12];//Queue
 int rear,front,size;//rear(points rear element) , front(points front element) , size(capacity of queue)
 public:
 void accept();
 void insertion();
 void deletion();
 void display();
};
void menu(Queue_class &);


//Accept function - Class: Queue_class
void Queue_class::accept()
{
 cout<<"Enter the size of the queue(Max-12): ";
 cin>>size;
 if(size < 1)
 {
    do            //Check size greater than 1 inorder to prevent underflow issues
    {
     cout<<"Enter valid size(Min-2 and Max-12): ";
     cin>>size;
    }while(size <= 1);
 }
 rear = -1;
 front = 0;
}


//Insertion function - Class: Queue_class
void Queue_class::insertion()
{
 cout<<'\n';
 char confirm;
 while(1)
 {
    rear++;
    if(rear >= size)
    {
     cout<<"\nQueue overflow";
     rear--;
     break;
    }
    else
    {
     cout<<"\nEnter the element here: ";
     cin>>queue[rear];
     cout<<"\nElement "<<queue[rear]<<" inserted into queue";
     cout<<"\nDo you want insert again(y/n): ";
     cin>>confirm;
     if(confirm != 'y'  && confirm != 'Y')
      break;
    }
 }
 if(rear < size)
  cout<<"\nInsertion completed";
}


//Delete function - Class: Queue_class
void Queue_class::deletion()
{
 bool flag = false; //flag(variable to ensure wheather the deletion operation is performed atleast one time)
 cout<<'\n';
 char confirm;
 while(1)
 {
    if(rear == -1)
    {
     cout<<"\nqueue underflow";
     break;
    }
    else
    {
     flag = true;
     cout<<"\nElement "<<queue[front]<<" deleted from queue";
     queue[front] = 0;
     if(front >= rear)
     {
        front = 0;
        rear = -1;
     }
     else
      front++;
     cout<<"\nDo you want delete again(y/n): ";
     cin>>confirm;
     if(confirm != 'y'  && confirm != 'Y')
      break;
    }
 }
 if(flag)
  cout<<"\nDeletion completed";
}


//Display function - Class: Queue_class
void Queue_class::display()
{
    int i;
    if(rear == -1)
     cout<<"\nQueue elements not found";
    else
    {
     cout<<"\nQueue elements are: ";
     for(i=front;i<=rear;i++)
      cout<<queue[i]<<'\t';
     cout<<"\nRear element is "<<queue[rear];
     cout<<"\nFront element is "<<queue[front];
    }
}


//Main function
int main()
{
  Queue_class obj;
  char confirm;
  obj.accept();
  do
  {
    menu(obj);
    cout<<"\n\nReturn to main menu(y/n): ";
    cin>>confirm;
  }while(confirm == 'y'||confirm == 'Y');     
  return 0;
}


//Menu function
void menu(Queue_class &obj)
{
  char option;

  cout<<"\n---------------------------------Main Menu---------------------------------\n";
  cout<<"1.)Perform insertion\n2.)Perform deletion\n3.)Display elements\n";
  cout<<"Input the option: ";
  cin>>option;
  switch(option)
  {
   case '1': obj.insertion();
           break;
   case '2': obj.deletion();
           break;
   case '3': obj.display();
            break;
   default: cout<<"Invalid input";
  }
}
