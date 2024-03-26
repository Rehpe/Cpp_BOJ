#include <bits/stdc++.h>

using namespace std;

#define time aaa

int N, M;
int arr[10];
int visited[10];

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++)
	{

		arr[cnt] = i;
		dfs(i, cnt+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	dfs(1 ,0);

	return 0;
}