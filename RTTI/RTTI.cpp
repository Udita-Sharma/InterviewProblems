#include<iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{}
};

class Derived : public Base //  virtual public Base //will not work
{};

int main()
{
	Base *b = new Derived();
	Derived *d = dynamic_cast<Derived*>(b); //ERROR
	/*$ g++ RTTI.cpp
	RTTI.cpp: In function ‘int main()’ :
		RTTI.cpp : 13 : 39 : error : cannot dynamic_cast ‘b’(of type ‘class Base*’) to type ‘class Derived*’(source type is not polymorphic)
		Derived *d = dynamic_cast<Derived*>(b);*/

	return 0;
}