#include <bits/stdc++.h>
using namespace std;

int parktime[101];
int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++)
	{
		int come, leave;
		cin >> come >> leave;

		for (int j = come; j < leave; j++)
		{
			parktime[j]++;
		}
	}

	int ans = 0;

	for (int i : parktime)
	{
		if (i == 1)
			ans += i * A;
		else if (i == 2)
			ans += i * B;
		else if (i == 3)
			ans += i * C;
	}

	cout << ans;
}