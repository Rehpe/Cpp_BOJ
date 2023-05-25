#include <bits/stdc++.h>
using namespace std;

int x, y, z;
int prize;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> z;

	if (x == y && y == z && z == x)
	{
		prize = 10000 + (1000 * x);
	}
	else if (x == y || y == z || z == x)
	{
		if (x == y)
			prize = 1000 + 100 * x;
		else if (y == z)
			prize = 1000 + 100 * y;
		else
			prize = 1000 + 100 * z;
	}
	else
	{
		vector<int> vec;
		vec.push_back(x);
		vec.push_back(y);
		vec.push_back(z);

		int maxP = *max_element(vec.begin(), vec.end());
		prize = 100 * maxP;
	}

	cout << prize;

}