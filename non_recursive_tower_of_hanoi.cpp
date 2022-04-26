#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int N)
{
	
	for (int x = 1; x <pow(2, N); x++) 
    {

		cout << "Move from Rod "
			<< ((x & x - 1) % 3 + 1)
			<< " to Rod "
			<< (((x | x - 1) + 1) % 3 + 1)
			<< endl;
	}
}

int main()
{
	int N ;
    cout<<"Enter the number of disks on rod 1\n";
    cin>>N;
	TowerOfHanoi(N);
	return 0;
}
