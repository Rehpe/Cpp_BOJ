#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100002];
int abssum = INT_MAX;
int a, b;

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

	while (start < end)
	{
		int sum = arr[start] + arr[end];

		// 구한 합계가 기존 합계 절대값보다 작은 경우 갱신
		if (abs(sum) < abs(abssum))
		{
			abssum = sum;
			a = arr[start];
			b = arr[end];
		}

		// 0일 경우 무조건 정답이므로 break
		if (sum == 0) break;

		// 절대값이 양수일 경우 -> 음수 절대값을 찾기 위해 end를 내려 작은 합계를 구함
		else if (sum > 0)
			end--;
		// 절대값이 음수인 경우-> 양수 절대값을 찾기 위해 start를 올려 큰 합계를 구함
		else
			start++;
	}

	cout << a << ' ' << b;

	return 0;
}