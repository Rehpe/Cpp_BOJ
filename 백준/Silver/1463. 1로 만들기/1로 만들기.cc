#include <bits/stdc++.h>

using namespace std;

int N;
int visited[1000000];
int minCnt = INT_MAX;
int ret;

void go(int n)
{
	if (n == 1)
	{
		ret = visited[1];
		return;
	}

	if (n % 6 == 0)
	{
		int here = n;
		for (int next : { here / 3, here / 2, here - 1})
		{
			if (visited[next] == INT_MIN || visited[next] > visited[n] + 1)
			{
				visited[next] = visited[n] + 1;
				go(next);
			}
		}
	}
	else if (n % 3 == 0)
	{
		int here = n;
		for (int next : { here / 3, here - 1})
		{
			if (visited[next] == INT_MIN || visited[next] > visited[n] + 1)
			{
				visited[next] = visited[n] + 1;
				go(next);
			}
		}
	}
	else if(n % 2 == 0)
	{
		int here = n;
		for (int next : { here / 2, here - 1})
		{
			if (visited[next] == INT_MIN || visited[next] > visited[n] + 1)
			{
				visited[next] = visited[n] + 1;
				go(next);
			}
		}
	}
	else
	{
		int here = n;
		int next = here - 1;
		if (visited[next] == INT_MIN || visited[next] > visited[n] + 1)
		{
			visited[next] = visited[n] + 1;
			go(next);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	fill(visited, visited + 1000000, INT_MIN);
	visited[N] = 1;
	go(N);

	cout << ret - 1;

	return 0;
}