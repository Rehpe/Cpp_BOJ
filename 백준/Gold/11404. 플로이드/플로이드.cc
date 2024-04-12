#include <bits/stdc++.h>

using namespace std;

#define MAX 9999999

#define time aaa
#define end bbb

int n, m;
int start, end, d;
int dist[102][102];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 102 * 102, MAX);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> d;

		// 기존 노선보다 가중치가 작은 경우에만 갱신
		if (d < dist[start][end])
		{
			dist[start][end] = d;
		}
	}

	// 거쳐갈 마을 노드 k
	for (int k = 1; k <= n; k++)
	{
		// 출발 마을
		for (int i = 1; i <= n; i++)
		{
			// 도착 마을
			for (int j = 1; j <= n; j++)
			{
				if (i == j)	dist[i][j] = MAX;
				else
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != MAX)
				cout << dist[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}