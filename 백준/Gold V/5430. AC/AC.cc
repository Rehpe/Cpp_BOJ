#include <bits/stdc++.h>
using namespace std;


int T;
string oper;
int vsize;
string arrays;
string num;
deque<int> d;
bool isReverse;
bool error;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while(T)
	{
		cin >> oper;
		cin >> vsize;
		cin >> arrays;

		for (int i = 0; i < arrays.size(); i++)
		{
			char c = arrays[i];

			// 숫자라면 num에 저장
			if ('0' <= c && c <= '9')
			{
				num += c;
			}
			// 문자라면 num을 deque에 넣고 num 초기화
			else
			{
				if (num != "")
				{
					d.push_back(stoi(num));
					num = "";
				}
			}
		}

		// oper을 하나씩 읽으며 덱을 처리한다
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper[i] == 'R')
			{
				if (isReverse)
					isReverse = false;
				else
					isReverse = true;
			}
			else
			{
				if (d.size() == 0)
				{
					error = true;
					break;
				}

				// Reverse 상태일 경우, pop_back
				if (isReverse)
					d.pop_back();
				// Reverse 상태가 아니라면 pop_front
				else
					d.pop_front();
			}
		}


		if (error)
			cout << "error" << '\n';
		else
		{
			if (isReverse)
				reverse(d.begin(), d.end());

			cout << "[";

			if (d.size() == 0)
				cout << "]" <<'\n';
			else
			{
				for (int k = 0; k < d.size(); k++)
				{
					if (k == d.size() - 1)
						cout << d[k] << "]" << '\n';
					else
						cout << d[k] << ",";
				}
			}
		}

		// 초기화
		d.clear();
		isReverse = false;
		error = false;
		T--;
	}
		
		return 0;
}