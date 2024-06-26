#include <bits/stdc++.h>

using namespace std;

int sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		if (x < 40) x = 40;
		sum += x;
	}

	cout << sum / 5;

	return 0;
}