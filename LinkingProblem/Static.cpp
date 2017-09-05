#include<iostream>
using namespace std;

class X
{
public:
	//static int i; //declaring i
	static void function()
	{
		int i = 10;
		cout << i;
	}
};

//void function()
//{
//	//extern int i;
//	cout << i;
//}

int main()
{
	//X::function();
	X x1 = new X();
	x1.function();
	return 0;
}