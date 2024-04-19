#include <bits/stdc++.h>

using namespace std;

int m, n;
int snack[1000004];
int cnt;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> snack[i];
	}

	sort(snack, snack + n);

	// 가장 짧은 / 긴 과자의 길이
	int start = 1;
	int end = snack[n-1];

	while (start <= end)
	{
		int mid = (start + end) / 2;
		
		cnt = 0;

		for (int i = n-1; i >= 0; i--)
		{
			cnt += snack[i] / mid;

			// 조카의 수보다 가능한 과자 수가 많거나 같아지면 break;
			if (cnt >= m)
			{
				ans = max(ans, mid);
				break;
			}
		}

		// 조카 수보다 과자 수가 부족하면
		if (cnt < m)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << ans;

	return 0;
}