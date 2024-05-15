#include <bits/stdc++.h>

using namespace std;

int n, m;
int iceberg[302][302];
int visited[302][302];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int icecnt;
int year;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (iceberg[ny][nx] == 0) continue;	// 바다를 만나면 continue;
		if (visited[ny][nx]) continue;

		dfs(ny, nx);
	}
}


void melt()
{
	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (iceberg[ny][nx] == 0) continue;	// 바다를 만나면 continue;
			
			iceberg[ny][nx]--;
		}
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
			cin >> iceberg[i][j];

			// 바닷물 q에 저장
			if (iceberg[i][j] == 0)
				q.push({ i, j });
		}
	}

	// q 크기가 n * m이라면 이미 모든 칸이 녹아있다는 의미로 0 출력
	if (q.size() == n * m)
	{
		cout << 0;
		return 0;
	}

	while (true)
	{
		// 빙산 녹음
		melt();

		// 1년 추가
		year++;

		// visited / icecnt 초기화
		memset(visited, 0, sizeof(visited));
		icecnt = 0;

		// 빙산 개수 체크 & 바닷물 다시 q에 담음
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (iceberg[i][j] == 0)
					q.push({ i, j });

				if (iceberg[i][j] != 0 && !visited[i][j])
				{
					icecnt++;
					if (icecnt >= 2)
					{
						cout << year;
						return 0;
					}
					dfs(i, j);
				}
			}
		}

		// icecnt가 0이라는 것은 빙하가 전부 녹았다는 뜻이므로 0 출력
		if (icecnt == 0)
		{
			cout << 0;
			return 0;
		}
	}
}