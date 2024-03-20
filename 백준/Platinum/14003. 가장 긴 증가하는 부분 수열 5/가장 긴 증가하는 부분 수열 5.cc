#include <bits/stdc++.h>

using namespace std;

int arr_size;
long long A[1000001];
vector<long long> L;
vector<long long> element;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> arr_size;

	for (int i = 1; i <= arr_size; i++)
	{
		cin >> A[i];

		if (L.empty() || L.back() < A[i])
		{
			L.push_back(A[i]);
			element.push_back(L.size());
		}
		else
		{
			int idx = lower_bound(L.begin(), L.end(), A[i]) - L.begin();
			L[idx] = A[i];
			element.push_back(idx + 1);
		}
	}
	int LIScnt = L.size();

	cout << LIScnt << '\n';

	vector<int> numlist;
	for (int i = arr_size -1; i >= 0; i--)
	{
		if (LIScnt == 0) break;

		if (element[i] == LIScnt)
		{
			numlist.push_back(A[i+1]);
			LIScnt--;
		}
	}

	reverse(numlist.begin(), numlist.end());
	for (auto a : numlist)
	{
		cout << a << ' ';
	}

	return 0;
}