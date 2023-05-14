#include <bits/stdc++.h>
using namespace std;

int N , M;
int nums;
vector<int> cardnum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> nums;
		cardnum.push_back(nums);
	}

	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = cardnum[i] + cardnum[j] + cardnum[k];
				if (sum > M)
					continue;
				else
					ret = max(sum, ret);
			}
		}
	}

	cout << ret;

}