#include <bits/stdc++.h>
using namespace std;

long long K, N;
long long length;
vector<long long> lans;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> length;
		lans.push_back(length);
	}

	sort(lans.begin(), lans.end());
	
	long long low = 1;
	long long high = lans[K - 1];	// 갖고 있는 랜선의 최대 길이


	while (low <= high)
	{
		long long cnt = 0;
		long long mid = (low + high) / 2;

		for (int i = 0; i < K; i++)
		{
			cnt += lans[i] / mid;	// 가진 랜선 길이를 mid cm로 나눈 몫만 더한다
		}
		// 자른 랜선의 개수가 N개보다 작다면, 더 작게 잘라야함
		if (cnt < N)				
		{
			high = mid - 1;
		}
		// 자른 랜선의 개수가 N개보다 같거나 크다면, 
		else                      
		{
			if (mid > ans)	// 이전에 기록된 결과보다 mid(자를 랜선 길이)가 클 경우에만 갱신
				ans = mid;
			low = mid + 1;
		}
	}

	cout << ans;
}

