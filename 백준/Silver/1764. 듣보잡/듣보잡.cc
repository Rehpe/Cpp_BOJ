#include <bits/stdc++.h>
using namespace std;

int N, M;
string name;
vector<string> A;
vector<string> B;
vector<string> AB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		A.push_back(name);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		B.push_back(name);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < N; i++)
	{
		name = A[i];
		if (binary_search(B.begin(), B.end(), A[i]))
			AB.push_back(A[i]);
	}

	
	cout << AB.size() << '\n';
	for (string s : AB)
	{
		cout << s << '\n';
	}
}

