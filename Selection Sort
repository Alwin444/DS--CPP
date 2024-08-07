#include <iostream>
using namespace std;
class Sorter
{
    int ar[10],i,j,temp,size,pos;
    public:
    void accept();
    void display();
    void sort();
};

void Sorter::accept()
{
    cout<<"Enter the size: ";
    cin>>size;
    for(i=0;i<size;i++)
    {
        cout<<"Enter here: ";
        cin>>ar[i];
    }
}

void Sorter::sort()
{
    int min_term;
    for(i=0;i<size;i++)
    {
        min_term = ar[i];
        pos = i;
        for(j=i;j<size-1;j++)
        {
            if(ar[j+1]<min_term)
            {
                temp = ar[pos];
                ar[pos] = ar[j+1];
                ar[j+1] = temp;
                pos = j+1;
            }
        }
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
