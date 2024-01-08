#include <bits/stdc++.h>

using namespace std;

int N, K;
int visited[200004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	if (N == K)
	{
		cout << 0;
		return 0;
	}

	visited[N] = 1;

	queue<int> q;
	q.push(N);


	while (q.size())
	{
		int here = q.front();
		q.pop();

		if (here == K)
			break;

		for (int next : {here + 1, here - 1, here * 2})
		{
			if (next < 0 || next > 100000) continue;
			if (visited[next]) continue;

			q.push(next);
			visited[next] = visited[here] + 1;
		}
	}

	cout << visited[K] - 1;
	return 0;
}