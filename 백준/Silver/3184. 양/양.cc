#include <bits/stdc++.h>

using namespace std;

int r, c;
char maps[251][251];
int visited[251][251];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int sheep, wolf;
int tempsheep, tempwolf;

void dfs(int y, int x)
{
	if (maps[y][x] == 'o') tempsheep++;
	if (maps[y][x] == 'v') tempwolf++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx]) continue;
		if (maps[ny][nx] == '#') continue;
		
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == 'o' || maps[i][j] == 'v')
			{
				if (visited[i][j]) continue;

				tempsheep = 0;
				tempwolf = 0;
				visited[i][j] = 1;
				dfs(i, j);
				if (tempsheep > tempwolf) sheep += tempsheep;
				else wolf += tempwolf;
			}
		}
	}

	cout << sheep << " " << wolf;

	return 0;
}