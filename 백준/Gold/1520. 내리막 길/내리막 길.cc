#include <bits/stdc++.h>

using namespace std;

int m, n;
int maps[501][501];
int cnt;
int dp[501][501];	// dp[i][j] = i, j에서 마지막 좌표까지 도달할 수 있는 경로의 수

int dy[] = {0, 0, -1, 1};
int dx[] = { -1, 1, 0, 0 };

int dfs(int y, int x)
{
	if (y == m - 1 && x == n - 1)	return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;	// 방문처리

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (maps[ny][nx] >= maps[y][x]) continue;

		dp[y][x] += dfs(ny, nx);
	}

	return dp[y][x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			dp[i][j] = -1;	// dp배열 초기화
		}
	}

	if (maps[0][0] <= maps[m - 1][n - 1])
	{
		cout << 0;
		return 0;
	}

	cout << dfs(0, 0);

	return 0;
}
