#include <bits/stdc++.h>

using namespace std;

int r, c, t;
int maps[54][54];
vector<pair<int, int>> cleanse;

struct dust
{
	int y;
	int x;
	int diffusing_dust;
};

vector<dust> dust_vec;

int cur_dust;
int prev_dust;

bool endflag;

// 상 - 우 - 하 - 좌
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int ans;


void diffuse()	// 미세먼지 확산
{
	dust_vec.clear();

	// 모든 칸에 접근, 미세먼지가 있는 칸의 경우 확산될 양 구하기
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == -1 || maps[i][j] == 0)	continue;

			// 확산될 양 구하기
			dust d;
			d.y = i;
			d.x = j;
			d.diffusing_dust = maps[i][j] / 5;

			dust_vec.push_back(d);
		}
	}

	// 확산시키기
	for (auto d : dust_vec)
	{
		int y = d.y;
		int x = d.x;

		// 좌표에서 상하좌우 diffusing_dust 확산
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)	continue;
			if (maps[ny][nx] == -1)	continue;
			
			maps[ny][nx] += d.diffusing_dust;
			maps[y][x] -= d.diffusing_dust;
		}
	}
}

// 반시계방향 공기청정
void counter_clockwise_cleanse(int y, int x, int dir, int prev_dust)
{
	// 현재 칸의 미세먼지 저장
	cur_dust = maps[y][x];
	if (cur_dust == -1) cur_dust = 0;

	// 4개의 포인트에서 방향값을 전환한다. ( 상-우-하-좌 순)

	// 1. 공기청정기 시작 위치 (오른쪽)
	if (y == cleanse[0].first && x == cleanse[0].second)
	{
		dir = 1;

		if (endflag)
			return;
	}

	// 2. 공기청정기 행 + c -1열 (위쪽)
	else if (y == cleanse[0].first && x == c - 1)
		dir = 0;

	// 3. 0 행 + c-1 열 (왼쪽)
	else if (y == 0 && x == c - 1)
		dir = 3;

	// 4. 0행 + 0열 (아래쪽)
	else if (y == 0 && x == 0)
		dir = 2;

	int ny, nx;
	ny = y + dy[dir];
	nx = x + dx[dir];

	// 이전 칸의 미세먼지 현재 칸으로 이동
	if (maps[y][x] != -1)
		maps[y][x] = prev_dust;


	// 시작 위치로 되돌아왔다면 endflag를 켜준다
	if (ny == cleanse[0].first && nx == cleanse[0].second)
		endflag = true;

	counter_clockwise_cleanse(ny, nx, dir, cur_dust);
}

// 시계방향 공기청정
void clockwise_cleanse(int y, int x, int dir, int prev_dust)
{
	// 현재 칸의 미세먼지 저장
	cur_dust = maps[y][x];
	if (cur_dust == -1) cur_dust = 0;

	// 4개의 포인트에서 방향값을 전환한다. ( 상-우-하-좌 순)

	// 1. 공기청정기 시작 위치 (오른쪽)
	if (y == cleanse[1].first && x == cleanse[1].second)
	{
		// 공기청정기 칸일 경우 가져온 이전 먼지를 정화한다
		dir = 1;

		if (endflag)
			return;
	}

	// 2. 공기청정기 행 + c -1열 (아래쪽)
	else if (y == cleanse[1].first && x == c - 1)
		dir = 2;

	// 3. r- 1행 + c-1 열 (왼쪽)
	else if (y == r-1 && x == c - 1)
		dir = 3;

	// 4. r-1행 + 0열 (위쪽)
	else if (y == r-1 && x == 0)
		dir = 0;

	int ny, nx;
	ny = y + dy[dir];
	nx = x + dx[dir];

	// 이전 칸의 미세먼지 현재 칸으로 이동
	if (maps[y][x] != -1)
		maps[y][x] = prev_dust;

	// 시작 위치로 되돌아왔다면 endflag를 켜준다
	if (ny == cleanse[1].first && nx == cleanse[1].second)
		endflag = true;

	clockwise_cleanse(ny, nx, dir, cur_dust);
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> maps[i][j];

			// 공기청정기 위치 기록
			if (maps[i][j] == -1)
			{
				cleanse.push_back({ i, j });
			}
		}
	}

	while (t--)
	{
		diffuse();

		endflag = false;
		counter_clockwise_cleanse(cleanse[0].first, cleanse[0].second, 1, 0);

		endflag = false;
		clockwise_cleanse(cleanse[1].first, cleanse[1].second, 1, 0);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == -1) continue;

			ans += maps[i][j];
		}
	}

	cout << ans;
}