#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;
int k;
int board[22][22];
int dice[7];
int moves[1001];

bool moveboard(int& x, int& y, int movedir)
{
	int nx = -1;
	int ny = -1;

	if (movedir == 1)	// 동
	{
		ny = y;
		nx = x + 1;
	}

	else if (movedir == 2)	// 서
	{
		ny = y;
		nx = x - 1;
	}

	else if (movedir == 3)	// 북
	{
		ny = y-1;
		nx = x;
	}

	else if (movedir == 4)	// 남
	{
		ny = y+1;
		nx = x;
	}

	if (ny < 0 || nx < 0 || ny >= n || nx >= m)
	{
		// 주사위가 범위 밖으로 나간다면 false를 반환
		return false;
	}

	x = nx;
	y = ny;

	return true;
}

void rolldice(int movedir)
{
	// 기존 dice 배열을 백업해둔다.
	int backup_dice[7];
	memcpy(backup_dice, dice, sizeof(dice));

	// 기존 주사위 : 위[1] 바닥[6] 상[2] 하[5] 좌[4] 우[3]

	// 동쪽으로 굴릴 때
	if (movedir == 1)
	{
		dice[1] = backup_dice[4];	// 위
		dice[6] = backup_dice[3];	// 바닥
		dice[4] = backup_dice[6];	// 좌
		dice[3] = backup_dice[1];	// 우
	}
	// 서쪽으로 굴릴 때
	else if (movedir == 2)
	{
		dice[1] = backup_dice[3];	// 위
		dice[6] = backup_dice[4];	// 바닥
		dice[4] = backup_dice[1];	// 좌
		dice[3] = backup_dice[6];	// 우
	}

	// 북쪽으로 굴릴 때
	else if (movedir == 3)
	{
		dice[1] = backup_dice[5];	// 위
		dice[6] = backup_dice[2];	// 바닥
		dice[2] = backup_dice[1];	// 상
		dice[5] = backup_dice[6];	// 하
	}

	// 남쪽으로 굴릴 때
	else if (movedir == 4)
	{
		dice[1] = backup_dice[2];	// 위
		dice[6] = backup_dice[5];	// 바닥
		dice[2] = backup_dice[6];	// 상
		dice[5] = backup_dice[1];	// 하
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> moves[i];
	}

	for (int i = 0; i < k; i++)
	{
		// 이동 결과가 보드칸 범위 내일 경우에만 내부 함수 실행
		if (moveboard(x, y, moves[i]))
		{
			// 주사위 굴리기
			rolldice(moves[i]);

			// 칸이 0일 경우
			if (board[y][x] == 0)
			{
				// 주사위 바닥면을 칸에 복사
				board[y][x] = dice[6];
			}
			// 칸이 0이 아닐 경우 
			else
			{
				// 칸의 숫자를 주사위 바닥면에 복사
				dice[6] = board[y][x];
				// 칸의 숫자는 0이 됨
				board[y][x] = 0;
			}

			// 주사위 윗면 출력
			cout << dice[1] << '\n';
		}
	}
}
