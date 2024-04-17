#include <bits/stdc++.h>

using namespace std;

int acnt, bcnt;
int A[500004];
int B[500004];
vector<int> ans;
bool flag;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> acnt >> bcnt;

	for (int i = 0; i < acnt; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < bcnt; i++)
	{
		cin >> B[i];
	}

	sort(B, B + bcnt);
	

	for (int i = 0; i < acnt; i++)
	{
		int num = A[i];

		int start = 0;
		int end = bcnt - 1;

		flag = false;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (num == B[mid])
			{
				flag = true;
				break;
			}
			else if (num < B[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		if (flag == false)
		{
			ans.push_back(A[i]);
		}
	}

	int anscnt = ans.size();

	cout << anscnt << '\n';

	if (anscnt != 0)
	{
		sort(ans.begin(), ans.end());
		for (int a : ans)
		{
			cout << a << ' ';
		}
	}

	return 0;
}