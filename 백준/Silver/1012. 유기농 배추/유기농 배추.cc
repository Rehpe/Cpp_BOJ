#include <bits/stdc++.h>
using namespace std;

int T;
int N, M, K;
int x, y;
int arr[54][54], visited[54][54];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ny, nx;
int ret;

void dfs(int y, int x)
{
	// 해당 함수 호출시 일단은 방문처리
	visited[y][x] = 1;

	// 4방향 접근
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		// 좌표가 유효범위 밖으로 나간 경우 무시한다
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		// 배열 좌표가 유효하고 / 방문 기록이 없다면 
		if (arr[ny][nx] == 1 && visited[ny][nx] == 0)
		{
			// 다시 dfs 호출
			dfs(ny, nx);
		}
	}
	return;
}



int main()
{
	// Test case 입력
	cin >> T;
	while (T--)
	{
		// arr 배열, visited 배열,  ret 초기화
		fill(&arr[0][0], &arr[0][0] + 54 * 54, 0);
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		ret = 0;

		// 가로/세로/배추 개수 입력
		cin >> M >> N >> K;

		// 배추 개수만큼 배추 좌표 입력
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}

		// 맵 크기만큼 탐색
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				// 배열 내 좌표가 유효하고 방문 기록이 없다면
				if (arr[i][j] == 1 && visited[i][j] == 0)
				{
					// 해당 좌표로 dfs 호출 후 결과값++
					dfs(i, j);
					ret++;
				}
			}
		}

		cout << ret << '\n';
	}
}
