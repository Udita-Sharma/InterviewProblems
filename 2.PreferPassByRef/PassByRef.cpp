#include"iostream"
using namespace std;

class myClass
{
public:
	myClass()
	{
		cout << endl << "Deafult ctor called";
	}

	myClass(int i) :m_c1(i)
	{
		cout << endl << "Param ctor called";
	}

	//Pass by Value
	/*myClass operator= (const myClass class1)
	{
		m_c1 = class1.m_c1;
		return m_c1;
	}
	Param ctor called
	Value is10
	Param ctor called
	Value is11
	Param ctor called -> If overloaded assignment is passed by value then an extra call to ctor is called
	Value is10
	*/


	//Pass by refernce
	myClass& operator= (const myClass& class1)
	{
		m_c1 = class1.m_c1;		
	}
	/*
	Param ctor called
	Value is10
	Param ctor called
	Value is11
	Value is10

	In this case no extra call to overloaded assignment operator
	*/
	void display()
	{
		cout<<endl<<"Value is"<<m_c1;
	}

	
private:
	int m_c1;
};

int main()
{
	myClass c1(10);
	c1.display();
	myClass c2(11);
	c2.display();
	c2 = c1;
	c2.display();
	
}