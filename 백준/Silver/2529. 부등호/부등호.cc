#include <bits/stdc++.h>

using namespace std;

int n;
char opers[10];
vector<string> ans;
int visited[10];

bool stringCompare(const string& a, const string& b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

bool check(char a, char b, char oper)
{
	if (a > b && oper == '>') return true;
	if (a < b && oper == '<') return true;

	return false;
}

void go(int idx, string s)
{
	if (idx == n+1)
	{
		ans.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{	
		char num = i +'0';
		if (visited[i]) continue;	// 한 번 사용한 숫자는 사용할 수 없음
		if (idx == 0 || check(s[idx - 1], num, opers[idx-1]))
		{
			visited[i] = 1;
			go(idx + 1, s + num);
			visited[i] = 0;
		}
	}
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> opers[i];
	}

	go(0, "");

	sort(ans.begin(), ans.end(), stringCompare);

	cout << ans[ans.size()-1] << '\n' << ans[0];

	return 0;
}