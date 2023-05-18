#include <bits/stdc++.h>
using namespace std;

int N;
int x, y;
vector<pair<int, int>> coord;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	sort(coord.begin(), coord.end());

	for (int i = 0; i < N; i++)
	{
		cout << coord[i].first << ' ' << coord[i].second;

		if (i == N - 1)
			return 0;
		else
			cout << '\n';
	}
	
}