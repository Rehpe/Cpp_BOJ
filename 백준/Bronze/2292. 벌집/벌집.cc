#include <bits/stdc++.h>
using namespace std;

int N;

int go(int i)
{
	int j = 1;
	int rangeEnd = j;

	while (i > rangeEnd)
	{
		rangeEnd += j * 6;
		j++;
	}

	return j;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << go(N);
}