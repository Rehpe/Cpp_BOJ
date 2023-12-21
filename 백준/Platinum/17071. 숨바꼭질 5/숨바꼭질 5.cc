#include <bits/stdc++.h>

using namespace std;

int N, K;	// 수빈이의 위치, 동생의 위치
int visited[2][5000004];	// 짝수턴/홀수턴의 수빈이가 특정 좌표에 도달했는지에 대한 2차원 배열
queue<int> q;
bool ok = false;
int turn = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	// 수빈위치 = 동생위치라면 0 반환
	if (N == K)
	{
		cout << 0;
		return 0;
	}

	// 수빈 위치 방문배열 체크 후 Queue에 푸시
	visited[0][N] = 1;
	q.push(N);

	while (q.size())
	{
		// (동생 좌표부터 계산) 동생은 매턴마다 해당 턴만큼 가속하여 앞으로 나간다
		K += turn;

		// 동생이 범위를 초과하면 break 
		if (K > 500000) break;

		// 만약 수빈이가 짝수 / 홀수 턴에 K좌표에 도달한 적이 있다면, 언제나 앞으로 돌아오는 짝수 / 홀수 턴에 K좌표에 도달할 수 있다
		// 왜냐면 해당 좌표에서 +1, -1을 하여 두 턴을 써서 제자리로 돌아오면 되기 때문이다
		// 따라서 짝수/홀수 번째 턴에 동생 좌표에 방문기록이 있다면 방문 가능이므로 break
		if (visited[turn % 2][K])
		{
			ok = true;
			break;
		}

		int	qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int here = q.front();
			q.pop();

			for (int next : { here + 1, here - 1, here * 2})
			{
				// 범위를 넘어갔거나, 같은 홀/짝 턴에 next 방문 기록이 있다면 continue
				if (next < 0 || next > 500000 || visited[turn % 2][next]) continue;

				visited[turn % 2][next] = visited[turn % 2][next] + 1;

				// 만약 같은 턴에 둘이 마주친다면 flag값 켜고 바로 break
				if (next == K)
				{
					ok = true;
					break;
				}

				// 다음 좌표 push
				q.push(next);
			}
			// 내부 for문에서 ok 가 true일 때 여기 다시 걸리면서 qSize for문을 탈출할 것이다.
			if (ok)	break;
		}
		// 내부에서 ok가 true일 때 여기에 다시 걸리며 최종적으로 while문을 탈출할 것이다.
		if (ok) break;

		// 모든 로직이 끝나면 turn을 증가시킨다.
		turn++;
	}

	// ok 가 true다 = 1. 동생의 좌표에 수빈이가 미리 방문한 적이 있을 경우(단, 현재 턴과 수빈이가 해당 좌표를 방문했던 턴의 짝.홀이 일치해야함)
	//				2. 동생과 수빈이가 그냥 같은 턴에 만난 경우 
	if (ok) cout << turn << '\n';
	else cout << -1 << '\n';

	return 0;
}