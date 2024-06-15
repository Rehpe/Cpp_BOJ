#include <bits/stdc++.h>

using namespace std;

int n, m;
char maps1[51][51];
char maps2[51][51];

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps1[i][j] != maps2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}


void flip(int y, int x)
{
	for (int i = y; i <= y + 2; i++)
	{
		for (int j = x; j <= x + 2; j++)
		{
			if (maps1[i][j] == '1')
				maps1[i][j] = '0';
			else
				maps1[i][j] = '1';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			maps1[i][j] = s[j] ;
		}
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			maps2[i][j] = s[j];
		}
	}

	if (n < 3 || m < 3)
	{
		if (!check()) cout << -1;
		else cout << 0;
		return 0;
	}

	int cnt = 0;	

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (maps1[i][j] != maps2[i][j])
			{
				flip(i, j);
				cnt++;
			}
		}
	}

	if (!check()) cout << -1;
	else cout << cnt;

	return 0;
}