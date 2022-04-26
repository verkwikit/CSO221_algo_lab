#include <bits/stdc++.h>
using namespace std;


class A 
{
	int a;

public:
	int* ptr;

	
	A()
	{
		cout<<"\nConstructor was Called!"<<endl;
	}

	
	~A()
	{
		cout<<"Destructor was Called!"<<endl;
	}
};


int main()
{

	A* a = new A;
	cout<<"Object of class A was created using new operator!"<<endl;

	delete (a);
	cout<<"Object of class A was  deleted using delete keyword!"<<endl;

	cout << endl;

	A* b = (A*)malloc(sizeof(A));
	cout<<"Object of class A was created using malloc()!"<<endl;
	free(b);
	cout<<"Object of class A was deleted using free()!"<<endl;

	return 0;
}
