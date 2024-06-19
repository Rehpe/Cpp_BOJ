#include <bits/stdc++.h>

using namespace std;

int l;
string orders;
int maps[1001][1001];
set<pair<int, int>> s;
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> orders;

	pair<int, int> here = {0, 0};
	s.insert(here);

	for (int i = 0; i < l; i++)
	{
		char order = orders[i];
		int y = here.first;
		int x = here.second;

		if (order == 'E')
			here = { y, x + 1 };
		else if(order =='W')
			here = { y, x - 1 };
		else if(order =='S')
			here = { y-1, x };
		else if(order =='N')
			here = { y+1, x };

		s.insert(here);
	}

	cout << s.size();

	return 0;
}