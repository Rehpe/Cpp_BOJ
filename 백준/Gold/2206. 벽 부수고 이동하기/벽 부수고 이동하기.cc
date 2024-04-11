#include <bits/stdc++.h>

using namespace std;

#define time aaa

int n, m;
int graph[1004][1004];
int visited[1004][1004][2];	// y, x, 벽을 부술 수 있는 횟수(1, 0)
int y, x, breakcnt;
int ans = -1;

int dy[] = {1, -1 , 0, 0};
int dx[] = { 0,  0, 1, -1 };

queue<pair<pair<int, int>, int>> q;	// 좌표(y, x) 와 남은 벽 부수기 횟수

void bfs()
{
	while (q.size())
	{
		tie(y, x) = q.front().first;
		breakcnt = q.front().second;
		q.pop();

		// 목표 지점에 도착 시 최단 거리 출력
		if (y == n && x == m)
		{
			ans =  visited[y][x][breakcnt];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)	continue;
			
			//if (visited[ny][nx][0] || visited[ny][nx][1]) continue;

			// case 1. 벽 부수기 횟수가 남아있는 상태에서 길이 막혀있는 경우
			else if (breakcnt && graph[ny][nx] == 1 && visited[ny][nx][1] == 0)
			{
				// 벽을 부수고, 벽 부수기 횟수를 차감하고 나아간다
				visited[ny][nx][0] = visited[y][x][1] + 1;
				q.push({ {ny, nx}, 0 });
			}

			// case 2. 벽 부수기 횟수가 남아있는 상태에서 길이 뚫려있는 경우
			if (breakcnt && graph[ny][nx] == 0 && visited[ny][nx][1] == 0)
			{
				// 벽을 부수지 않고 나아간다
				visited[ny][nx][1] = visited[y][x][1] + 1;
				q.push({ {ny, nx},1 });
			}

			// case 3. 남은 벽 부수기 횟수가 0인 상태에서 길이 뚫려있는 경우
			else if (!breakcnt && graph[ny][nx] == 0 && visited[ny][nx][1] == 0 && visited[ny][nx][0] == 0)
			{
				// 나아간다
				visited[ny][nx][0] = visited[y][x][0] + 1;
				q.push({ {ny, nx}, 0 });
			}

			// case 4. 남은 벽 부수기 횟수가 0인 상태에서 길이 막혀있는 경우
			else
				continue; // 진행 불가능
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			graph[i][j] = s[j - 1] -'0';
		}
	}

	visited[1][1][1] = 1;
	q.push({ { 1, 1 }, 1 });

	bfs();

	cout << ans;

	return 0;
}