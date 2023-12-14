#include <bits/stdc++.h>

using namespace std;

int T, w, h, x, y;
char maps[1004][1004];
int fire[1004][1004];
int s[1004][1004];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

pair<int, int> location;
queue<pair<int, int>> q;
int minute;


bool isIn(int y, int x)
{
	return y >= 0 && x >= 0 && y < h && x <= w;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T)
	{
		// 초기화
		memset(maps, 0, sizeof(maps));
		memset(s, 0, sizeof(s));
		fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INT_MAX);
		location = { -1, -1 };
		minute = 0;

		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> maps[i][j];

				// 상근이라면
				if (maps[i][j] == '@')
				{
					s[i][j] = 1;
					location = { i, j };
				}

				// 불이라면
				if (maps[i][j] == '*')
				{
					fire[i][j] = 1;
					q.push({ i, j });
				}
			}
		}

		// 불 최단거리 구하기
		while (q.size())
		{
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!isIn(ny, nx)) continue;
				if (maps[ny][nx] == '#') continue;
				if (fire[ny][nx] != INT_MAX) continue;

				fire[ny][nx] = fire[y][x] + 1;
				q.push({ ny, nx });
			}
		}

		//상근이 최단거리 구하기
		q.push({ location.first, location.second });

		while (q.size())
		{
			tie(y, x) = q.front();
			q.pop();

			if (y == 0 || x == 0 || y == h - 1 || x == w - 1)
			{
				minute = s[y][x];
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!isIn(ny, nx)) continue;
				if (maps[ny][nx] == '#') continue;
				if (s[ny][nx]) continue;
				if (fire[ny][nx] <= s[y][x] + 1) continue;

				s[ny][nx] = s[y][x] + 1;
				q.push({ ny, nx });
			}
		}

		if (minute == 0) cout << "IMPOSSIBLE" << '\n';
		else cout << minute << '\n';

		T--;
	}

	return 0;
}