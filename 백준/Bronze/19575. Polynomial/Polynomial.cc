#include <bits/stdc++.h>

using namespace std;


#define MOD 1000000007

long long n, x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;

	vector<long long> kyesus(n+1);

	for (int i = 0; i <= n; i++)
	{
		long long kyesu, sangsu;
		cin >> kyesu >> sangsu;
		kyesus[n - sangsu] = kyesu;
	}

	long long res = 0;
	for (int i = 0; i <= n; i++)
	{
		res = (res * x + kyesus[i]) % MOD;
	}

	cout << res;

	return 0;
}