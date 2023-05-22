#include <bits/stdc++.h>
using namespace std;

int N;
string func;
queue<int> q;
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
			q.push(n);
		}
		else if (func == "pop")
		{
			if (q.empty())
				n = -1;
			else
			{
				n = q.front();
				q.pop();
			}
			cout << n << '\n';
		}
		else if (func == "size")
		{
			cout << q.size() << '\n';

		}
		else if (func == "empty")
		{
			if (q.empty())
				n = 1;
			else
				n = 0;
			cout << n << '\n';
		}
		else if (func == "front")
		{
			if (q.empty())
				n = -1;
			else
				n = q.front();
			cout << n << '\n';
		}
		else if (func == "back")
		{
			if(q.empty())
				n = -1;
		else
			n = q.back();
		cout << n << '\n';
		}
	}
}