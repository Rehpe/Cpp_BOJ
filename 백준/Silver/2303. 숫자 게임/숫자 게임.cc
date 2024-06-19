#include <bits/stdc++.h>

using namespace std;

int n;
int card[1001][5];

int pick(int personidx)
{
	int maxsum = INT_MIN;

	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				int sum = card[personidx][i] + card[personidx][j] + card[personidx][k];
				sum = sum % 10;
				maxsum = max(maxsum, sum);
			}
		}
	}
	return maxsum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> card[i][j];
		}
	}

	int maxsum = INT_MIN;
	int maxId = -1;
	for (int i = 1; i < n+1; i++)
	{
		if (maxsum <= pick(i))
		{
			maxsum = pick(i);
			maxId = i;
		}
	}
	
	cout << maxId;

	return 0;
}