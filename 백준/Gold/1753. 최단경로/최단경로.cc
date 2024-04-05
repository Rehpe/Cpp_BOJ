#include <bits/stdc++.h>
using namespace std;

int v, e, s; // v: 정점 수 e: 간선 수 s: 시작 정점
vector<vector<pair<int, int>>> maps; // maps[i] = { first, second } : 정점 i의 인접 정점 리스트, second는 인접 정점 인덱스, fisrt는 i정점부터 해당 정점까지의 거리

int dist[20002];	// dist[i] : 시작 정점에서 i 정점까지의 최단 거리
int visited[20002]; // 방문 처리 배열

void dijkstra(int startnode)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[startnode] = 0; // 시작 정점에서 시작 정점까지의 거리는 당연히 0
	pq.push({ 0, startnode });

	while (!pq.empty())
	{
		int curdist = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		for (int i = 0; i < maps[curnode].size(); i++)
		{
			int nextnode = maps[curnode][i].second;
			int nextdist = curdist + maps[curnode][i].first;

			if (nextdist < dist[nextnode])
			{
				dist[nextnode] = nextdist;
				pq.push({ nextdist, nextnode });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e >> s;

	maps.resize(v+1);
	
	for (int i = 0; i < e; i++)
	{
		int here, there, d;
		cin >> here >> there >> d;
		maps[here].push_back({ d, there });
	}
	
	// dist배열(최단 거리 테이블) INF로 초기화(인덱스가 1번부터 시작하므로 초기화도 1부터)
	fill(dist+1, dist + v+1, INT_MAX);

	dijkstra(s);

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INT_MAX)
			cout << "INF" <<'\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;
}
