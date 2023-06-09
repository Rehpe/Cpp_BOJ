#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end());

	// 9C7 = 9C2
	// 100 + 두명의 키 = 전체 난쟁이 키의 합이므로
	// 두명의 키 = 전체 난쟁이 키의 합 - 100 일 때를 찾는다

	int sum = accumulate(vec.begin(), vec.end(), 0);
	pair<int, int> ret;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (vec[i] + vec[j] == sum - 100)
			{
				ret = { vec[i], vec[j] };
				break;
			}
		}
	}

	for (int i : vec)
	{
		// 이상한 두 난쟁이일 경우 continue
		if (i == ret.first || i == ret.second)
		{
			continue;
		}
		else
			cout << i << '\n';
	}
}