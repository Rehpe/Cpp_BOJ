#include <bits/stdc++.h>

using namespace std;

int n, m;
int rule[101];
int yeon[101];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int length, speed;
		cin >> length >> speed;
		
		for (int i = start; i < start + length; i++)
			rule[i] = speed;

		start += length;
	}

	start = 0;
	for (int i = 0; i < m; i++)
	{
		int length, speed;
		cin >> length >> speed;

		for (int i = start; i < start + length; i++)
			yeon[i] = speed;

		start += length;
	}

	int maxsub = INT_MIN;
	for (int i = 0; i < 100; i++)
	{
		maxsub = max(maxsub, yeon[i] - rule[i]);
	}
	
	if (maxsub < 0) cout << 0;
	else cout << maxsub;

	return 0;
}