#include <bits/stdc++.h>

using namespace std;

#define prev aaa

int N, K;
int visited[200004];
int prev[200004];
queue<int> q;
vector<int> route;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	//if (N == K)
	//{
	//	cout << 0 << '\n' << N;
	//}

	visited[N] = 1;

	q.push(N);

	while (q.size())
	{
		int here = q.front();
		q.pop();

		// K좌표에 도착했다면 종료
		if (here == K)
			break;

		for (int next : { here + 1, here - 1, here * 2})
		{
			if (0 <= next && next <= 100000)
			{
				if (!visited[next])
				{
					visited[next] = visited[here] + 1;
					prev[next] = here;
					q.push(next);
				}
			}
		}
	}

	// i는 K부터, i가 N이 아닐때까지(i가 N일 때 for문 종료), i = prev[i];
	// 즉 prev[k]부터 역순으로 prev를 벡터에 담는다.
	for (int i = K; i != N; i = prev[i])
	{
		route.push_back(i);
	}

	// i가 N일때 for문이 종료되므로 N이 담기지 않는다. 따라서 N(시작 좌표)를 따로 담아준다
	route.push_back(N);
	
	reverse(route.begin(), route.end());

	cout << visited[K] - 1 << '\n';
	for (int x : route)
	{
		cout << x << ' ';
	}

	return 0;
}