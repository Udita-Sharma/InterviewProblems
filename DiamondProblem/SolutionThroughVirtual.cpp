/*Multiple inheritance where constructor and destructor of A is called only once because we have put virtual keyword.*/
#include<iostream>
using namespace std;

class A
{
public:
	A(){ cout << "A's default constructor" << endl; }
	A(int x){ cout << "A's constructor" << endl; }
	virtual ~A(){ cout << "A's destructor" << endl; }
	virtual void function1()
	{
		cout << "A's function1()";
	}
};
class B :virtual public A
{
public:
	B(int x) :A(x)
	{
		cout << "B's constructor" << endl;
	}
	virtual ~B(){ cout << "B's destructor" << endl; }
	void function1()
	{
		cout << "B's function1()" << endl;
	}
};
class C :virtual public A
{
public:
	C(int x) :A(x)
	{
		cout << "C's constructor" << endl;
	}
	virtual ~C(){ cout << "C's destructor" << endl; }
	void function1()
	{
		cout << "C's function1()";
	}
};
class D : public B, public C
{
public:
	D(int x) :B(x), C(x)
	{
		cout << "D's constructor" << endl;
	}
	void function1()
	{
		cout << "D's function1()" << endl;
	}
	~D(){ cout << "D's destructor" << endl; }
};

int main()
{
	//D d(10);
	A *d = new D(10);
	d->function1();
	delete d;
	return 0;
}
/*
In the above program, constructor of ‘A’ is called once. One important thing to note in the above output is, the default constructor of ‘A’ is called. When we use ‘virtual’ keyword,
the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor.
o/p:
A's default constructor
B's constructor
C's constructor
D's constructor
D's function1()
D's destructor
C's destructor
B's destructor
A's destructor