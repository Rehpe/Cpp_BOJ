#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
			break;

		vector<int> nums = {};
		nums.push_back(a);
		nums.push_back(b);
		nums.push_back(c);

		sort(nums.begin(), nums.end());

		if (nums[2] * nums[2] == nums[0] * nums[0] + nums[1] * nums[1])
			cout << "right" <<'\n';
		else
			cout << "wrong" << '\n';
	}
}