#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 0;
	int end = 1;
	int sub = 0;
	int minsub = INT_MAX;

	while (start < n && end < n)
	{
		sub = arr[end] - arr[start];

		if (sub < m) // 차가 m보다 작을 경우 차를 늘려야 함 -> 더 큰 수에서 빼야함 -> end 증가
		{
			end++;
		}
		else if (sub == m) // 차가 m일 경우 바로 정답이므로 break
		{
			minsub = m;
			break;
		}
		else // 차가 m보다 클 경우 최소값을 저장하고 차를 좁히기 위해 start 증가
		{
			minsub = min(minsub, sub);
			start++;
		}
	}

	cout << minsub;

	return 0;
}