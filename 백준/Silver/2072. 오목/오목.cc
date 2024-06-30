#include <bits/stdc++.h>

using namespace std;

int n;
int maps[20][20];
vector < pair<int, int>> dy = { {1, -1},{0, 0}, {-1, 1}, {1, -1} };
vector < pair<int, int>> dx = { {0, 0},{-1, 1}, {1, -1}, {1, -1} };

int dfs(int y, int x, int dy, int dx, int color)
{
	// 범위 밖이거나 다른 돌이 있거나 돌이 없다면 return
	int cnt = 0;

	while (true)
	{

		if (y <= 0 || x <= 0 || y > 19 || x > 19) break;
		if(maps[y][x] == color*-1)	break;	 // 다른 색 돌일 때
		if (maps[y][x] == 0)	break; //빈 칸일 때

		cnt++;

		int ny = y + dy;
		int nx = x + dx;

		y = ny;
		x = nx;
	}

	return cnt;
}

bool check(int y, int x)
{
	int color = maps[y][x];

	// 각각 2개의 방향으로 4가지 케이스(상-하/  좌-우/ 우상향 / 우하향) 에 대해 dfs를 돌려본다.
	for (int i = 0; i < 4; i++)
	{
		int count = 1;

		// 1번 방향
		int diry = dy[i].first;
		int dirx = dx[i].first;
		int ny = y + diry;
		int nx = x + dirx;

		count += dfs(ny, nx, diry, dirx, color);
		
		// 2번 방향
		diry = dy[i].second;
		dirx = dx[i].second;
		ny = y + diry;
		nx = x + dirx;

		count += dfs(ny, nx, diry, dirx, color);

		if (count == 5) return true;
	}
	
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int y, x;
		cin >> y >> x;
		if (i & 1) // i가 홀수라면 흑
			maps[y][x] = 1;
		else      // i가 짝수라면 백
			maps[y][x] = -1;

		// 오목이 되려면 최소 각각 5알 이상 둬야하므로
		if (i >= 8)
			if (check(y, x))
			{
				cout << i;
				exit(0);
			}
	}

	cout << -1;

	return 0;
}