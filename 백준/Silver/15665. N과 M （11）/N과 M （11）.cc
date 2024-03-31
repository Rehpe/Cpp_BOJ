#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int visited[10];
int ans[10];
set<vector<int>> s; // 중복 제거용 set

void dfs(int cnt, int num)
{
	if (cnt == m)
	{
		vector<int> v;
		for (int i = 0; i < m; i++)
		{
			v.push_back(ans[i]);
		}
		s.insert(v);
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		//if (!visited[i])
		//{
			//visited[i] = true;
			ans[cnt] = arr[i];
			dfs(cnt + 1, i+1);
			//visited[i] = false;
		//}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	dfs(0,0);

	for (auto v : s)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}
