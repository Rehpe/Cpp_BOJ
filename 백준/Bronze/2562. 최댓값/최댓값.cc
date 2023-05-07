#include <bits/stdc++.h>
using namespace std;

int i;
vector<int> nums;
int maxNum;

int main()
{
	maxNum = 0;
	for (int j = 0; j < 9; j++)
	{
		cin >> i;
		nums.push_back(i);
		maxNum = max(i, maxNum);
	}

	cout << maxNum <<'\n';
	cout << find(nums.begin(), nums.end(), maxNum) - nums.begin() + 1;
}