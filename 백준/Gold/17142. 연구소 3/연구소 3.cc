#include <bits/stdc++.h>

using namespace std;

int n, m;
int maps[51][51];
int markmaps[51][51];
int visited[51][51];
vector<pair<int, int>> virus;
int dy[] = { 1, -1,  0, 0 };
int dx[] = { 0, 0, 1, -1 };
int maxtime = INT_MIN;
int mintime = INT_MAX;

int check_virus()
{
	maxtime = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (markmaps[i][j] == 0)
				return INT_MAX;

			maxtime = max(maxtime, visited[i][j] - 1);
		}
	}
	return maxtime;
}



int bfs(vector<pair<int, int>> vec)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	memcpy(markmaps, maps, sizeof(maps));

	for (int i = 0; i < vec.size(); i++)
	{
		q.push(vec[i]);
		
		int y, x;
		tie(y, x) = vec[i];
		visited[y][x] = 1;
	}

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // 범위 밖인 경우
			if (markmaps[ny][nx] == 1) continue; // 벽인 경우
			if (visited[ny][nx]) continue; // 방문한 곳인 경우

			if (markmaps[ny][nx] == 2)	// 비활성 바이러스를 만나면
			{
				if (check_virus() != INT_MAX)
					return maxtime;
			}

			visited[ny][nx] = visited[y][x] + 1;
			markmaps[ny][nx] = 2;
			q.push({ ny, nx });
		}
	}

	return check_virus();
}

void combi(int start, vector<pair<int, int>> vec)
{
	if (vec.size() == m)
	{
		// bfs 시작
		mintime = min(mintime, bfs(vec));
		return;
	}

	for (int i = start + 1; i < virus.size(); i++)
	{
		vec.push_back(virus[i]);
		combi(i, vec);
		vec.pop_back();
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
				virus.push_back({ i, j });
			}
		}
	}

	memcpy(markmaps, maps, sizeof(maps));

	if (check_virus() != INT_MAX)
	{
		cout << 0;
		return 0;
	}
	else
	{
		vector<pair<int, int>> activated_virus;
		combi(-1, activated_virus);

		if (mintime == INT_MAX) cout << -1;
		else cout << mintime;

		return 0;
	}
}