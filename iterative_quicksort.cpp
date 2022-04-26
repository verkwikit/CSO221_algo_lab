#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int n)
{
	
	for (int i=0; i<n; ++i)
		cout<<A[i]<<" ";
}
void inputArray(int A[], int n)
{
	for (int i=0; i<n; i++)
		cin>>A[i];
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
 
 int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //selecting last element as pivot
    int i = low ;  //index of smaller element 
 
    for (int j = low;j < high; j++) 
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i ;
}


void quickSort(int arr[], int l, int h)
{
	
	int Auxstack[h - l + 1];

	
	int top = -1;


	Auxstack[++top] = l;
	Auxstack[++top] = h;

	
	while (top >= 0) 
    {
		
		h = Auxstack[top--];
		l = Auxstack[top--];
		
        int p = partition(arr, l, h);
		
        if (p - 1 > l) 
        {
			Auxstack[++top] = l;
			Auxstack[++top] = p - 1;
		}
		if (p + 1 < h) 
        {
			Auxstack[++top] = p + 1;
			Auxstack[++top] = h;
		}
	}
}



int main()
{
    int n ;
    cin>>n;
	int A[n];

    inputArray(A,n);
	quickSort(A, 0, n - 1);
	printArray(A, n);
	return 0;
}


