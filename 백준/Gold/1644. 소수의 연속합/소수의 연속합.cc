#include <bits/stdc++.h>

using namespace std;

int n;
int primedata[4000001];
vector<int> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(primedata, primedata + n + 1, 1);

	//에라토스테네스의 체로 소수 판별
	
	// 0과 1은 소수가 아님
	primedata[0] = 0;
	primedata[1] = 0;

	// n의 제곱근까지 판별(그 이후로는 대칭이기 때문에)
	for (int i = 2; i <= sqrt(n) + 1; i++)
	{
		if (primedata[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				// i의 배수는 소수가 아니다
				primedata[j] = 0;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (primedata[i])
			prime.push_back(i);
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int cnt = 0;

	while (true)
	{
		if(sum >= n)
		{
			sum -= prime[start];
			start++;
		}
		else if (end == prime.size()) break;
		else
		{
			sum += prime[end];
			end++;
		}
		
		if (sum == n) cnt++;
	}

	cout << cnt;

	return 0;
}


