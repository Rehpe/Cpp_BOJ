#include <bits/stdc++.h>
using namespace std;

int N, M; // N: 지도 세로, M: 지도 가로
char c;
char maps[51][51];
int visited[51][51];
int maxDist;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(int y, int x)
{
	//돌릴 때마다 방문배열 초기화
	memset(visited, 0, sizeof(visited));

	//방문 처리
	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size())
	{
		tie(y,x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (maps[ny][nx] == 'W') continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });

			// 최대 최단거리를 구해야함
			maxDist = max(maxDist, visited[ny][nx]);
		}
	}
	return;
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//육지라면 bfs
			if (maps[i][j] == 'L')
				bfs(i, j);
		}
	}

	// 시작 좌표에서부터 1을 더하므로 1을 빼줘야 최종 거리가 계산됨
	cout << maxDist - 1;

	return   0;
}