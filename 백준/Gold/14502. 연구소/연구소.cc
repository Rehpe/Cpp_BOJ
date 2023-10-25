#include <bits/stdc++.h>

using namespace std;

int N, M;
int origin[9][9];
int a[9][9];
int visited[9][9];
vector<pair<int, int>> space;
int dx[] = { 0, 0 ,-1, 1 };
int dy[] = { 1, -1, 0, 0 };
int cnt, maxcnt;

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;

		if (a[ny][nx] == 1 || visited[ny][nx] == 1)
			continue;

		a[ny][nx] = 2;
		dfs(ny, nx);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	// 입력 받기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> origin[i][j];
			// 벽을 세울 수 있는 좌표는 벡터에 푸시백
			if (origin[i][j] == 0)
				space.push_back({ i, j });
		}
	}

	// 복사
	memcpy(&a, &origin, sizeof(origin));

	// 벽을 세울 수 있는 좌표 중 3개를 조합으로 뽑고 벽 세움
	for (int i = 0; i < space.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				a[space[i].first][space[i].second] = 1;
				a[space[j].first][space[j].second] = 1;
				a[space[k].first][space[k].second] = 1;

				// dfs
				for (int l = 0; l < N; l++)
				{
					for (int m = 0; m < M; m++)
					{
						if (a[l][m] == 2 && visited[l][m] == 0)
							dfs(l, m);
					}
				}

				// max값 추출
				for (int o = 0; o < N; o++)
				{
					for (int p = 0; p < M; p++)
					{
						if (a[o][p] == 0)
							cnt++;
					}
				}

				maxcnt = max(cnt, maxcnt);

				// 원상복귀
				memcpy(&a, &origin, sizeof(origin));
				cnt = 0;
				fill(&visited[0][0], &visited[0][0] + 9 * 9, 0);
			}
		}
	}

	cout << maxcnt;
	return 0;
}