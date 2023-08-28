#include <bits/stdc++.h>
using namespace std;

int  N, M, arr[104][104], visited[104][104], x, y;
string s;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	cin >> N >> M;

	// 다닥다닥 붙어있는 숫자를 문자열로 입력받은 후 배열에 넣기
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	
	//  반드시 시작점을 방문 처리한 뒤 큐에 넣는다
	visited[0][0] = 1;	
	q.push({ 0,0 });

	while (q.size())
	{
		// 큐의 front 좌표(y,x)를 꺼낸 뒤, pop한다
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 좌표가 유효범위 밖으로 나간 경우 또는 문제에 나온 0번(갈 수 없는 좌표)인 경우 무시한다
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 0)
				continue;

			// 이미 방문한 노드라면 무시한다
			if (visited[ny][nx])
				continue;

			// 방문한 적 없는 방문 가능 노드라면, 이전 비용에 1을 더해 기록한다.
			visited[ny][nx] = visited[y][x] + 1;

			q.push({ ny,nx });
		}
	}
	
	// 문제는 시작점을 0, 0이 아닌 1,1로 가정하므로 최종 출력시에는 각 좌표에 -1을 해준다.
	cout << visited[N - 1][M - 1];

	return 0;
};
