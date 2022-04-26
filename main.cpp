#include <time.h>
#include<stdio.h>
    
int main()
{ 
     clock_t start, end;
     double cpu_time_used;
     
     start = clock();
     
      int n,b;
    
    scanf("%d",&n);
    
    int a[n];
    int max=0;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=max)
        {
            max=a[i];
        }
    }
    
    int arr[max+1]={};
    
    for(int i=0;i<n;i++)
    {
        arr[a[i]]++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        {
            printf("\nthe frq of %d is %d\n",a[i],arr[a[i]]);
        }
    }
    
    
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("\ntime of execution is :%f\n",cpu_time_used);
}
