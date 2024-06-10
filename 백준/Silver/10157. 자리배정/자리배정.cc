#include <bits/stdc++.h>

using namespace std;

int c, r;
int maps[1001][1001];
int visited[1001][1001];
int k;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> c >> r >> k;

	if (k > r * c)
	{
		cout << 0;
		return 0;
	}
	else if (k == 1)
	{
		cout << 1 << " " << 1;
		return 0;
	}

	int y = 1;
	int x = 1;
	int num = 1;
	visited[y][x] = 1;
	string dir = "up";

	while (num <= k)
	{
		num++;

		int ny =0;
		int nx =0;

		if (dir == "up")
		{
			ny = y;
			nx = x+1;

			if ((ny > c || nx > r || ny <= 0 || nx <= 0) || visited[ny][nx])
			{
				dir = "right";
				ny = y+1;
				nx = x;
			}
		}
		else if (dir == "right")
		{
			ny = y+1;
			nx = x;

			if ((ny > c || nx > r || ny <= 0 || nx <= 0) || visited[ny][nx])
			{
				dir = "down";
				ny = y;
				nx = x-1;
			}
		}
		else if (dir == "down")
		{
			ny = y;
			nx = x-1;

			if ((ny > c || nx > r || ny <= 0 || nx <= 0) || visited[ny][nx])
			{
				dir = "left";
				ny = y-1;
				nx = x;
			}
		}
		else if (dir == "left")
		{
			ny = y-1;
			nx = x;

			if ((ny > c || nx > r || ny <= 0 || nx <= 0) || visited[ny][nx])
			{
				dir = "up";
				ny = y;
				nx = x+1;
			}
		}
		
		visited[ny][nx] = 1;
		y = ny;
		x = nx;
		if (num == k)
		{
			cout << y << " " << x;
			break;
		}
	}
	return 0;
}