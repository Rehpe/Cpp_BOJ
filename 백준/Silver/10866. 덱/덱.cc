#include <bits/stdc++.h>
using namespace std;

int N;
string func;
deque<int> dq;
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

		if (func == "push_front")
		{
			cin >> n;
			dq.push_front(n);
		}
		else if (func == "push_back")
		{
			cin >> n;
			dq.push_back(n);
		}
		else if (func == "pop_front")
		{
			if (dq.empty())
				n = -1;
			else
			{
				n = dq.front();
				dq.pop_front();
			}
			cout << n <<'\n';	
		}
		else if (func == "pop_back")
		{
			if (dq.empty())
				n = -1;
			else
			{
				n = dq.back();
				dq.pop_back();
			}
			cout << n << '\n';
		}
		else if (func == "size")
		{
			cout << dq.size() <<'\n';
		}
		else if (func == "empty")
		{
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (func == "front")
		{
			if (dq.empty())
				n = -1;
			else
			{
				n = dq.front();
			}
			cout << n << '\n';
		}
		else if (func == "back")
		{
			if (dq.empty())
				n = -1;
			else
			{
				n = dq.back();
			}
			cout << n << '\n';
		}
	}
}