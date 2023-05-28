#include <bits/stdc++.h>
using namespace std;

int N;
int n;
bool b;
int num;
vector<string> ret;
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	b = false;
	num = 1;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		// 스택이 비었거나, 스택의 top이 입력된 수(n)보다 작을 경우
		if (st.empty() || st.top() < n)
		{
			// 1부터 n까지의 수를 스택에 push
			for (int j = num; j < n + 1; j++)
			{
				st.push(j);
				ret.push_back("+");
				num++;
			}

			if (st.top() == n)
			{
				st.pop();
				ret.push_back("-");
			}
		}
		
		// 스택의 top이 입력된 수와 같을 경우
		else if (st.top() == n)
		{
			st.pop();
			ret.push_back("-");
		}

		else
		{
			b = true;
		}
	}

	if (b)
		cout << "NO";
	else
	{
		for (string s : ret)
		{
			cout << s << '\n';
		}
	}
}
