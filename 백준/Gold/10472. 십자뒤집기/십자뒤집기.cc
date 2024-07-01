#include <bits/stdc++.h>

using namespace std;

int p;
string str[3];
set<string> s;
vector<pair<int, int>> dir = { {0, 1}, { 0, -1}, {0, 0}, {1, 0}, {-1,0} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> p;

	while (p--)
	{
		bool solve = false;
		int cnt = -1;
		string board = "";

		for (int i = 0; i < 3; i++)
		{
			cin >> str[i];
			board += str[i];
		}
		
		s.clear();
		queue<string> q;
		s.insert(board);
		q.push(board);

		while (q.size())
		{
			cnt++;
			int qsize = q.size();

			while (qsize--)
			{
				string str = q.front();
				q.pop();

				if (str == ".........")
				{
					solve = true;
					break;
				}

				for (int i = 0; i < 9; i++)
				{
					// i번째 버튼의 가로-세로 좌표 구함
					int y = i / 3;
					int x = i % 3;

					string temp = str;

					for (int j = 0; j < 5; j++)
					{
						int ny = y + dir[j].first;
						int nx = x + dir[j].second;

						if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;
						if (temp[ny * 3 + nx] == '*') temp[ny * 3 + nx] = '.';
						else temp[ny * 3 + nx] = '*';
					}

					if (!s.count(temp))
					{
						s.insert(temp);
						q.push(temp);
					}
				}
			}
			if (solve) break;
		}

		cout << cnt << '\n';
	}

	return 0;
}