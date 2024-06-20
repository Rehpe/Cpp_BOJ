#include <bits/stdc++.h>

using namespace std;

int n, m;
int randomidx;
map<string, int> maps;
string history[101];
string hubo[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> history[i];
		maps.insert({ history[i], i });
	
		if (history[i] == "?")
			randomidx = i;	
	}

	char first = '0';
	char last = '0';

	if (randomidx - 1 >= 0)
	{
		first = history[randomidx - 1][history[randomidx - 1].size() - 1];
	}
	if (randomidx + 1 < n)
	{
		last = history[randomidx + 1][0];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> hubo[i];

		if (first == '0' && last == '0')
		{
			cout << hubo[i];
		}
		else if (first == '0')
		{
			if(hubo[i][hubo[i].size() - 1] == last)
			{
				auto a = maps.find(hubo[i]);
				if (a == maps.end())
				{
					cout << hubo[i];
					exit(0);
				}
			}
		}
		else if (last == '0')
		{
			if (hubo[i][0] == first)
			{
				auto a = maps.find(hubo[i]);
				if (a == maps.end())
				{
					cout << hubo[i];
					exit(0);
				}
			}
		}
		else
		{
			if (hubo[i][0] == first && hubo[i][hubo[i].size() - 1] == last)
			{
				auto a = maps.find(hubo[i]);
				if (a == maps.end())
				{
					cout << hubo[i];
					exit(0);
				}
			}
		}
	}

	return 0;
}