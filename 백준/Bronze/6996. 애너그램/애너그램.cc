#include <bits/stdc++.h>

using namespace std;

int t;
int flength;
int slength;
int first[26];
int second[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		string f, s;
		cin >> f >> s;

		bool trigger = false;
		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));

		for (int i = 0; i < f.size(); i++)
		{
			first[f[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			second[s[i] - 'a']++;
		}

		if (f.size() == s.size())
		{
			for (int i = 0; i < 26; i++)
			{
				if (first[i] != second[i])
				{
					cout << f << " & " << s << " are NOT anagrams." << '\n';
					trigger = true;
					break;
				}
			}
			if(!trigger)
				cout << f << " & " << s << " are anagrams." <<'\n';
		}
		else
			cout << f << " & " << s << " are NOT anagrams." << '\n';
	}


	return 0;
}