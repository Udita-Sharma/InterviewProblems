/*Multiple inheritance but it has caused diamond problem as B and C both point to A, then when object of D is created 
 constructor and destructor of A is called twice*/
#include<iostream>
using namespace std;

class A
{
	public:
	A(){ cout << "A's  constructor" << endl; }
	~A(){cout<<"A's destructor"<<endl;}
	
};
class B:public A
{
	public:
	B()
	{cout<<"B's constructor"<<endl;}
	~B(){cout<<"B's destructor"<<endl;}
	
};
class C:public A
{
	public:
	C()
	{cout<<"C's constructor"<<endl;}
	~C(){cout<<"C's destructor"<<endl;}
	
};
class D: public B, public C
{
	public:
	D()
	{cout<<"D's constructor"<<endl;}
	~D(){cout<<"D's destructor"<<endl;}
};
	
int main()
{
	D d;
	return 0;
}
/*
A's constructor
B's constructor
A's constructor
C's constructor
D's constructor
D's destructor
C's destructor
A's destructor
B's destructor
A's destructor
*/