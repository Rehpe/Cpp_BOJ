#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<pair<string, int>> v;
string alpha[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven",
					"eight", "nine" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		string s = to_string(i);

		string a = "";
		for (int i = 0; i <= s.size(); i++)
		{
			a += alpha[s[i] - '0'];
		}
		v.push_back({ a, i });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			cout << '\n';
		cout << v[i].second << " ";
	}

	return 0;
}