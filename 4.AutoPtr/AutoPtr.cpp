#include<iostream>
using namespace std;

class autoPtr
{
public:
	autoPtr(int *p) :ptr(p)
	{}

	~autoPtr()
	{
		delete ptr;
	}

	void display()
	{
		if (ptr)
			cout << endl << *ptr;
		else
			cout << endl << "object is null";
	}

	autoPtr(autoPtr &obj)
	{
		ptr = obj.ptr;
		obj.ptr = NULL;
	}

	autoPtr& operator=(autoPtr &obj)
	{
		ptr = obj.ptr;
		obj.ptr = NULL;
		return *this;
	}
private:
	int *ptr;
};

int main()
{
	
	autoPtr obj1(new int(10));
	obj1.display();
	autoPtr obj2(obj1);
	obj2.display();
	obj1.display();
	
	return 0;
}