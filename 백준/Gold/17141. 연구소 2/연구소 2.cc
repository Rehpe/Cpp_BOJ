#include <bits/stdc++.h>

using namespace std;

int n, m;
int maps[51][51];
int visited[51][51];
int tempmaps[51][51];
int isused[11];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
vector<pair<int, int>> virusable;
vector<int> pickIdx;
int mintime = INT_MAX;

int go()
{
	int maxnum = 1;
	
	memcpy(tempmaps, maps, sizeof(maps));
	queue<pair<int, int>> q;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < m; i++)
	{
		int y, x;
		tie(y, x) = virusable[pickIdx[i]];
		tempmaps[y][x] = 1;
		visited[y][x] = 1;
		q.push({ y, x });
	}

	while (!q.empty())
	{
		int y, x;
		tie(y,x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (tempmaps[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;

			tempmaps[ny][nx] = 1;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			maxnum = max(maxnum, visited[ny][nx]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tempmaps[i][j] == 0)
				return INT_MAX;
		}
	}
	return maxnum;
}


void pick(int idx, int viruscnt)
{
	if (viruscnt == m)
	{
		mintime = min(go(), mintime);
		return;
	}

	for (int i = idx; i < virusable.size(); i++)
	{
		if (!isused[i])
		{
			pickIdx.push_back(i);
			isused[i] = true;
			pick(i, viruscnt + 1);
			pickIdx.pop_back();
			isused[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];

			if (maps[i][j] == 2)
			{
				maps[i][j] = 0;
				virusable.push_back({ i, j });
			}
		}
	}

	pick(0,0);

	if (mintime == INT_MAX) cout << -1;
	else cout << mintime -1;
	
	return 0;
}