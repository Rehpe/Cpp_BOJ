#include <bits/stdc++.h>
using namespace std;

int N;
int num;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	// 산술 평균
	float sum = accumulate(vec.begin(), vec.end(), 0);
	cout << floor(sum / float(N) + 0.5) << '\n';

	// 중앙값
	int mid = N / 2;
	cout << vec[mid] << '\n';

	int maxcnt = 0;
	vector<int> maxcntnum;

	// 최빈값
	for (int i = 0; i < N; i++)
	{
		int cnt = upper_bound(vec.begin(), vec.end(), vec[i]) - lower_bound(vec.begin(), vec.end(), vec[i]);
		
		if (cnt > maxcnt)
		{
			maxcnt = cnt;
			maxcntnum.clear();
			maxcntnum.push_back(vec[i]);
		}
		else if (cnt == maxcnt)
		{
			maxcntnum.push_back(vec[i]);
		}
		else
			continue;
	}
	
	maxcntnum.erase(unique(maxcntnum.begin(), maxcntnum.end()), maxcntnum.end());

	if (maxcntnum.size() == 1)
		cout << maxcntnum[0] << '\n';
	else
		cout << maxcntnum[1] << '\n';

	// 범위
	cout << vec[N - 1] - vec[0];
}

