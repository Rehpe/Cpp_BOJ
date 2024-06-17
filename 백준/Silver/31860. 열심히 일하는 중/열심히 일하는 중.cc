#include <bits/stdc++.h>

using namespace std;

int n, m, k;	// n: 일 갯수 m: 감소하는 중요도 k: k 이하면 완료한 것으로 간주
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		int imp;
		cin >> imp;
		pq.push(imp);
	}


	vector<int> v;
	int sati = 0;	// 만족감

	while (!pq.empty())
	{
		int imp = pq.top();
		pq.pop();

		sati = sati / 2 + imp;
		v.push_back(sati);
		
		imp -= m;
		if (imp > k) pq.push(imp);
	}

	cout << v.size() << '\n';
	for (int i : v)
	{
		cout << i << '\n';
	}

	return 0;
}