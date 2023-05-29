#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
char c;
bool input;		// 전체 입력 여부
bool line;		// 문장 입력 여부

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input = true;

	while (input)
	{
		getline(cin, s);

		if (s[0] == '.')	// 온점 하나만 들어올 경우 전체 입력 종료
		{
			input = false;
			break;
		}

		if (input == false)
			break;

		for (char c : s)	// 단어가 들어올 경우
		{
			if (c == '[' || c == ']' || c == '(' || c == ')')	// 괄호일 경우에만 스택에 push
			{
				// 닫는 괄호일 경우에만 st.top과 비교 후 pop 또는 push
				if (c == ']')
				{
					if (!st.empty() && st.top() == '[')
						st.pop();
					else
						st.push(c);
				}
				else if (c == ')')
				{
					if (!st.empty() && st.top() == '(')
						st.pop();
					else
						st.push(c);
				}
				// 여는 괄호일 경우에는 무조건 push
				else
					st.push(c);
			}
			//else if (c == '.')	// 단어 중 온점을 만났다면 문장 입력 종료
				//line = false;
		}


		if (st.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
		// 스택 및 문장입력 bool변수 초기화
		st = {};
		line = true;
	}
}

