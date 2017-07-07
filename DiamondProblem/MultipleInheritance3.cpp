/*Multiple inheritance where constructor and destructor of A is called only once because we have put virtual keyword.*/
#include<iostream>
using namespace std;

class A
{
	public:
	//A(){cout<<"A's constructor"<<endl;}
	A(int x){cout<<"A's param constructor"<<endl;}
	~A(){cout<<"A's destructor"<<endl;}
};
class B:virtual public A
{
	public:
	B(int x):A(x)
	{cout<<"B's constructor"<<endl;}
	~B(){cout<<"B's destructor"<<endl;}
};
class C:virtual public A
{
	public:
	C(int x):A(x)
	{cout<<"C's constructor"<<endl;}
	~C(){cout<<"C's destructor"<<endl;}
};
class D:public B,public C
{
	public:
	D(int x):B(x),C(x),A(x) // Note: The difference between this and SolutionThroughVirtual
	{cout<<"D's constructor"<<endl;}
	~D(){cout<<"D's destructor"<<endl;}
};
	
int main()
{
	D d(10);
	return 0;
}
/*output:
A's param constructor
B's constructor
C's constructor
D's constructor
D's destructor
C's destructor
B's destructor
A's destructor

No need of default constructor since we have put D(int x):B(x),C(x),A(x)
*/