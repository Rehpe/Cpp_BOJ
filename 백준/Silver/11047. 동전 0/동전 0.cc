#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> coin;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		coin.push_back(n);
	}

	sort(coin.begin(), coin.end(), greater<int>());

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		if (coin[i] > K)
			continue;
		else if (coin[i] == K)
		{
			cnt++;
			break;
		}
		else
		{
			cnt += K / coin[i];
			K = K % coin[i];
		}
	}

	cout << cnt;
}

