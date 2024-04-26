#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[] = { -1,0,1,0 };	// 상-우-하-좌
int dx[] = { 0,1,0,-1 };	
int maps[9][9];
int cctvcnt, wallcnt;
vector<pair<int, int>> cctv;
set<pair<int, int>> view;
int ans = INT_MAX;

void straight(int y, int x, int dir)
{
	// dir이 4를 넘더라도 0~3 내의 범위를 가지게 함
	dir %= 4;

	while (true)
	{
		// 방향에 따라 일직선으로 감시하는 공간을 체크한다
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		y = ny;
		x = nx;

		// 맵 밖으로 나가면 종료
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			break;

		// 벽을 만나면 종료
		if (maps[ny][nx] == 6)	break;

		// 빈 공간이라면
		if (maps[ny][nx] == 0)
		{
			// 시야 set에 해당 좌표 넣기
			view.insert({ ny, nx });

			//maps[ny][nx] = -1;
		}

		else
			continue;
	}
}

// idx 개의 cctv를 가능한 모든 방향으로 체크해보는 dfs 함수
void cctv_check(int idx)
{
	// 모든 cctv를 검사했다면
	if (idx == cctvcnt)
	{
		// 맵 전체 크기 - 벽 개수 - cctv 개수 - 보이는 구역 개수
		int temp_ans = n * m - wallcnt - cctvcnt - view.size();
		ans = min(ans, temp_ans);
		return;
	}

	int y = cctv[idx].first;
	int x = cctv[idx].second;
	set<pair<int, int>> temp_view;

	// 4방향으로 돌려본다
	for (int dir = 0; dir < 4; dir++)
	{
		temp_view = view;

		if (maps[y][x] == 1)
		{
			straight(y, x, dir);
		}
		else if (maps[y][x] == 2)
		{
			straight(y, x, dir);
			straight(y, x, dir + 2);
		}
		else if (maps[y][x] == 3)
		{
			straight(y, x, dir);
			straight(y, x, dir + 1);
		}
		else if (maps[y][x] == 4)
		{
			straight(y, x, dir);
			straight(y, x, dir + 1);
			straight(y, x, dir + 3);
		}
		else if(maps[y][x] == 5)
		{
			straight(y, x, dir);
			straight(y, x, dir + 1);
			straight(y, x, dir + 2);
			straight(y, x, dir + 3);
		}

		cctv_check(idx + 1);

		view = temp_view;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];

			// cctv일 경우 벡터에 push
			if (maps[i][j] != 0 && maps[i][j] != 6)
				cctv.push_back({ i, j });

			// 벽이라면 벽 개수 count
			if (maps[i][j] == 6)
				wallcnt++;
		}
	}

	// cctv 개수 저장
	cctvcnt = cctv.size();

	cctv_check(0);
	cout << ans;

	return 0;
}
