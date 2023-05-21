#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> vec;

bool cmp(string& a, string& b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		vec.push_back(s);
	}

	sort(vec.begin(), vec.end(), cmp);

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (string s : vec)
	{
		cout << s << '\n';
	}
}