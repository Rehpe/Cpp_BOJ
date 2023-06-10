#include <bits/stdc++.h>
using namespace std;
int num;
string s;
vector<string> names;
int a[26];
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> s;
		names.push_back(s);
	}

	for (string s : names)
	{
		a[int(s[0]) - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
			result.push_back(i);
	}

	if (result.size())
	{
		for (int c : result)
			cout << char(c + 'a');
	}

	else
		cout << "PREDAJA";

	return 0;
}
