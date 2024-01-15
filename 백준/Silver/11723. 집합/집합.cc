#include <bits/stdc++.h>

using namespace std;

int M;
int x;
string s;
vector<int> arr;
bool exist;

bool IsExist(int x)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		exist = false;

		cin >> s;

		if (s == "all")
		{
			arr.clear();
			for (int i = 0; i < 20; i++)
			{
				arr.push_back(i + 1);
			}
		}
		else if (s == "empty")
		{
			arr.clear();
		}

		else if(s == "add")	
		{
			cin >> x;
			if (!IsExist(x))
				arr.push_back(x);
		}
		else if (s == "remove") 
		{
			cin >> x;
			if (IsExist(x))
				arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
		}
		else if (s == "check")
		{
			cin >> x;
			if (IsExist(x))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "toggle")
		{
			cin >> x;
			if (IsExist(x))
				arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
			else
				arr.push_back(x);
		}

	}
	
	return 0;
};