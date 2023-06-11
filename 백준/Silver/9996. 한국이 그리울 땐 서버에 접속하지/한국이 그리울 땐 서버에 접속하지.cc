#include <bits/stdc++.h>
using namespace std;
int num;
string file, pt, first, last;
vector<string> files;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> num;
	cin >> pt;

	for (int i = 0; i < num; i++)
	{
		cin >> file;
		files.push_back(file);
	}

	int pos = pt.find('*');

	first = pt.substr(0, pos);
	last = pt.substr(pos + 1);

	for (string file : files)
	{
		if (first.size() + last.size() > file.size())
			cout << "NE" << '\n';
		else
		{
			if (file.substr(0, first.size()) == first &&
				file.substr(file.size() - last.size()) == last)
				cout << "DA" << '\n';
			else
				cout << "NE" << '\n';
		}
	}

	return 0;
}
