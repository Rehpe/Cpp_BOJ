#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> que;
vector<int> ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        que.push(i + 1);
    }

    while (!(que.empty()))
    {
        for (int i = 0; i < K - 1; i++)
        {
            int n = que.front();
            que.pop();
            que.push(n);
        }

        int num = que.front();
        ret.push_back(num);
        que.pop();
    }

    cout << "<";
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i];

        if (i == ret.size() - 1)
            break;
        else
            cout << ", ";
    }
    cout << ">";
	
}