#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa


int N, M, K;	// 전체 판 크기, 직사각형 개수
int x1, x2, y1, y2;	// 직사각형의 좌하단(x1, x2), 우상단(y1, y2) 좌표
int pan[101][101], visited[101][101];
int dx[] = { 0 ,0 , -1, 1 }, dy[] = { -1, 1, 0, 0 };
vector<int> ret;	// 외부 영역의 크기를 담을 벡터

int dfs(int y, int x)
{
	//방문처리
	visited[y][x] = 1;

	// 외부 영역 한조각을 찾을 때마다 크기 +1
	// 정점의 값을 1이라 생각하고, 새로운 정점을 찾을 때마다 ++한다고 생각해도 됨
	int ret = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 유효범위 밖 혹은 이미 방문한 좌표는 continue
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[ny][nx] == 1) continue;

		// 외부 영역이 아닌 기존 직사각형 영역이라도 continue
		if (pan[ny][nx] == 1) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		// 입력받은 사각형을 바탕으로 사각형 내부를 1로 채움
		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				pan[y][x] = 1;
			}
		}
	}

	// 판 전체에 dfs 걸기
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 판의 빈 영역이면서 방문처리가 안되어있는 곳이라면
			if (pan[i][j] != 1 && visited[i][j] == 0)
			{
				// 반환타입이 int인 dfs를 돌려서 나온 결과값을 ret에 담기
				ret.push_back(dfs(i, j));
			}
		}
	}

	// ret을 바탕으로 결과 정리하기
	
	// 오름차순 정렬
	sort(ret.begin(), ret.end());
	
	// 영역 개수 출력
	cout << ret.size() << '\n';

	// 영역 크기 오름차순으로 출력
	for (int i : ret)
	{
		cout << i << " ";
	}

	return 0;
}
