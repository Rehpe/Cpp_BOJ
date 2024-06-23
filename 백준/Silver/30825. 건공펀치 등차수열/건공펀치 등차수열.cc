#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long A[200001];
long long B[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (long long i = 0; i < n; i++)
	{
		cin >> A[i];
		B[i] = A[i] - (k * i);
	}

	long long maxnum = *max_element(B, B + n);
	long long punch = 0;

	for (long long i = 0; i < n; i++)
	{
		punch += maxnum - B[i];
	}

	cout << punch;

	return 0;
}