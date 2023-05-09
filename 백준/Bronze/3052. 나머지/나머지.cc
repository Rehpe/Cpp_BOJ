#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		nums.push_back(n);
	}

	for (int i = 0; i < 10; i++)
	{
		nums[i] = nums[i] % 42;
	}

	sort(nums.begin(), nums.end());

	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	cout << nums.size();
}

// unique : 중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환한다.
// 원래 배열의 앞에서부터 중복되지 않은 값들을 채워넣고, 나머지 요소들은 그냥 둔다.
// 따라서 반드시 sort한 벡터에 사용해야하며, unique로 정리한 배열 다음 이터를 반환하므로
// erase의 첫번째 인자로 unique값, 원본 배열의 end로 중복되지 않은 값만 깔끔히 남길 수 있다.
