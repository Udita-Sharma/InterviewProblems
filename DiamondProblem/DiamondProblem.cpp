/*Multiple inheritance but it has caused diamond problem as B and C both point to A, then when object of D is created 
 constructor and destructor of A is called twice*/
#include<iostream>
using namespace std;

class A
{
	public:
	A(){ cout << "A's default constructor" << endl; }
	A(int x){cout<<"A's constructor"<<endl;}
	~A(){cout<<"A's destructor"<<endl;}
	void function1()
	{
		cout << "A's function1()" << endl;
	}
};
class B:public A
{
	public:
	B(int x):A(x)
	{cout<<"B's constructor"<<endl;}
	~B(){cout<<"B's destructor"<<endl;}
	void function1()
	{
		cout << "B's function1()"<<endl;
	}
};
class C:public A
{
	public:
	C(int x):A(x)
	{cout<<"C's constructor"<<endl;}
	~C(){cout<<"C's destructor"<<endl;}
	void function1()
	{
		cout << "C's function1()" << endl;
	}
};
class D: public B, public C
{
	public:
	D(int x):B(x),C(x)
	{cout<<"D's constructor"<<endl;}
	void function1()
	{
		cout << "D's function1()" << endl;
	}
	~D(){cout<<"D's destructor"<<endl;}
};
	
int main()
{
	//D d(10);
	A *b = new B(10);
	b->function1();
	delete b;
	/*A's constructor
	  B's constructor
	  A's function1()
	  A's destructor*/
	
	
	//A *d = new D(10); //COmpile time error
	//d->function1();
	//delete d;

	/*DiamondProblem.cpp:61 : 17 : error : ‘A’ is an ambiguous base of ‘D’
		A *d = new D(10);*/
	



	return 0;
}
/*output:
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