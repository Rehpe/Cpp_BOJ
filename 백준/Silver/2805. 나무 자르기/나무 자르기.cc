#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long height;
long long ans;
vector<int> tree;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		tree.push_back(height);
	}

	sort(tree.begin(), tree.end());

	long long low = 0;			
	long long high = tree[N-1];	// 가장 큰 나무의 길이

	while (low <= high)
	{
		long long mid = (low + high) / 2;	// 절단기 높이
		long long cutted = 0;				// 잘린 나무의 합

		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid)				// 절단기 높이보다 큰 나무만 자를 수 있다
				cutted += tree[i] - mid;	// 잘린 만큼을 더함
		}
		// 잘린 나무의 합이 주어진 M이면, mid가 최소 절단기 높이
		if (cutted == M)					
		{
			ans = mid;
			break;
		}
		// 잘린 나무의 합이 M보다 작다면, 절단기를 내려서 나무를 더 많이 잘라야함
		else if (cutted < M)
		{
			high = mid - 1;
		}
		// 잘린 나무의 합이 M보다 크다면,
		else
		{
			// 우리는 절단기의 최대높이를 찾고 있으므로, 기존 기록된 ans보다 클 때에만 저장
			if (mid > ans)
				ans = mid;
			low = mid + 1;
		}
	}

	cout << ans;
	
}

