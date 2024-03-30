#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int visited[10];
int ans[10];

void dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		for(int i =0; i <m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++)
	{
		//if (!visited[i])
		//{
			//visited[i] = true;
			ans[cnt] = arr[i];
			dfs(i, cnt + 1);
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

	dfs(0, 0);

	return 0;
}