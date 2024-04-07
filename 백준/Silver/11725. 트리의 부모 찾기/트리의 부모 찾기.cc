#include <bits/stdc++.h>
using namespace std;

int n;	// 노드의 개수
vector<int> graph[100001];
int parent[100001];

void dfs(int root)
{
	for (int i = 0; i < graph[root].size(); i++)
	{
		int next = graph[root][i];

		// 부모가 0이다 -> 부모 설정이 되지 않았다 -> 방문한 적 없는 노드이다
		if (parent[next] == 0)
		{
			parent[next] = root;
			dfs(next);
		}
	}
}


void bfs(int root)
{
	queue<int> q;

	q.push(root);

	while (q.size())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < graph[here].size(); i++)
		{
			int child = graph[here][i];

			if (parent[child] == 0)
			{
				parent[child] = here;
				q.push(child);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 루트 노트에서부터 탐색 시작
	
	// dfs(재귀)
	dfs(1);

	// bfs(queue)
	//bfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}
