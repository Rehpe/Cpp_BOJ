#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2002];
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		int start = 0;
		int end = N-1;

		while (start < end)
		{
			// 두 수의 합으로 나타낼 때, 자기 자신(i)은 포함시키면 안된다.
			if (i == start)
			{
				start++;
				continue;
			}
			if (i == end)
			{
				end--;
				continue;
			}

			int sum = arr[start] + arr[end];
			
			if (arr[i] == sum)
			{
				cnt++;
				break;
			}
			else if (arr[i] < sum)
			{
				end--;
				continue;
			}
			else
			{
				start++;
				continue;
			}
		}
	}

	cout << cnt;

	return 0;
}