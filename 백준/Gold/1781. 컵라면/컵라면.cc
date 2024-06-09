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
		int d, c;
		cin >> d >> c;
		v.push_back({ d, c });
	}

	 // 데드라인이 짧은 순으로 정렬
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		int dead = v[i].first;
		int cup = v[i].second;

		pq.push(cup);

		if (pq.size() > dead)
		{
			pq.pop();
		}
	}
	
	int ret = 0;
	while (!pq.empty())
	{
		ret += pq.top(); 
		pq.pop();
	}

	cout << ret;
	
	return 0;
}