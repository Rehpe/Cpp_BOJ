#include <bits/stdc++.h>

using namespace std;

int n;
int money[10004];
int cnt;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
	}

	cin >> cnt;

	sort(money, money + n);

	int start = 1;
	int end = money[n-1];

	while (start <= end)
	{
		// 상한액
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			// 예산안이 같거나 작은 경우 
			if (money[i] <= mid)
			{
				sum += money[i];
			}
			else
			{
				sum += mid;
			}
		}

		// 배정된 예산이 더 크면 상한액을 줄인다
		if (sum > cnt)
		{
			end = mid - 1;
		}
		// 배정된 예산이 작으면 기록하고 상한액을 늘린다
		else
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
	}

	cout << ans;

	return 0;
}