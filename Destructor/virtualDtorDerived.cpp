/*	
In that case, the destructor of the derived class will be virtual, regardless of whether you add the virtual keyword or not:

struct base {
   virtual ~base() {}       // destructor is virtual
};
struct derived : base {
   ~derived() {}            // destructor is also virtual, because it is virtual in base
};
This is not limited to destructors, if at any point in a type hierarchy a function member is declared virtual, all overrides (not overloads) 
of that same function will be virtual, whether they are declared as so or not. The specific bit for destructors is that ~derived() overrides virtual ~base()
even if the name of the member differs --that is the only specificity for destructors here.*/


//Even if we derive C from B, when C goes out of scope all the dtor's are called in order even though virtual keyword is not used in B's dtor
#include<iostream>
using namespace std;

class A
{
public:
	A(int x) :i(x)
	{
		cout << "A's Param ctor" << endl;
	}


	virtual ~A()
	{
		cout << "A' dtor" << endl;
	}
private: 
	int i;
};

class B:public A
{
public:
	B(int x) :j(x),A(x)
	{
		cout << "B's Param ctor" << endl;
	}


	~B()
	{
		cout << "B' dtor" << endl;
	}
private:
	int j;

};

class C :public B
{
public:
	C(int x) :k(x), B(x)
	{
		cout << "C's Param ctor" << endl;
	}


	~C()
	{
		cout << "C' dtor" << endl;
	}
private: 
	int k;
};

int main()
{
	C c(10);
	return 0;
}

/*output
A's Param ctor
B's Param ctor
C's Param ctor
C' dtor
B' dtor
A' dtor
*/