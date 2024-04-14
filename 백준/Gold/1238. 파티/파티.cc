#include <bits/stdc++.h>

using namespace std;

#define MAX 10000001

int n, m, x;
int dist[1004][1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;

	fill(&dist[0][0], &dist[0][0] + 1004 * 1004, MAX);

	for (int i = 0; i < m; i++)
	{
		int start, dest, d;
		cin >> start >> dest >> d;

		dist[start][dest] = d;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dist[i][k] == MAX)	continue;

			for (int j = 1; j <= n; j++)
			{
				if (i == j) dist[i][j] = 0;
				else
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dist[i][x] + dist[x][i]);
	}

	cout << ans;

	return 0;
}