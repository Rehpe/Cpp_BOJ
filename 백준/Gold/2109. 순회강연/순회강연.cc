#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, d;
		cin >> p >> d;
		v.push_back({ d, p });
	}

	// 기한(day)이 짧은 순으로 정렬
	sort(v.begin(), v.end());

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		int pay = v[i].second;
		int day = v[i].first;

		pq.push(pay);

		if (pq.size() > day)
		{
			// pq-> pay가 오름차순(작은) 순으로 정렬되어있음
			pq.pop();	// day까지 얻을 수 있는 최소금액을 빼버림
		}
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}

	cout << ret;

	return 0;
}