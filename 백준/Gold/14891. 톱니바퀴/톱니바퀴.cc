#include <bits/stdc++.h>

using namespace std;

int gear[4][8];
int k; // 회전 횟수
string s;
queue<pair<int, int>> rotation;
int gear_cur_dir[4];

void rotate_gear(int num, int dir)
{
	int rotated_gear[8];

	// 회전하지 않는 경우 -> return;
	if (dir == 0)
		return;

	// 시계방향인 경우
	if (dir == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			int next = (i + 1) % 8;
			rotated_gear[next] = gear[num][i];
		}
	}

	// 반시계방향인 경우
	else if(dir == -1)
	{
		for (int i = 0; i < 8; i++)
		{
			int next = i - 1;
			if (next < 0) next = 7;
			rotated_gear[next] = gear[num][i];
		}
	}

	// num 번째 톱니 갱신
	for (int i = 0; i < 8; i++)
	{
		gear[num][i] = rotated_gear[i];
	}
}

void to_left(int num, int dir)
{
	// 회전할 기어의 왼쪽 기어 확인, 회전 방향 기록

	if (num - 1 < 0) return;

	// num 기어(현재 기어) 6번과 num -1 기어(왼쪽 기어) 2번 비교

	if (gear[num][6] == gear[num-1][2])	// 같다면 더이상 왼쪽으로는 회전하지 않으므로 return
		return;
	else
	{
		// num-1의 회전방향 기록 후 하나 왼쪽으로 재귀호출
		gear_cur_dir[num - 1] = dir * -1;
		to_left(num - 1, dir * -1);
	}

	return;
}

void to_right(int num, int dir)
{
	// 회전할 기어의 오른쪽 기어 확인, 회전 방향 기록

	if (num + 1 > 3) return;

	// num 기어(현재 기어) 2번과 num +1 기어(오른쪽 기어) 6번 비교

	if (gear[num][2] == gear[num + 1][6])	// 같다면 더이상 왼쪽으로는 회전하지 않으므로 return
		return;
	else
	{
		// num+1의 회전방향 기록 후 하나 왼쪽으로 재귀호출
		gear_cur_dir[num + 1] = dir * -1;
		to_right(num + 1, dir * -1);
	}

	return;
}

void rotate_start(int num, int dir)
{
	// 1번 톱니의 2번과 2번 톱니의 6번
	// 2번 톱니의 2번과 3번 톱니의 6번
	// 3번 톱니의 2번과 4번 톱니의 6번이 맞닿아있음

	// 처음 회전시킬 기어의 회전방향 기록
	gear_cur_dir[num] = dir;

	// 회전할 기어의 왼쪽 확인
	to_left(num, dir);

	// 회전할 기어의 오른쪽 확인
	to_right(num, dir);

	// 기록된 회전방향대로 회전
	for (int i = 0; i < 4; i++)
	{
		int dir = gear_cur_dir[i];
		rotate_gear(i, dir);
	}
}

int score()
{
	int ans = 0;
	
	// 각 톱니의 12시 방향(0번) 확인
	for (int i = 0; i < 4; i++)
	{
		// S극인 경우
		if (gear[i][0] == 1)
		{
			ans += pow(2, i);
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			gear[i][j] = s[j] - '0';
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num, dir;
		cin >> num >> dir;
		rotation.push({ num, dir });
	}

	while (!rotation.empty())
	{
		int num, dir;
		tie(num, dir) = rotation.front();
		rotation.pop();

		rotate_start(num-1, dir);
		memset(gear_cur_dir, 0, sizeof(gear_cur_dir));	// 회전방향 초기화
	}

	cout << score();
	
	return 0;
}