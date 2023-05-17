#include <bits/stdc++.h>
using namespace std;

int N;
int x, y;
vector<pair<int, int>> coord;

int cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	sort(coord.begin(), coord.end(), cmp);

	for (int i = 0; i < coord.size(); i++)
	{
		cout << coord[i].first << " " << coord[i].second;

		if (i == coord.size() - 1)
			return 0;
		else
			cout << '\n';
	}

};