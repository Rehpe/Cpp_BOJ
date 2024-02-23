#include <bits/stdc++.h>

using namespace std;

int M, N, H;
int x, y, z;
int dx[] = {1, -1, 0, 0 ,0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = { 0, 0, 0, 0, 1, -1 };

int tomato[104][104][104];
int visited[104][104][104];
int day;
bool allRipe;

// 3차원 배열을 관리하기 위한 struct
struct A
{
	int zz, xx, yy;
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> H;

	allRipe = true;
	queue<A> q;

	// 입력 받기
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];

				if (allRipe == true && tomato[i][j][k] == 0)
					allRipe = false;

				// 익은 토마토라면 입력 받음과 동시에 큐에 저장 & 방문처리
				if (tomato[i][j][k] == 1)
				{
					q.push({ i, j, k });
					visited[i][j][k] = 1;
				}

				// 벽이라면 방문배열에 -1 기록
				if (tomato[i][j][k] == -1)
				{
					visited[i][j][k] = -1;
				}
			}
		}
	}

	// 이미 모든 토마토가 익은 상태라면
	if (allRipe) cout << 0;
	else
	{
		// 익은 토마토에서 bfs
		while (q.size())
		{
			int z = q.front().zz;
			int x = q.front().xx;
			int y = q.front().yy;

			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				int nz = dz[i] + z;

				// 유효범위 밖일시
				if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H)	continue;

				// 벽(토마토 없는 공간) 일시
				if (tomato[nz][nx][ny] == -1) continue;

				// 이미 방문한 지점일시 (입력 순서대로, z,x,y 순임)
				if (visited[nz][nx][ny]) continue;

				// 위 조건이 아니라면, 거리 증가
				visited[nz][nx][ny] = visited[z][x][y] + 1;

				// 다시 q에 push
				q.push({ nz, nx, ny });
			}
		}

		// bfs가 모두 끝난 후, 3중 for문을 돌며 방문칸 체크
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					// 안 익은 토마토(방문한 적 없는 좌표)가 하나라도 있다면
					if (visited[i][j][k] == 0)
					{
						cout << -1;
						return 0;
					}

					day = max(day, visited[i][j][k]);
				}
			}
		}

		cout << day -1;
	}

	return 0;
};