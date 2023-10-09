#include <bits/stdc++.h>
using namespace std;

int N;
string s, num;
vector<string> vec;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

void go()
{
	while (true)
	{
		if (num.size() && num.front() == '0')
			num.erase(num.begin());
		else
			break;
	}

	if (num.size() == 0) num = "0";

	vec.push_back(num);
	num = "";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		num = "";

		for (int j = 0; j < s.size(); j++)
		{
			if ('a' <= s[j] && s[j] <= 'z')
			{	
				if(num.empty())
					continue;
				else
				{
					go();
				}
			}
			else
			{
				num += s[j];
			}
		}
		if(!num.empty())
			go();
	}

	sort(vec.begin(), vec.end(), cmp);

	for (string a : vec)
	{
		cout << a << '\n';
	}
}