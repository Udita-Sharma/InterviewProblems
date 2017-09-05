//Reverse string

#include<iostream>
#include<conio.h>
using namespace std;
#include<string.h>

void reverse(char *s)
{
	int len = strlen(s);
	int i = 0;
	int j = len - 1;
	while (i != j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	
}

int main()
{
	char s[] = "Udita";
	reverse(s);
	cout << "Reversed string is: ";
	for (int i = 0; i < strlen(s); i++)
	{
		cout << s[i];
	}
	_getch();
	return 0;
}