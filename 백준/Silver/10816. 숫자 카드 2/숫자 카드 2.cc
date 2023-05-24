#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> ans;
int num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (ans.find(num) != ans.end())
			ans[num]++;
		else
			ans.insert({num, 1});
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << ans[num] << " ";
	}

}