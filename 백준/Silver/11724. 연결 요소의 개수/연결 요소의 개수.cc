#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> vert[1004];
int visited[1004];
int cnt;

void dfs(int x)
{
	visited[x] = 1;

	for (int i = 0; i < vert[x].size(); i++)
	{
		int idx = vert[x][i];
		if (visited[idx]) continue;
		dfs(idx);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		vert[x].push_back(y);
		vert[y].push_back(x);
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (visited[i]) continue;
		dfs(i);
		cnt++;
	}

	cout << cnt;

	return 0;
}