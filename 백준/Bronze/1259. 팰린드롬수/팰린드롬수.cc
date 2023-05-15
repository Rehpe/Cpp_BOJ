#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		dq = {};

		string n = to_string(N);
		for (char c : n)
		{
			dq.push_back(c);
		}
		
		while (dq.front() == dq.back())
		{
			if (dq.size() == 1 || dq.size() == 0)
				break;

			dq.pop_back();
			dq.pop_front();
		}

		if (dq.size() == 1 || dq.size() == 0)
			cout << "yes" <<'\n';
		else
			cout << "no"<<'\n';
	}
}