#include <bits/stdc++.h>

using namespace std;

int N;
int x;
struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x == 0)
		{
			if (pq.size())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(x);
		}
	}
	
	return 0;
};