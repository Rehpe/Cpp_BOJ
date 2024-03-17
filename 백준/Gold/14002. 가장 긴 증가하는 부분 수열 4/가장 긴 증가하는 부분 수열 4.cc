#include <bits/stdc++.h>

using namespace std;

int arr_size;
int A[1001];
int dp[1001];
int ans;
vector<int> LIS;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> arr_size;

	for (int i = 1; i <= arr_size; i++)
	{
		cin >> A[i];

		int here = 0;

		for (int j = 1; j < i; j++)
		{
			if (A[i] > A[j])
			{
				here = max(here, dp[j]);
			}
		}
		dp[i] = here + 1;
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	for (int i = arr_size; i >= 1; i--)
	{
		if (dp[i] == ans)
		{
			LIS.push_back(A[i]);
			ans--;
		}
	}

	reverse(LIS.begin(), LIS.end());
	for (auto a : LIS)
	{
		cout << a << " ";
	}

	return 0;
}