#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[504][504];
int visited[504][504];
int depth;
int maxsum;

int dy[] = { 0, 0,  -1, 1 };
int dx[] = { -1, 1, 0, 0 };


void dfs(int y, int x, int depth, int sum)
{
	// 깊이가 3이라면 합계 비교 후 return
	if (depth == 3)
	{
		maxsum = max(maxsum, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		dfs(ny, nx, depth + 1, sum + a[ny][nx]);
		
		// 백트래킹 (방문 좌표의 방문기록을 취소함)
		visited[ny][nx] = false;
	}
}

void other(int y, int x)
{
	// dfs로 처리할 수 없는 ㅜ 모양을 계산한다
	int temp;
	
	// ㅜ
	if (y + 1 < N && x + 2 < M)
	{
		temp = a[y][x] + a[y][x + 1] + a[y + 1][x + 1] + a[y][x + 2];
		maxsum = max(temp, maxsum);
	}

	// ㅗ
	if (y - 1 >= 0 && x + 2 < M)
	{
		temp = a[y][x] + a[y][x + 1] + a[y - 1][x + 1] + a[y][x + 2];
		maxsum = max(temp, maxsum);
	}

	// ㅏ
	if (y + 2 < N && x + 1 < M)
	{
		temp = a[y][x] + a[y+1][x] + a[y + 2][x] + a[y+1][x +1];
		maxsum = max(temp, maxsum);
	}

	// ㅓ
	if (y + 2 < N && x - 1 >=0)
	{
		temp = a[y][x] + a[y + 1][x] + a[y + 2][x] + a[y + 1][x - 1];
		maxsum = max(temp, maxsum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			dfs(i, j, 0, a[i][j]);
			visited[i][j] = false;
			other(i, j);
		}
	}

	cout << maxsum;
	
	return 0;
};