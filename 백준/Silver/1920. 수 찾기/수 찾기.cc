#include <bits/stdc++.h>
using namespace std;

int N, M;
int num;
vector<int> arr;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (upper_bound(arr.begin(), arr.end(), num) - lower_bound(arr.begin(), arr.end(), num) == 0)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
	
}