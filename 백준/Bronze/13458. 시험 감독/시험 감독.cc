#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000001];
int b, c;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++)
	{
		int x = a[i] - b;
		ans++;
		
		if (x > 0)
		{
			if (x % c == 0) ans += x / c;
			else ans += (x / c) + 1;
		}
	}

	cout << ans;

	return 0;
}