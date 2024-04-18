#include <bits/stdc++.h>

using namespace std;

#define right aaa
#define left bbb

int n, m;
int r, c, d;
int room[54][54];
int cleanroom;
//bool isAnyDirtyRoom;

pair<int, int> up, down, right, left;

bool isAnyDirtyRoom(int y, int x)
{
	// 주변 네 칸 청소 여부 확인
	up = { y - 1, x };
	down = { y + 1, x };
	right = { y, x + 1 };
	left = { y, x - 1 };

	for (auto dir : { up, down, right, left })
	{
		int ny = dir.first;
		int nx = dir.second;

		// 유효범위 밖이라면
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		// 4방향 중 한 방향에라도 청소되지 않은 방이 있는 경우
		if (room[ny][nx] == 0)
		{
			return true;
		}
	}
	return false;
}

pair<int, int> goback(int y, int x, int d)
{
	pair<int, int> next;

	up = { y - 1, x };
	down = { y + 1, x };
	right = { y, x + 1 };
	left = { y, x - 1 };

	// 북쪽(위) => 후진해야할 칸 : down
	if (d == 0)
		next = down;
	// 동쪽(오른쪽) => 후진해야할 칸 : left
	else if (d == 1)
		next = left;
	// 남쪽(아래쪽) => 후진해야할 칸 : up
	else if (d == 2)
		next = up;
	// 서쪽(왼쪽) => 후진해야할 칸: right
	else
		next = right;

	return next;
}

int turnCounterClockwise(int d)
{
	d -= 1;
	if (d < 0) d = 3;

	return d;
}

pair<int, int> gofront(int y, int x, int d)
{
	up = { y - 1, x };
	down = { y + 1, x };
	right = { y, x + 1 };
	left = { y, x - 1 };

	// 북쪽(위)
	if (d == 0)
		return up;
	// 동쪽(오른쪽)
	else if (d == 1)
		return right;
	// 남쪽(아래쪽)
	else if (d == 2)
		return down;
	// 서쪽(왼쪽)
	else
		return left;
}

void sol(int y, int x, int d)
{
	// 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다
	if (room[y][x] == 0)
	{
		room[y][x] = -1;
		cleanroom++;
	}

	// 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
	if (!isAnyDirtyRoom(y, x))
	{
		// 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
		// 현재 d에 따라 후진해야할 칸을 판별한다
		
		// 후진할 next 칸이 유효한지 확인
		int ny, nx;
		tie(ny, nx) = goback(y, x, d);

		// 후진 가능한 경우
		if (room[ny][nx] == 0 || room[ny][nx] == -1)
			sol(ny, nx, d);
		// 후진 불가능할 경우
		else
			return;
	}
	// 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
	else
	{
		int newdir = turnCounterClockwise(d);

		int ny, nx;
		tie(ny, nx) = gofront(y, x, newdir);

		// 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한 후 1번으로 돌아간다.
		if (room[ny][nx] == 0)
		{
			sol(ny, nx, newdir);
		}
		// 아닐 경우 전진하지 않고 1번으로 돌아간다
		else
		{
			sol(y, x, newdir);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}

	sol(r, c, d);
	
	cout << cleanroom;

	return 0;
}