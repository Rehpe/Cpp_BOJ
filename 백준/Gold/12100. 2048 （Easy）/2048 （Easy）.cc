#include <bits/stdc++.h>

using namespace std;

int n;
int board[21][21];
int isSummed[21][21];
int maxnum;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


void move(int y, int x, int dir)
{
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= n)
		return;

	if (board[ny][nx] != 0)
	{
		if (board[ny][nx] == board[y][x])
		{
			if (!isSummed[ny][nx])
			{
				board[ny][nx] *= 2;
				isSummed[ny][nx] = 1;
				board[y][x] = 0;
			}
		}
		else
			return;
	}
	else
	{
		//다음 칸이 0이라면 0이 아닐때까지 탐색
		board[ny][nx] = board[y][x];
		board[y][x] = 0;
		move(ny, nx, dir);
		return;
	}
}

void movedir(int dir)
{
	// 위
	if (dir == 0)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				move(i, j, dir);
			}
		}
	}

	// 오른쪽
	else if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				move(i, j, dir);
			}
		}
	}

	// 아래쪽
	else if (dir == 2)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				move(i, j, dir);
			}
		}
	}

	// 왼쪽
	else if (dir == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				move(i, j, dir);
			}
		}
	}
}

void go(int cnt)
{
	if (cnt == 5)
	{
		int tempmax = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tempmax = max(tempmax, board[i][j]);
			}
		}
		maxnum = max(maxnum, tempmax);
		return;
	}

	int backup_board[21][21];

	for (int dir = 0; dir < 4; dir++)
	{
		// 이번 스택의 board 현황을 백업
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				backup_board[i][j] = board[i][j];
			}
		}

		memset(isSummed, 0, sizeof(isSummed));

		movedir(dir);

		go(cnt + 1);

		// 백업된 board로 원상복구
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board[i][j] = backup_board[i][j];
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for(int i= 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	go(0);

	cout << maxnum;

	return 0;
}