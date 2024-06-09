#include <bits/stdc++.h>

using namespace std;

string s;
string ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	if (s == "SONGDO")
		ret = "HIGHSCHOOL";
	if (s == "CODE")
		ret = "MASTER";
	if (s == "2023")
		ret = "0611";
	if (s == "ALGORITHM")
		ret = "CONTEST";

	cout << ret;
	
	return 0;
}