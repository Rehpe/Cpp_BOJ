#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int minLen = INT_MAX;

	while (start <= end)
	{
		if (sum >= s)
		{
			minLen = min(minLen, end - start);
			sum -= arr[start++];
		}
		else if (end == n) break; 
		else
			sum += arr[end++];
	}

	if (minLen == INT_MAX) cout << 0;
	else cout << minLen;

	return 0;
}