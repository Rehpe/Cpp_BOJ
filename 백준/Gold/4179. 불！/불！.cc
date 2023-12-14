#include <bits/stdc++.h>

using namespace std;


int R, C;
int x, y;
char maze[1004][1004];
int fire[1004][1004];
int jihoon[1004][1004];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0 , 0, 1, -1 };
int minute = INT_MIN;
queue<pair<int, int>> q;
pair<int, int> location;


bool isIn(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x <= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INT_MAX);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> maze[i][j];

			// 지훈 위치 저장
			if (maze[i][j] == 'J')
			{
				location = { i, j };
				jihoon[i][j] = 1;
			}

			if (maze[i][j] == 'F')
			{
				q.push({ i,j });
				fire[i][j] = 1;
			}
		}
	}

	// 불의 최단거리 구하기
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!isIn(ny, nx)) continue;		// 맵 밖이면 X
			if (fire[ny][nx] != INT_MAX) continue;	// 불이 이미 번진 곳이라면 X
			if (maze[ny][nx] == '#')	continue;	// 벽이라면 X

			fire[ny][nx] = fire[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	// 지훈이의 최단거리 구하기
	q.push({ location.first, location.second });
	
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		// 가장자리 도착했다면
		if (y == 0 || x == 0 || y == R - 1 || x == C - 1)
		{
			minute = jihoon[y][x];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!isIn(ny, nx)) continue;		// 맵 밖이면 X
			if (maze[ny][nx] == '#')	continue;	// 벽이라면 X
			if (jihoon[ny][nx])	continue;	// 이미 방문한 곳이라면 X
			if (fire[ny][nx] <= jihoon[y][x] + 1)	continue;	// 불의 최단거리보다 지훈이 최단거리가 더 크다면 X

			jihoon[ny][nx] = jihoon[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	if (minute == INT_MIN)
		cout << "IMPOSSIBLE";
	else
		cout << minute;

	return 0;
}