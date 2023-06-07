#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int cnt = 0;

	for (int i = 5; i <= N; i *= 5)
	{
		// i가 5의 배수일 때 몫만큼 cnt 증가
		cnt += N / i;
	}

	cout << cnt;
}

