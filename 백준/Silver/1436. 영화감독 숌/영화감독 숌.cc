#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int i = 666;
	vec.push_back(0);
	while (!(vec.size() == 10001))
	{
		string num = to_string(i);
		auto it = num.find("666");
		if (it != string::npos)
			vec.push_back(i);
		i++;
	}

	cout << vec[N];
}