#include <bits/stdc++.h>
using namespace std;

int N;
string s;
stack<char> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		st = {};

		for (int j = 0; j < s.size(); j++)
		{
			if (!st.empty())
			{
				if (st.top() == '(' && s[j] == ')')
					st.pop();
				else
					st.push(s[j]);
			}
			else
				st.push(s[j]);
		}

		if (st.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	
}