#include <bits/stdc++.h>
using namespace std;

int N, M;	// 판의 세로, 가로 길이
int pan[101][101], visited[101][101];
vector<pair<int, int>> vec;	// 이번에 녹여야할 치즈 좌표를 담은 벡터
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0,0,-1,1 };
int timecnt;	// 치즈가 녹아 없어지는데 걸리는 시간
int cheesecnt;	// 녹기 전 남아있는 치즈 조각

void go(int y, int x)
{
	// 방문 처리
	visited[y][x] = 1;

	// 방문한 판의 좌표가 치즈라면
	if (pan[y][x] == 1)
	{
		// 녹일 치즈 벡터에 담고 return;
		vec.push_back({ y,x });
		return;
	}

	// 방문한 판의 좌표가 치즈가 아니라면
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 유효하지 않은 곳이거나 방문한 곳을 제외하고 dfs
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
			continue;

		go(ny, nx);
	}
	return;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{	
			cin >> pan[i][j];
		}
	}

	// 이 문제는 탐색만이 필요하기 때문에 DFS/BFS 어느 쪽으로 풀어도 괜찮다

	while (true)
	{
		// 방문 배열 초기화
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

		// DFS로 찾아온, 녹여야할 치즈(1)의 좌표를 담은 벡터를 초기화한다.
		vec.clear();

		// 가장자리는 늘 비어있으므로 가장자리에서부터 bfs 시작
		go(0, 0);

		// 녹여야할 치즈 개수 저장
		cheesecnt = vec.size();

		// 벡터 내부의 치즈 좌표를 참고하여 판의 해당 치즈 부분을 0으로 녹여줌
		for (pair<int, int> cheese : vec)
		{
			pan[cheese.first][cheese.second] = 0;
		}

		// 전체 판을 탐색해서 아직 녹지 않은 치즈가 있다면 dfs flag true;
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (pan[i][j] != 0)	flag = true;
			}
		}

		// 시간  ++
		timecnt++;

		// flag가 false다 : 모든 치즈가 녹았다-> break
		if (!flag) break;
	}

	cout << timecnt << '\n' << cheesecnt << '\n';

}
