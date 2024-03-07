#include <bits/stdc++.h>

using namespace std;

int N;
char color[101][101];
int visited[101][101];
int blindvisited[101][101];
int norcnt, blindcnt;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void nordfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
		if (visited[ny][nx]) continue;
		if (color[y][x] == color[ny][nx])
		{
			nordfs(ny, nx);
		}
	}
}

void blinddfs(int y, int x)
{
	blindvisited[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
		if (blindvisited[ny][nx]) continue;
		if (color[y][x] == color[ny][nx])
		{
			blinddfs(ny, nx);
		}
		else
		{
			if ((color[y][x] == 'R' && color[ny][nx] == 'G') || (color[y][x] == 'G' && color[ny][nx] == 'R'))
				blinddfs(ny, nx);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> color[j][i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[j][i])
			{
				nordfs(j, i);
				norcnt++;
			}
			if (!blindvisited[j][i])
			{
				blinddfs(j, i);
				blindcnt++;
			}
		}
	}

	cout << norcnt << ' ' << blindcnt;

	return 0;
};