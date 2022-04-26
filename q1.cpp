#include<iostream>
#include<climits>
using namespace std;


void swap(int *x, int *y);


class MinHeap
{
	int *harr; // pointer to array of elements in heap
	int size; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	
	MinHeap(int size);

	
	void MinHeapify(int ); // to heapify a subtree with the root at given index

	int parent(int i) { return (i-1)/2; }

	
	int left(int i) { return (2*i + 1); } // to get index of left child of node at index i

	
	int right(int i) { return (2*i + 2); } // to get index of right child of node at index i

	
	int extractMin(); // to extract the root which is the minimum element

	
	void decreaseKey(int i, int new_val); // Decreases key value of key at index i to new_val


	int getMin() { return harr[0]; } 	// Returns the minimum key (key at root) from min heap

	
	void deleteKey(int i); // Deletes a key stored at index i

	
	void insertKey(int k); // Inserts a new key 'k'
};


MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	size = cap;
	harr = new int[cap];
}


void MinHeap::insertKey(int k)
{
	if (heap_size == size)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


int main()
{
    cout<<"enter size of heap";
    int n;
    cin>>n;
	MinHeap h(n);
    
	h.insertKey(5);
	h.insertKey(2);
	h.deleteKey(5);
	h.insertKey(1);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(4, 1);
	cout << h.getMin();
	return 0;
}
