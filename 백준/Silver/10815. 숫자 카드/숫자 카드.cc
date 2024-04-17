#include <bits/stdc++.h>

using namespace std;

int n, m;
int s[500002];
int t[500002];
int res;
//vector<int> s;
//vector<int> t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t[i];
	}

	sort(s, s + n);

	for (int i = 0; i < m; i++)
	{
		res = 0;

		int num = t[i];

		int start = 0;
		int end = n - 1;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (num == s[mid])
			{
				res = 1;
				break;
			}
			else if (num < s[mid])
			{
				end = mid - 1;
			}
			else if(num > s[mid])
			{
				start = mid + 1;
			}
		}

		cout << res << ' ';
	}

	return 0;

}