#include <bits/stdc++.h>

using namespace std;

long long N, num, cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		int n = 1;

		while ((int)pow(5, n) <= num)
		{
			cnt += num / (int)pow(5, n);
			n++;
		}

		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}