#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> q;
vector<int> asc;
vector<int> desc;

int main()
{
	for (int i = 0; i < 8; i++)
	{
		asc.push_back(i + 1);
	}

	for (int i = 8; i > 0; i--)
	{
		desc.push_back(i);
	}

	for (int i = 0; i < 8; i++)
	{
		cin >> n;
		q.push_back(n);
	}

	if (q == asc)
		cout << "ascending";
	else if (q == desc)
		cout << "descending";
	else
		cout << "mixed";
}