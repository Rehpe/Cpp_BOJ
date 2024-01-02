#include <bits/stdc++.h>

using namespace std;

int N, M, V;
vector<int> edge[1004];
int visited[1004];
int x, y;

void dfs(int a)
{
	if (visited[a])	return;

	visited[a] = 1;
	cout << a << ' ';

	if (edge[a].size())
	{
		sort(edge[a].begin(), edge[a].end());

		for (int v : edge[a])
		{
			dfs(v);
		}
	}
}

void bfs()
{
	queue<int> q;

	q.push(V);
	visited[V] = 1;

	while (q.size())
	{
		x = q.front();
		cout << x << ' ';
		q.pop();

		if (edge[x].size())
		{
			sort(edge[x].begin(), edge[x].end());

			for (int v : edge[x])
			{
				if (visited[v]) continue;

				q.push(v);
				visited[v] = 1;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	dfs(V);
	cout << '\n';

	fill(visited, visited + 1004, 0);
	bfs();
}