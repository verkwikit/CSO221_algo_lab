#include<bits/stdc++.h>
using namespace std;


#define point pair<int, int>


set<point> c_hull;


int find_side(point p1, point p2, point p)
{
	int val;
    val = (p.second-p1.second)*(p2.first-p1.first) - (p2.second-p1.second)*(p.first-p1.first);

	if(val>0)
	{
        return 1;
    }
	
    if(val<0)
    {
		return -1;
    }
    
    return 0;
}


int lineDist(point p1, point p2, point p)
{
	return abs ((p.second - p1.second) * (p2.first - p1.first) -
			(p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(point a[], int n, point p1, point p2, int side)
{
	int index = -1;
	int max_dist = 0;

	
	for (int i=0; i<n; i++)
	{
		int temp = lineDist(p1, p2, a[i]);
		if (find_side(p1, p2, a[i]) == side && temp > max_dist)
		{
			index = i;
			max_dist = temp;
		}
	}

	// If no point is found, add the end points of Line L to the convex hull.
	if (index == -1)
	{
		c_hull.insert(p1);
		c_hull.insert(p2);
		return;
	}

	// Recursion for the two parts divided by a[index]
	quickHull(a, n, a[index], p1, -find_side(a[index], p1, p2));
	quickHull(a, n, a[index], p2, -find_side(a[index], p2, p1));
}

void printHull(point a[], int n)
{

	if(n<3)
	{
		cout << "Convex hull not possible\n";
		return;
	}


	int x_min = 0, x_max = 0;
	for (int i=1; i<n; i++)
	{
		if (a[i].first < a[x_min].first)
        {
            x_min = i;
        }

		if (a[i].first > a[x_max].first)
        {
            x_max = i;
        }
	}


	quickHull(a, n, a[x_min], a[x_max], 1);
    quickHull(a, n, a[x_min], a[x_max], -1);

	cout<<"The points in Convex Hull are:\n";
	while (!c_hull.empty())
	{
		cout<<"("<<(*c_hull.begin()).first<<","<<(*c_hull.begin()).second <<")\n";
		c_hull.erase(c_hull.begin());
	}
    cout<<endl;
}


int main()
{

        int n;
        int x,y;
        cout << "Enter number of elements\n";
        cin >> n;
		
		if(n<3)
		{
			printf("\nConvex Hull not possible\n");
		}
		else if (n==3)
		{
			printf("\nThe triangle is the convex hull\n");
		}
		else
		{

			point a[n];
			
		
			cout << "enter x and y coordinates- \n";
			for(int i=0; i<n; i++)
			{
				cin >> a[i].first;
				cin >> a[i].second;

			}
			cout << "Elements are:\n";
			for (int i=0;i<n;i++)
			{
				cout << "("<<a[i].first << "," <<a[i].second <<")"<< "\n";
			}
		
			printHull(a, n);

		}
   
    return 0;
}
