#include <bits/stdc++.h>

using namespace std;

int n;
int arr[12];
int maxret = INT_MIN;
int minret = INT_MAX;
int ret;
int operators[4];	// + / - / x / %


void go(int opercnt, int ret)
{
	if (opercnt == n - 1)
	{
		maxret = max(maxret, ret);
		minret = min(minret, ret);
		return;
	}

	// 연산자의 종류는 4개
	for (int i = 0; i < 4; i++)
	{
		// 현재 남아있는 연산자만 사용 가능함
		if (operators[i] <= 0)	continue;
		
		operators[i]--;

		int temp = 0;

		if (i == 0) temp = ret + arr[opercnt + 1];
		else if (i == 1) temp = ret - arr[opercnt + 1];
		else if (i == 2) temp = ret * arr[opercnt + 1];
		else if (i == 3) temp = ret / arr[opercnt + 1];

		go(opercnt + 1, temp);

		operators[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	ret = arr[0];

	go(0, ret);

	cout << maxret << '\n' << minret;
	
	return 0;
}