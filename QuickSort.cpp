#include <iostream>
using namespace std;
class Sorter
{
	int ar[10],i,j,temp,pivot,pos;
public:
	void accept(int size);
	void sort(int low,int high);
	void display(int size);
};

void Sorter::accept(int size)
{
	for(i=0; i<size; i++)
	{
		cout<<"Enter here: ";
		cin>>ar[i];
	}
}

void Sorter::sort(int low,int high)
{
	if(low < high)
	{
		pivot = ar[high];
		i = low-1;
		for(j=low; j<high; j++)
		{
			if(ar[j]<pivot)
			{
				i++;
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
		pos = i+1;
		temp = pivot;
		ar[high] =  ar[pos];
		ar[pos] = temp;
		//Left partion
		sort(low,pos-1);
		//Right partion
		sort(pos+1,high);
	}
}

void Sorter::display(int size)
{
	for(i=0; i<size; i++)
		cout<<ar[i]<<'\t';
}


int main()
{
	Sorter obj;
	int size;
	cout<<"Enter the size: ";
	cin>>size;
	obj.accept(size);
	obj.sort(0,size-1);
	obj.display(size);
	return 0;
}
