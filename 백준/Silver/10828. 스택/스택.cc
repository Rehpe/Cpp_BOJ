#include <bits/stdc++.h>
using namespace std;

int N;
string func;
stack<int> st;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> func;

		if (func == "push")
		{
			cin >> n;
			st.push(n);
		}
		else if (func == "pop")
		{
			if (st.empty())
				n = -1;
			else
			{
				n = st.top();
				st.pop();
			}
			cout << n << '\n';
		}
		else if (func == "size")
		{
			cout << st.size() << '\n';
		}
		else if (func == "empty")
		{
			if (st.empty())
				n = 1;
			else
				n = 0;
			cout << n << '\n';
		}
		else if (func == "top")
		{
			if (st.empty())
				n = -1;
			else
			{
				n = st.top();
			}
			cout << n << '\n';
		}
	}
}