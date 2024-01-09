#include <bits/stdc++.h>

using namespace std;

int T, edge;
vector<vector<int>> coms;
int visited[104];
int cnt;

void dfs(int n)
{
	visited[n] = 1;
	cnt++;

	if (coms[n].size())
	{
		for (int com : coms[n])
		{
			if (visited[com]) continue;

			dfs(com);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T >> edge;

	coms.resize(T+1);

	for (int i = 0; i < edge; i++)
	{
		int x, y;
		cin >> x >> y;
		coms[x].push_back(y);
		coms[y].push_back(x);
	}

	dfs(1);

	cout << cnt - 1;
};