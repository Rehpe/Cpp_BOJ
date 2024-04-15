#include <bits/stdc++.h>

using namespace std;

#define MAX INT_MAX - 1

int n, m;
int start, dest;
vector<vector<pair<int, int>>> graph;
int dist[1004];
int visited[1004];


void dijkstra(int start)
{
	fill(dist + 1, dist + n + 1, MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curdist = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		if (visited[curnode]) continue;
		visited[curnode] = true;

		for (int i = 0; i < graph[curnode].size(); i++)
		{
			int nextnode = graph[curnode][i].second;
			int nextdist = curdist + graph[curnode][i].first;

			if ( nextdist < dist[nextnode])
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

	cin >> n >> m;

	graph.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, d;
		cin >> from >> to >> d;
		graph[from].push_back({ d, to });
	}

	cin >> start >> dest;

	dijkstra(start);

	cout << dist[dest];

	return 0;
}