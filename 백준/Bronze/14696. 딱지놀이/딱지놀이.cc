#include <bits/stdc++.h>

using namespace std;

int r;
int acnt, bcnt;
int a[6];
int b[6];

char compare()
{
	if (a[4] == b[4])
	{
		if (a[3] == b[3])
		{
			if (a[2] == b[2])
			{
				if (a[1] == b[1])
				{
					return 'D';
				}
				else
				{
					if (a[1] > b[1]) return 'A';
					else return 'B';
				}
			}
			else
			{
				if (a[2] > b[2]) return 'A';
				else return 'B';
			}
		}
		else
		{
			if (a[3] > b[3]) return 'A';
			else return 'B';
		}
	}
	else
	{
		if (a[4] > b[4]) return 'A';
		else return 'B';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r;

	while (r--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		cin >> acnt;
		for (int i = 0; i < acnt; i++)
		{
			int poly;
			cin >> poly;
			a[poly]++;
		}
		cin >> bcnt;
		for (int i = 0; i < bcnt; i++)
		{
			int poly;
			cin >> poly;
			b[poly]++;
		}

		cout << compare() <<'\n';
	}
	return 0;
}