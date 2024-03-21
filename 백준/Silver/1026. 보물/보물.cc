#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> B;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		int y;
		cin >> y;
		B.push_back(y);
	}

	// A의 가장 작은수 * B의 가장 큰 수여야 가장 작은 값이 나올 것이다.
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[i];
	}

	cout << ans;
		
	return 0;
}