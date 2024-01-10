#include <bits/stdc++.h>

using namespace std;

int T;
int num;
int ret;

void go(int n)
{
	// 목표 숫자보다 크다면 return
	if (n > num) return;
	// 목표 숫자라면
	else if (n == num) ret++;

	// 목표 숫자보다 작다면
	for (int next : { n + 1, n + 2, n + 3})
	{
		go(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> num;

		ret = 0;
		go(1);
		go(2);
		go(3);
		cout << ret << '\n';
	}
};