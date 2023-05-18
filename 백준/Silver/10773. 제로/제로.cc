#include <bits/stdc++.h>
using namespace std;

int K;
int n;
stack<int> nums;

int main()
{
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> n;
		if (n != 0)
			nums.push(n);
		else
			nums.pop();
	}

	int sum = 0;
	while (nums.size())
	{
		sum += nums.top();
		nums.pop();
	}

	cout << sum;
};