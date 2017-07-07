#include<iostream>
using namespace std;

class Base
{
	public:
	void fun()
	{
		cout<<"Inside base fun()"<<endl;
	}
	void fun(int i)
	{
		cout<<"inside base fun(i)"<<endl;
	}
};
class Derived:public Base
{
	public:
	void fun(int i)
	{
		cout<<"inside derived fun(i)"<<endl;
	}
};
int main()
{
	Derived d;
	d.fun(1);
	Base *b = &d;
	b->fun(1);
	Derived *d1 = &d;
	d1->fun(1);
	
	return 0;
}