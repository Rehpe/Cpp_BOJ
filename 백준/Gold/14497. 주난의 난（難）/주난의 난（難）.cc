#include <bits/stdc++.h>

using namespace std;
#define y1 aaa

int N, M;
int x, y, x1, y1, x2, y2;
int cnt;

char maps[304][304];
int visited[304][304];

queue<pair<int, int>> q;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> x1 >> y1 >> x2 >> y2;

	x1--;
	y1--;
	x2--;
	y2--;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}

	visited[x1][y1] = 1;
	q.push({ x1, y1 });
	
	// 목표 좌표를 0으로 만들 때까지 루프
	while (maps[x2][y2] != '0')
	{
		cnt++;

		// 매번 초기화되어야하므로 전역변수가 아니라 지역변수로 새로 선언함
		queue<pair<int, int>> temp;
		
		while (q.size())
		{
			tie(x, y) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= M || nx >= N)	continue;
				if (visited[nx][ny]) continue;

				//visited에 몇 번째 공격인지 기록
				visited[nx][ny] = cnt;

				// 0(빈칸)을 만나면 계속 진행
				if (maps[nx][ny] == '0')
				{
					q.push({ nx, ny });
				}
				// 그 외(1, #)를 만나면 기존 맵을 0으로 만든 후 다른 큐에 푸시
				else
				{
					maps[nx][ny] = '0';
					temp.push({ nx, ny });
				}
			}
		}
		// 맵을 돌며 빈 공간이 아닌 곳을 만나면 기존 맵을 수정하고 해당 좌표를 새로운 큐에 저장함
		// 빈 공간을 만나면 계속해서 퍼져나가야하므로 원래 큐에 푸시함
		// 원래 큐가 끝났다는 것은 해당 턴에 도달할 수 있는 모든 빈 공간을 순회완료했다는 뜻으로, 
		// 해당 턴에 만났던 1 좌표를 기록한 큐와 순회할 큐를 변경한다.
		q = temp;
	}

	cout << visited[x2][y2];
}