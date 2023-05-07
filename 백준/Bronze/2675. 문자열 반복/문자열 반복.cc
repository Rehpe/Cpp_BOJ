#include <bits/stdc++.h>
using namespace std;

int T;
int repeat;
string s;
string ret;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		ret = {};
		cin >> repeat >> s;

		for (int k = 0; k < s.length(); k++)
		{
			for (int j = 0; j < repeat; j++)
			{
				ret += s[k];
			}
		}

		for (char c : ret)
		{
			cout << c;
		}

		if (i == T - 1)
			return 0;
		else
			cout << '\n';
	}
}