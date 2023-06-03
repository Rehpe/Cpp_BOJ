#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, M;
string site, pw;
unordered_map<string, string> memo;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> site >> pw;
		memo.insert(make_pair(site, pw));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> site;
		cout << memo[site] << '\n';
	}
}

