#include <bits/stdc++.h>

using namespace std;

#define MAX 10000001

int n, m, x;
int dist[1004];
int res[1004];
vector<vector<pair<int, int>>> maps;	// maps[i] = 정점 i의 인접 리스트, first는 해당 정점까지의 거리, second는 인접 정점
vector<vector<pair<int, int>>> revmaps;

void dijkstra(int startnode, vector<vector<pair<int, int>>> maps)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	fill(dist + 1, dist + n + 1, MAX);

	dist[startnode] = 0;
	pq.push({ 0, startnode });

	while (!pq.empty())
	{
		int curnode = pq.top().second;	// 현재 방문 중인 노드
		int curdist = pq.top().first;	// 시작 노드로부터 현재 노드까지의 거리
		pq.pop();

		for (int i = 0; i < maps[curnode].size(); i++)	// 현재 방문 중인 노드의 모든 인접 노드 탐색
		{
			int nextnode = maps[curnode][i].second;		// 현재 방문 노드의 i번째 인접 노드(다음 탐색할 노드)
			int nextdist = curdist + maps[curnode][i].first;	// 시작 노드부터 현재 방문 노드까지의 거리 + 현재 방문 노드부터 i번째 인접 노드까지의 거리
				
			if (nextdist < dist[nextnode])	// 위 값이 테이블에 기록된 시작 노드~방문노드의 i번째 인접노드의 거리보다 작다면
			{
				// 최단거리 테이블 갱신 후 pq에 삽입한다.
				dist[nextnode] = nextdist;
				pq.push({ nextdist, nextnode });
			}
		}
	}

	// result 배열에 합하여 기록한다
	for (int i = 1; i <= n; i++)
	{
		res[i] += dist[i];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;

	maps.resize(n + 1);
	revmaps.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int start, dest, d;
		cin >> start >> dest >> d;
		maps[start].push_back( { d, dest });
		revmaps[dest].push_back({ d, start });
	}

	// 정방향 그래프로 X에서부터 모든 마을까지의 최단 거리를 구함
	dijkstra(x, maps);

	// 역방향 그래프로 모든 마을에서부터 X까지의 최단 거리를 구함
	dijkstra(x, revmaps);

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, res[i]);
	}

	cout << ans;

	return 0;
}