#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<string> mbti;
int threedist;

int calcdist(int a, int b)
{
    string MbtiA = mbti[a];
    string MbtiB = mbti[b];

    int dist = 0;

    if (MbtiA[0] != MbtiB[0])    dist++;
    if (MbtiA[1] != MbtiB[1])    dist++;
    if (MbtiA[2] != MbtiB[2])    dist++;
    if (MbtiA[3] != MbtiB[3])    dist++;

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        mbti.clear();
        threedist = 100;

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            mbti.push_back(s);
        }

        if (N >= 33)
        {
            cout << 0 << '\n';
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    for (int k = j + 1; k < N; k++)
                    {
                        int temp;
                        temp = calcdist(i, j) + calcdist(j, k) + calcdist(k, i);
                        threedist = min(temp, threedist);
                    }
                }
            }

            cout << threedist << '\n';
        }
    }

    return 0;
}