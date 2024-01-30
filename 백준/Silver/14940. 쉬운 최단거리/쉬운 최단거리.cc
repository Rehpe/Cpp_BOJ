#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[1004][1004];
int visited[1004][1004];
int x, y;
int dx[] = {0, 0, -1, 1};
int dy[] = { 1, -1, 0, 0 };
int targetx, targety;
queue<pair<int, int>> q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
			{
				targety = i;
				targetx = j;
			}
		}
	}

	q.push({targety, targetx});
	visited[targety][targetx] = 1;

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (maps[ny][nx] == 0) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 0)
				cout << 0 << ' ';
			else if (visited[i][j])
				cout << visited[i][j] - 1 << ' ';
			else
				cout << -1 << ' ';
 		}
		cout << '\n';
	}

	return 0;
}