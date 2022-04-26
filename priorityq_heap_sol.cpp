// C++ code to implement priority-queue
// using array implementation of
// binary heap

#include <bits/stdc++.h>
using namespace std;

int H[50];
int size = -1;


int parent(int i)
{
    extern int size;
	return (i - 1) / 2;
}


int leftChild(int i)
{
    extern int size;
	return ((2 * i) + 1);
}

int rightChild(int i)
{

    extern int size;
	return ((2 * i) + 2);
}

void shiftUp(int i)
{
    extern int size;
	while (i > 0 && H[parent(i)] < H[i]) 
    {
		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}


void shiftDown(int i)
{
    extern int size;
	int maxIndex = i;


	int l = leftChild(i);
	if (l <= size && H[l] > H[maxIndex]) 
    {
		maxIndex = l;
	}


	int r = rightChild(i);
	if (r <= size && H[r] > H[maxIndex]) 
    {
		maxIndex = r;
	}

	
	if (i!=maxIndex) 
    {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}


void insert(int p)
{
    extern int size;
	size = size + 1;
	H[size] = p;
	shiftUp(size);
}

int extractMax()
{
    extern int size;
	int result = H[0];
	H[0] = H[size];
	size = size - 1;
	shiftDown(0);
	return result;
}


void changePriority(int i, int p)
{
    extern int size;
	int oldpriority = H[i];
	H[i] = p;

	if(p>oldpriority) 
    {
		shiftUp(i);
	}
	else 
    {
		shiftDown(i);
	}
}


int getMax()
{
    extern int size;
	return H[0];
}


void remove(int i)
{
    extern int size;
	H[i] = getMax() + 1;
	shiftUp(i);

	//deleting by maing it maximum
	extractMax();
}

void printq()
{
    extern int size;
    int i = 0;
	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}
	cout << "\n";
}


int main()
{
    extern int size;
	/*45 31 14 13 20 7 11 12 7 */
    
    int n,a;
    cout<<"\nEnter the number and values to inserted in priority queue\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        insert(a);
    }

	printq();
	
	// Node with maximum priority
	cout << "Node with maximum priority : "<< extractMax() << "\n";
    cout << "Priority queue after extracting max : ";
    printq();
	

	// Change the priority of element present at index 4 to 35
	changePriority(4, 35);
	cout << "Priority queue after priority change : ";
	printq();

	// Remove element at index 3
	remove(3);
	cout << "Priority queue after removing the element : ";
	printq();

	return 0;
}
