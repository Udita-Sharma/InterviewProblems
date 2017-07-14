/*Multiple inheritance where constructor and destructor of A is called only once because we have put virtual keyword.*/
#include<iostream>
using namespace std;

class A
{
public:
	A(){ cout << "A's constructor" << endl; }
	~A(){ cout << "A's destructor" << endl; }
	
};
class B :virtual public A
{
public:
	B()
	{
		cout << "B's constructor" << endl;
	}
	~B(){ cout << "B's destructor" << endl; }
	
};
class C :virtual public A
{
public:
	C()
	{
		cout << "C's constructor" << endl;
	}
	~C(){ cout << "C's destructor" << endl; }
	
};
class D : public B, public C
{
public:
	D()
	{
		cout << "D's constructor" << endl;
	}
	
	~D(){ cout << "D's destructor" << endl; }
};

int main()
{
	D d;
	return 0;
}
/*
In the above program, constructor of ‘A’ is called once. 
A's constructor
B's constructor
C's constructor
D's constructor
D's destructor
C's destructor
B's destructor
A's destructor
*/