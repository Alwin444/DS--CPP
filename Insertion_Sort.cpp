#include <iostream>
using namespace std;
class Sorter
{
   int ar[10],i,j,size,temp;
   public:
   void accept();
   void display();
   int pos();
   void sort();
};

int Sorter::pos()
{
    int pos;
    for(i=0;i<size-1;i++)
    {
        if(ar[i] > ar[i+1])
        {
         pos = i;
         break;
        }
    }
    return pos;
}

void Sorter::sort()
{
    int p = pos();
    for(i=p;i<size;i++)
    {
        for(j=i;j>0;j--)
        {
            if(ar[j]<ar[j-1])
            {
                temp = ar[j];
                ar[j] = ar[j-1];
                ar[j-1] = temp;
            }
        }
    }
}

void Sorter::accept()
{
    cout<<"Enter size of array: ";
    cin>>size;
    for(i=0;i<size;i++)
    {
        cout<<"Enter here: ";
        cin>>ar[i];
    }
}

void Sorter::display()
{
    for(i=0;i<size;i++)
     cout<<ar[i]<<'\t';
}


int main()
{
    Sorter obj;
    obj.accept();
    obj.sort();
    obj.display();
    return 0;
}
