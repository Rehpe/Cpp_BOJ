#include <bits/stdc++.h>

using namespace std;

int zerocnt[41];
int onecnt[41];
int T, N;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		zerocnt[0] = 1;
		onecnt[1] = 1;

		for (int i = 2; i < N+1; i++)
		{
			zerocnt[i] = zerocnt[i - 1] + zerocnt[i - 2];
			onecnt[i] = onecnt[i - 1] + onecnt[i - 2];
		}

		cout << zerocnt[N] << ' ' << onecnt[N] << '\n';
	}
	return 0;
}