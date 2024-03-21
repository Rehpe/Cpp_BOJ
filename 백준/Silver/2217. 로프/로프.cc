#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> rope;
int maxsum;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		rope.push_back(x);
	}

	// 내림차순으로 정렬(하중이 큰 로프 순으로)
	sort(rope.begin(), rope.end(), greater<>());

	// i : 몇 개의 로프를 사용할 것인지
	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, rope[i - 1] * i);
	}

	cout << ans;

	return 0;
}