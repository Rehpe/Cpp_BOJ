#include <bits/stdc++.h>

using namespace std;
#define y1 aaa

int R, C, x, y;
int alphabet[26];
char maps[21][21];
int ret = INT_MIN;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void go(int y, int x, int cnt)
{
	// cnt의 최대값을 저장한다
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

		char alpha = maps[ny][nx];

		// 이미 지나온 적 있는 알파벳이라면 continue
		if (alphabet[alpha - 'A']) continue;
		
		// 지나온 적 없는 알파벳이라면 방문처리 후 cnt를 1 늘려서 재귀호출
		else
		{
			alphabet[alpha - 'A'] = 1;
			go(ny, nx, cnt + 1);

			// 이후 완탐을 위해 원상복구
			alphabet[alpha - 'A'] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> maps[i][j];
		}
	}

	alphabet[maps[0][0] - 'A'] = 1;
	go(0, 0, 1);

	cout << ret;
}