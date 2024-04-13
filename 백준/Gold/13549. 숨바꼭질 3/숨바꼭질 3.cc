#include <bits/stdc++.h>

using namespace std;

int n, k;
int visited[200002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (q.size())
	{
		int here = q.front();
		q.pop();

		if (here == k)
			break;

		for (int next : {here + 1, here - 1, here * 2})
		if (0 <= next && next <= 100000)
		{
			if (next == here * 2)
			{
				if (!visited[next] || visited[here] < visited[next])
				{
					visited[next] = visited[here];
					q.push(next);
				}
			}
			else
			{
				if (!visited[next] || visited[here] + 1 < visited[next])
				{
					visited[next] = visited[here] + 1;
					q.push(next);
				}
			}
		}
	}
	
	cout << visited[k] - 1;
}