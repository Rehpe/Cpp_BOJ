#include <bits/stdc++.h>
using namespace std;

int M, N;
int primenum[1000001];
vector<int> primedata;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 에라토스테네스의 체
	fill(&primenum[0], &primenum[1000000], 1);
	primenum[0] = 0;
	primenum[1] = 0;

	for (int i = 2; i < sqrt(1000000) + 1; i++)
	{
		if (primenum[i])	// 데이터값이 1이라면
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				primenum[j] = 0;
			}
		}
	}

	cin >> M >> N;
	
	for (int i = M; i < N + 1; i++)
	{
		if (primenum[i] == 1)
			cout << i << '\n';
	}
}

