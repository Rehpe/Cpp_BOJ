#include <bits/stdc++.h>

using namespace std;

int arr_size;
long long A[1000001];
vector<int> L;		// L[i] =  A 배열에서 i 길이의 수열을 가지는 가장 작은 원소


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
		}
		else
		{
			int idx = lower_bound(L.begin(), L.end(), A[i]) - L.begin();
			L[idx] = A[i];
		}
	}
	
	cout << L.size();

	return 0;
}