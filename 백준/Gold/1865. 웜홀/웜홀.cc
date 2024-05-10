#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX/2


int t;
int n, m, w;
vector<pair<pair<int, int>, int>> v;
int dist[502];
bool flag;

void Bellman_Ford()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int start = v[j].first.first;
			int end = v[j].first.second;
			int cost = v[j].second;

			// 일반적으로 최단 거리를 구하기 위해서는 갱신되지 않은 정점의 경우 탐색하지 않지만
			// 이 문제의 경우 음수 사이클의 여부만을 파악하기 때문에 이 코드를 스킵한다
			// 이 부분을 스킵하면 시작점과 상관 없이, 연결되지 않은 고립된 정점이라도
			// 음수 사이클 여부를 파악할 수 있다
			// if (start == INF) continue;

			// 계산 후 비교 후 갱신
			if (dist[end] > dist[start] + cost)
				dist[end] = dist[start] + cost;
		}
	}
}

bool check_minus_cycle()
{
	// 한 번 더 검사하여 갱신되는 거리가 있는지(음수 사이클이 있는지) 체크
	for (int i = 0; i < v.size(); i++)
	{
		int start = v[i].first.first;
		int end = v[i].first.second;
		int cost = v[i].second;

		// n번째 검사에서 거리가 갱신된다면 음수 사이클이 존재한다는 의미
		if (dist[end] > dist[start] + cost)
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n >> m >> w;

		fill(dist, dist + n + 1, INF);
		v.clear();

		// 도로 입력
		for (int i = 0; i < m; i++)
		{
			int s, e, cost;
			cin >> s >> e >> cost;

			v.push_back({ {s, e}, cost });
			v.push_back({ {e, s}, cost });
		}

		// 웜홀 입력
		for (int i = 0; i < w; i++)
		{
			int s, e, cost;
			cin >> s >> e >> cost;

			v.push_back({ {s,e}, -cost });
		}

		Bellman_Ford();

		if (check_minus_cycle()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}