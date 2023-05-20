#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> que;
int ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		que.push(i + 1);
	}

	while (que.size() > 1)
	{
		que.pop();
		int n = que.front();
		que.pop();
		que.push(n);
	}

	cout << que.front();
}