#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int cnt = 0;

	while (start <= end)
	{
		if (end == n + 1) break;

		if (sum == m)
		{
			cnt++;
			sum -= arr[start++];
		}
		else if (sum > m)
			sum -= arr[start++];
		else
			sum += arr[end++];
	}

	cout << cnt;

	return 0;
}