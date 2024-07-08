#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int q; 
int cnt[1001]; // 진입 차수
vector<int> graph[1001];
int cost[1001];
long long dp[1001];	// dp[i] : i를 완료하는데 드는 시간

void topologySort()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)	// 진입 차수가 0이라면, 즉 선행으로 지어져야할 건물이 없는 건물이라면(첫 건물)
		{
			dp[i] = cost[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		for (int i = 0; i < graph[v].size(); i++)
		{
			int next = graph[v][i];		// 방문 후
			cnt[next]--;				// 진입 차수 제거

			// 해당 레벨에서 더 큰 쪽을 선택
			dp[next] = max(dp[next], dp[v] + cost[next]);

			if (cnt[next] == 0) q.push(next);	// 진입 차수가 0이라면 q에 푸시
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(cost, 0, sizeof(cost));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 1001; i++)
		{
			graph[i].clear();
		}

		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < k; i++)
		{
			int first; int after;
			cin >> first >> after;
			graph[first].push_back(after);
			cnt[after]++;	// 진입 차수
		}
		cin >> q;
		topologySort();

		cout << dp[q] << '\n';
	}
	return 0;
}