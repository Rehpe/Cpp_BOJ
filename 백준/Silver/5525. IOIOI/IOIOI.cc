#include <bits/stdc++.h>

using namespace std;

int N, M;
string S;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> S;

	for (int i = 0; i < M; i++)
	{
		// 'O'일 경우 아무것도 일어나지 않고 인덱스 증가
		if (S[i] == 'O')	continue;
		else
		{
			int cnt = 0;		// 몇 개짜리 IOI인지 세기 위한 변수

			// I일 경우 뒤에 OI가 오는지 체크
			while (S[i + 1] == 'O' && S[i + 2] == 'I')
			{
				cnt++;

				// N만큼 반복되었다면 ans를 ++ 
				if (cnt == N)
				{
					ans++;

					// 아래 코드에서 String의 인덱스를 2칸씩(O,I) 이동할 것이기 때문에, 카운트했던 cnt를 1 줄여준다.
					cnt--;
				}

				// 인덱스를 2씩 넘기며 while 문 'O','I' 루프 반복
				i += 2;
			}
		}
	}

	cout << ans;
	return 0;
};