#include <bits/stdc++.h>
using namespace std;

int N;
int x;
vector<int> nums;
int maxNum;
int minNum;

int main()
{
	minNum = INT_MAX;
	maxNum = INT_MIN;
	cin >> N;
	for (int i  = 0; i < N; i++)
	{
		cin >> x;
		nums.push_back(x);
		maxNum = max(x, maxNum);
		minNum = min(x, minNum);
	}

	cout << minNum << " " << maxNum;
}