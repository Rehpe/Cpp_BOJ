#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> house;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		house.push_back(x);
	}

	sort(house.begin(), house.end());

	// 가능한 공유기 사이의 거리를 start, end로 둔다
	int start = 1;
	int end = house[n - 1] - house[0];	// 가능한 최대 거리는 끝집-첫집

	while (start <= end)
	{
		// 이분 탐색으로 두 집 사이의 최소 거리를 설정한다
		int mid = (start + end) / 2;

		int cnt = 1;
		int prev_house = house[0];

		for (int i = 1; i < n; i++)
		{
			// 두 집 사이 간의 거리가 설정한 거리보다 같거나 큰 경우에만 공유기 설치
			if (house[i] - prev_house >= mid)
			{
				cnt++;
				prev_house = house[i];
			}
		}

		// 설정한 최소 거리로 설치한 공유기 수가 주어진 공유기 수보다 많다면
		if (cnt >= c)
		{
			// 우선 기록해두고, 거리를 최대화하기 위해 최소 거리를 더 늘려본다
			ans = max(ans, mid);
			start = mid + 1;
		}
		// 설정한 최소 거리로 설치한 공유기 수가 주어진 공유기 수보다 부족하다면
		else if (cnt < c)
		{
			// 공유기 수를 늘려야하므로 최소 거리를 줄인다
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}