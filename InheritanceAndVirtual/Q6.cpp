#include<iostream>
using namespace std;

class A
{
	public:
	int a;
};

class B :private A// if we use public and protected , C can still print a, but when we put private Class B can only print a,A's data members
	// will not be passed to c since B is privately inheriting A now.
{
public:
	virtual void foo()
	{
		a = 10;
		cout << "B's a is: " << a << endl;
	}
};

class C :public B
{
public:
	void foo()
	{
		a = 10;
		cout << "C's a is: " << a << endl;
	}
};


int main()
{
	C c;
	c.foo();
	return 0;

}

/*
Q6.cpp: In member function ‘virtual void C::foo()’:
Q6.cpp:7:6: error: ‘int A::a’ is protected
int a;
^
Q6.cpp:25:3: error: within this context
a = 10;
^
Q6.cpp:7:6: error: ‘int A::a’ is protected
int a;
^
Q6.cpp:26:27: error: within this context
cout << "C's a is: " << a << endl;

*/