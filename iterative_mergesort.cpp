#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int n)
{
	for (int i=0; i<n; i++)
		cout<<A[i]<<" ";
	cout <<"\n";
}
void inputArray(int A[], int n)
{
	for (int i=0; i<n; i++)
		cin>>A[i];
}
int min(int x, int y)
{ return (x<y)?x:y; }

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
    int n= n1+n2;
	
	int L[n1], R[n2];

	
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0,j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];	
		}
        
		
	}

	while (i < n1)
	{
		arr[k++] = L[i++];
	}

	while (j < n2)
	{
		arr[k++] = R[j++];
	}
}




void mergeSort(int arr[], int n)
{
int width; // size of subarrays to be merged
				
int left; // starting index of left subarray
				


for (width=1; width<n; width = 2*width)
{

	for (left = 0; left <n; left = left + 2*width)
	{
		
		int mid = left + width-1 ;

		int right = min(left + 2*width-1 , n-1);

		// Merge Subarrays arr[left.....mid] & arr[mid+1...right]
		merge(arr, left, mid, right);
        
	}
    
}
}

int main()
{
    int n;
    
    cin>>n;
    int arr[n];
   
    inputArray(arr,n);
	mergeSort(arr, n);
	cout <<"\nSorted array\n ";
	printArray(arr, n);
	
    return 0;
}

