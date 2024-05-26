#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 0;
	int end = n - 1;
	int sum = 0;
	int ans = INT_MAX;
	int first = 0;
	int second = 0;

	while (start < end)
	{
		int sum =arr[start] + arr[end];

		ans = min(ans, abs(sum));
		if (ans == abs(sum))
		{
			first = arr[start];
			second = arr[end];
		}

		if (sum == 0)
		{
			cout << arr[start] << " " << arr[end];
			return 0;
		}

		if (sum > 0)
		{
			end--;
		}
		else if (sum < 0)
		{
			start++;
		}
	}
	
	cout << first << " " << second;

	return 0;
}
