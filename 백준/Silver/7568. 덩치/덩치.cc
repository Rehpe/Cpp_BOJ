#include <bits/stdc++.h>
using namespace std;

int N;
int x, y;
vector<pair<int, int>> body;		// 키, 몸무게

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		body.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;

		for (int j = 0; j < N; j++)
		{
			// 자신(i)보다 상대(j)의 덩치가 더 크다면
			if (body[i].first < body[j].first
				&& body[i].second < body[j].second)
				cnt++;
		}

		cout << cnt + 1 << " ";
	}
}