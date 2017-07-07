#include<iostream>
using namespace std;

//class X
//{
//public:
//	static int i; //Declaring i
//	/*void function()
//	{
//		cout << i;
//	}*/
//};

void function()
{
	extern int i;
	cout << i;
}

int main()
{
	function();
	return 0;
}