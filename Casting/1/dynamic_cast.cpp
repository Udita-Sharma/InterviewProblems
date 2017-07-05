#include<iostream>
using namespace std;

class Base
{
public:
	virtual bool func1()
	{
		cout << "Base func1" << endl;
	}
};


class Derived1 : public Base
{
public:
	virtual bool func1()
	{
		cout << "Derived1 func1" << endl;
	}

	virtual bool funcDer1()
	{
		cout << "Derived1 funcDer1" << endl;
	}
};



class Derived2 : public Base
{
public:
	virtual bool func1()
	{
		cout << "Derived2 func1" << endl;
	}
	virtual bool funcDer2()
	{
		cout << "Derived2 funcDer2" << endl;
	}
};

int main()
{
	Base* pDer1 = new Derived1;
	pDer1->func1();
	Base* pDer2 = new Derived2;
	/*pDer2->funcDer2(); We cannot call funDer2 directly since Base class does not have that function
	dynamic_cast.cpp:48:9: error: ‘class Base’ has no member named ‘funcDer2’
	pDer2->funcDer2();
	*/

	Derived2* pDerCasted = dynamic_cast<Derived2*>(pDer2);// applying dynamic cast on pDer2
	if (pDerCasted)
	{
		pDerCasted->funcDer2();
	}

	return 0;

}
