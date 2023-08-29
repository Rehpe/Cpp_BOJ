#include <bits/stdc++.h>
using namespace std;

int N;
int height;
int safe;
int ret;
int x, y, nx, ny;
int dx[] = { -1, 0, 1 ,0 };
int dy[] = { 0, -1, 0, 1 };
int arr[104][104];
int visited[104][104];

void dfs(int y, int x, int height)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		if (visited[ny][nx] == 0 && arr[ny][nx] >= height)
			dfs(ny, nx, height);
	}

	return;
}



int main()
{
	cin >> N;

	ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}

	for (int k = 0; k < 101; k++)
	{
		// 초기화
		safe = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0 && arr[i][j] >= k)
				{
					dfs(i, j, k);
					safe++;
				}
			}
		}
		if (safe < 1)
			break;

		ret = max(safe, ret);
	}

	cout << ret;

}
