#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 0 번 인덱스 초기화
	vec.push_back(0);
	int psum[1001] = { 0, };

	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		vec.push_back(p);
	}

	sort(vec.begin()+1, vec.end());

	int sum = 0;
	for (int i = 1; i < N+1; i++)
	{
		psum[i] = psum[i - 1] + vec[i];
		sum += psum[i];
	}

	cout << sum;
}

