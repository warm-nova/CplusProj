#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int n;
string del(string str, int i)
{
	return str.substr(0, i) + str.substr(i + 1, str.length() - i);
}

string format(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') {
			str = del(str, i);
			i--;
		}
	}
	stack<int> lkh;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] == '(') lkh.push(i);
		else if (str[i] == ')')
		{
			int l = lkh.top();
			lkh.pop();
			if (l == 0 || str[l - 1] == '+' || str[l - 1] == '(' || i - l == 2)
			{
				str = del(str, i);
				str = del(str, l);
				i -= 2;
			}
		}
	}

	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] == '(') lkh.push(i);
		else if (str[i] == ')')
		{
			int l = lkh.top();
			lkh.pop();
			if (l == 0 || str[l - 1] == '-' || str[l - 1] == '(' || i - l == 2)
			{
				//cout << str << endl;
				//cout << "i and l:" << i << " " << l << endl;
				for (int a = l; a < i; a++)
				{
					if (str[a] == '+')
						str[a] = '-';
					else if (str[a] == '-')
						str[a] = '+';
				}
				str = del(str, i);
				str = del(str, l);
				i -= 2;
			}
		}
	}
	return str;
}
int main()
{
	string str;
	cin >> str;
	cout << format(str) << endl;
	system("pause");
	return 0;

}
