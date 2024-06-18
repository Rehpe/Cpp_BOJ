#include <bits/stdc++.h>

using namespace std;

int n, k;
string num;
deque<int> d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	cin >> num;

	for (int i = 0; i < n; i++)
	{
		// 제거 횟수가 남아있고, 덱의 가장 최근에 넣은 숫자가 지금 넣을 숫자보다 작다면
		while (!d.empty() && k && d.back() < num[i] -'0')
		{
			// 작은 앞자리 수를 빼버림
			d.pop_back();
			k--;
		}
		d.push_back(num[i]-'0');
	}

	if (k)
	{
		while (k--)
			d.pop_back();
	}

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i];
	}

	return 0;
}