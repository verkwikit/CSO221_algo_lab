#include<bits\stdc++.h>
using namespace std;

int c=0;
void toh(int n,char rodA, char rodC, char rodB) //rod A as source rod , rod B as spare rod , rod C as target rod
{
    if(n==0)
    {
        return ;
    }

    toh(n-1 ,rodA ,rodB,rodC);
    cout << "Move disk " << n << " from rod " << rodA <<" to rod " << rodB << endl;
    toh(n-1 ,rodB,rodC,rodA);
    c++;
}
int main()
{
    
    int n;
    cout<<"Enter the number of disks on rod A\n";
    cin>>n;
    toh(n,'A','B','C');
    cout<<"Minimum number of valid steps required to move all the disks from rod A to rod C\n";
    cout<<c<<" = (2^"<<n<<")-1";
    return 0;
}