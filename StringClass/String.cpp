#include"iostream"
using namespace std;

class String
{
public:
	String() :m_str(NULL)
	{}
	String(char *str)
	{
		int len = 0;
		while (str[len] != '\0')
		{
			len++;

		}
		m_len = len + 1;
		m_str = new char[m_len];
		for (int i = 0; i < (m_len - 1); i++)
			m_str[i] = str[i];
		m_str[(m_len - 1)] = 0;		
	}
	String(const String &str)
	{
		cout << endl << "copy ctor";
		m_len = str.m_len;
		m_str = new char[ m_len];
		for (int i = 0; i < (m_len - 1); i++)
			m_str[i] = str.m_str[i];
		m_str[(m_len - 1)] = 0;
	}

	String& operator=(const String& str)
	{
		cout << endl << "assignment operator";
		m_len = str.m_len;
		m_str = new char[m_len];
		for (int i = 0; i < (m_len - 1); i++)
			m_str[i] = str.m_str[i];
		m_str[(m_len - 1)] = 0;

	}
	void display()
	{
		cout << endl << "String is: ";
		for (int i = 0; i < (m_len - 1); i++)
			cout << m_str[i];
	}


private:
	char *m_str;
	int m_len;
};

int main()
{
	String s1("Hello");
	s1.display();
	String s2(s1);
	s2.display();

	String s3("How are you");
	s3.display();
	s3 = s1;
	s3.display();

	return 0;
}