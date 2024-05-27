#include <bits/stdc++.h>

using namespace std;

int n;
int maps[101][101];
int visited[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> edges;
int ans = INT_MAX;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };


void label(int y, int x, int cnt)
{
	q.push({ y, x });
	visited[y][x] = 1;
	maps[y][x] = cnt;

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (maps[ny][nx] == 0)
			{
				// 한 면이 바다라면
				edges.push_back({ y,x });
				continue;
			}

			visited[ny][nx] = 1;
			maps[ny][nx] = cnt;
			q.push({ ny, nx });
		}
	}
}

void build(int y, int x, int islandnum)
{
	int dist[101][101] = { 0, };

	q.push({ y, x });

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (dist[ny][nx]) continue;
			if (maps[ny][nx] == islandnum) continue;	// 본인 섬 육지라면 
			if (visited[y][x] + 1 > ans) continue;

			// 현재 칸이 바다도 아니고, 시작 섬도 아니라면
			if (maps[ny][nx] != 0 && maps[ny][nx] != islandnum)
			{
				// 다른 섬에 도착한 것임
				ans = min(ans, dist[y][x]);
				continue;
			}

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == 0) continue;
			if (visited[i][j]) continue;

			label(i, j, cnt);
			cnt++;
		}
	}
			

	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		int y, x;
		tie(y, x) = edges[i];
		build(y, x, maps[y][x]);
	}

	cout << ans;

	return 0;
}
