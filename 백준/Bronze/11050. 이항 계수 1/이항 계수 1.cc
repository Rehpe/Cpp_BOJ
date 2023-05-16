//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;

int fact(int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}

int main()
{
	cin >> N >> K;

	cout << fact(N) / (fact(K) * fact(N - K));
};