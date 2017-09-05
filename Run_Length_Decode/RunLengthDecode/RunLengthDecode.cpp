#include<iostream>
#include<string.h>
#include<conio.h>
#include<vector>
using namespace std;

void leftShift(vector<char> &a, int j,int n);
void decode(vector<char>a)
{
	int len = a.size();
	int n = len;
	int count = 0;
	for (int i = 1; i < n; i= i + 2)
	{
		if (a[i] == '1')
		{
			n--;
			leftShift(a, i,n);
			count += 1;
			i--;
		}
		else
		{
			char*s = &a[i];
			count += atoi(s);
		}
			

	}

	if (len < count)
	{
		a.resize(len + (count - len));
	}

	if (len > count)
		{
			a.resize(len - (len - count));
		}
	

	/*for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}*/

	int s = a.size();
	int x = s - 1;
	int j = n - 1;
	while (s>0)
	{
		if (a[j] >= '2' && a[j] <= '9')
		{
			char*m = &a[j];
			int m_len = atoi(m);

			char con = a[--j];
			while (m_len > 0)
			{
				a[x] = con;
				x--;
				s--;
				m_len--;
			}
			j--;

		}
		else
		{
			a[x] = a[j];
			x--;
			j--;
		}
		s--;

	}

	
	cout << endl<<"Final Output is: ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}




}

void leftShift(vector<char> &a, int j, int n)
{
	for (int i = j; i <n ; i++)
		a[i] = a[i + 1];
}

int main()
{

	char test[] = { 'a', '4','b','1','c', '3','d','1'};
	
	vector<char> v;
	for (int i = 0; i<8; i++)
	v.push_back(test[i]);
	decode(v);


	char test1[] = { 'a', '1', 'b', '1', 'c', '4', 'd', '1' };

	vector<char> v1;
	for (int i = 0; i<8; i++)
		v1.push_back(test1[i]);
	decode(v1);

	_getch();
	return 0;

}