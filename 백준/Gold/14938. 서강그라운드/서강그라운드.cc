#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int item[101];
int dist[101][101];
int maxitem;
int itemcnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	fill(&dist[0][0], &dist[0][0] + 101 * 101, INT_MAX);

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int i = 0; i < r; i++)
	{
		int from, to, d;
		cin >> from >> to >> d;
		dist[from][to] = d;
		dist[to][from] = d;
	}


	for (int k = 1; k <= n; k++)	// 거쳐갈 지역
	{
		for (int i = 1; i <= n; i++)
		{
			if (dist[i][k] == INT_MAX) continue;

			for (int j = 1; j <= n; j++)
			{
				if (dist[k][j] == INT_MAX) continue;
				
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		itemcnt = 0;

		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] <= m)
				itemcnt += item[j];
		}
		maxitem = max(maxitem, itemcnt);
	}

	cout << maxitem;

	return 0;
}