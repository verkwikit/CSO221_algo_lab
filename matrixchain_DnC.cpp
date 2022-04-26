#include <bits/stdc++.h>
using namespace std;


int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
        {
    		min = count;
        }
	}

	
	return min; // Return minimum count
}


int main()
{
	

    int i,j,n,k,l;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    vector<pair<int,int> >val;
    cout<<"Enter the dimensions of matrices in chain form"<<endl;
    for(i=0;i<n;i++) {
       cout<<"Enter the dimensions of matrix "<<i+1<<": ";
        cin>>l>>k;
        val.push_back(make_pair(l,k));
    }
    int arr[n+1];
    arr[0]=val[0].first;
    arr[1]=val[0].second;
    for(int i =1;i<n+1;i++)
    {
        arr[i+1]=val[i].second;
    }
    for(int i=0;i<n+1;i++)
    {
        cout<<arr[i]<<"\t";
    }
	cout<<"\nMinimum number of multiplications is "<< MatrixChainOrder(arr, 1, n )<<endl;
}

