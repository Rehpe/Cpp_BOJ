#include <bits/stdc++.h>

using namespace std;


int n, apple, l;	// 보드칸, 사과, 방향 변환 횟수
int board[104][104];
map<int, char> turn;
deque<pair<int, int>> snakebody;
int timer;
int curdir;	// 뱀 방향

pair<int, int> nextcoord(pair<int, int> head, int dir)
{
	switch (dir)
	{
		// 위
		case 0:
			return { head.first - 1, head.second };
			break;

		// 오른쪽
		case 1:
			return { head.first, head.second +1 };
			break;

		// 아래
		case 2:
			return { head.first + 1, head.second };
			break;

		// 왼쪽
		case 3:
			return { head.first, head.second-1 };
			break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> apple;
	for (int i = 0; i < apple; i++)
	{
		int row, column;
		cin >> row >> column;
		board[row][column] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char dir;
		cin >> sec >> dir;
		turn[sec] = dir;
	}

	snakebody.push_back( { 1, 1 });
	
	// 초기 뱀의 방향은 오른쪽
	curdir = 1;

	// 보드에 뱀 위치 기록
	board[1][1] = -1;

	while (true)
	{
		// 0. 1초 증가
		timer++;

		// 1. 향하는 방향으로 한 칸 늘어남
		pair<int, int> head = snakebody.back();
		pair<int, int> next = nextcoord(head, curdir);

		// 1-1. next의 좌표가 범위 밖(벽)이라면 끝
		if (next.first <1 || next.second < 1 || next.first > n || next.second > n)
			break;

		// 1-2. next의 좌표가 뱀 몸통이라면 끝
		if (board[next.first][next.second] == -1)
			break;

		// 1-3. 위에 해당하지 않는다면 next를 snakebody에 추가함
		snakebody.push_back({next.first, next.second});
		
		// 2. next 칸의 사과 여부에 따라 처리
		// 2-1. 사과가 없는 경우
		if (board[next.first][next.second] != 1)
		{
			// 꼬리 한 칸 삭제
			pair<int, int> tail = snakebody.front();
			snakebody.pop_front();
			board[tail.first][tail.second] = 0;

			// 추가된 좌표를 뱀 위치로 기록 (머리가 됨)
			board[next.first][next.second] = -1;
		}
		// 2-2. 사과가 있는 경우
		else
		{
			// 추가된 좌표를 뱀 위치로 기록 (머리가 됨)
			board[next.first][next.second] = -1;
		}

		// 3. 해당 초에 방향 전환이 있다면 방향을 전환함
		if (turn[timer])
		{	
			// 오른쪽 전환
			if (turn[timer] == 'D')
			{
				curdir += 1;
				if (curdir > 3) curdir = 0;
			}
			// 왼쪽 전환
			else
			{
				curdir -= 1;
				if (curdir < 0) curdir = 3;
			}
		}
	}

	cout << timer;

	return 0;
}