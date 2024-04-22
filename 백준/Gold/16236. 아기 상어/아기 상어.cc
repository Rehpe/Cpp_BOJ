#include <bits/stdc++.h>

using namespace std;

int n, m;
int maps[22][22];
int visited[22][22];
int dy[] = { 0,  0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int startX, startY;
int nearestdist;
int targetX, targetY;
int eatcnt;
int sharksize = 2;
int ans;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void find(int starty, int startx)
{
	memset(visited, 0, sizeof(visited));
	while (!pq.empty())
		pq.pop();

	queue<pair<int, int>> path;
	visited[starty][startx] = 1;
	path.push({ starty, startx });

	nearestdist = INT_MAX;

	while (path.size())
	{
		int y, x;
		tie(y, x) = path.front();
		path.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위 밖 불가능
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;

			// 방문한 좌표라면 불가능
			if (visited[ny][nx])	continue;

			// 아기 상어보다 큰 물고기가 있는 칸이라면 불가능
			if (maps[ny][nx] > sharksize)	continue;

			// 빈 칸 혹은 아기 상어와 같은 크기의 물고기 칸이라면 지나가기만 가능
			if (maps[ny][nx] == 0 || maps[ny][nx] == sharksize)
			{
				visited[ny][nx] = visited[y][x] + 1;
				path.push({ ny, nx });
			}

			// 아기 상어보다 작은 크기의 물고기라면 먹이 후보에 등록
			else if (maps[ny][nx] < sharksize)
			{
				visited[ny][nx] = visited[y][x] + 1;
				path.push({ ny, nx });

				// 최단거리 갱신했다면
				if (visited[ny][nx] < nearestdist)
				{
					nearestdist = visited[ny][nx];

					// pq 내의 모든 요소 제거 후 추가
					while (!pq.empty())
						pq.pop();

					pq.push({ny, nx});
				}
				// 기존 최단거리와 같다면
				else if (visited[ny][nx] == nearestdist)
				{
					// pq에 추가
					pq.push({ ny, nx });
				}
			}
		}
	}
}

void move(int starty, int startx, int targety, int targetx)
{
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> path;
	visited[starty][startx] = 1;
	path.push({ starty, startx });
	
	while (path.size())
	{
		int y, x;
		tie(y, x) = path.front();
		path.pop();

		// 목표 지점에 도착했다면 (먹기)
		if (y == targety && x == targetx)
		{
			// 도착지의 visited(몇 칸 걸렸는지)를 더하고
			ans += visited[y][x] - 1;

			// 먹이 먹은 양 ++
			eatcnt++;

			// 먹이칸 빈 칸으로 초기화
			maps[y][x] = 0;

			// 아기 상어의 현재 위치를 갱신하고 return;
			startY = y;
			startX = x;

			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny =  y + dy[i];
			int nx =  x + dx[i];

			// 범위 밖 불가능
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;

			// 방문한 좌표라면 불가능
			if (visited[ny][nx])	continue;

			// 아기 상어보다 큰 물고기가 있는 칸이라면 불가능
			if (maps[ny][nx] > sharksize)	continue;

			// 빈칸, 못먹는 물고기칸, 목표칸이라면 vistied + 1 
			if (maps[ny][nx] == 0 || maps[ny][nx] <= sharksize)
			{
				visited[ny][nx] = visited[y][x] + 1;
				path.push({ ny, nx });
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];

			// 아기 상어 시작 위치 기록
			if (maps[i][j] == 9)
			{
				startX = j;
				startY = i;
				maps[i][j] = 0;
			}
		}
	}

	while (true)
	{
		// 먹이 탐색
		find(startY, startX);

		// 먹이가 없다면 루프 종료
		if (pq.empty())
			break;

		// 타겟 좌표 추출
		tie(targetY, targetX) = pq.top();

		// 타겟 좌표로 이동
		move(startY, startX, targetY, targetX);

		// 아기 상어가 몸집만큼의 물고기를 먹었다면 몸집을 키운다
		if (eatcnt == sharksize)
		{
			sharksize++;
			eatcnt = 0;
		}
	}

	cout << ans;
}