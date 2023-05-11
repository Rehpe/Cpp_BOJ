#include <bits/stdc++.h>
using namespace std;

int T;
int H, W,N;
int Floor, Room;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;

		// 층수: 손님번호(N) % 층수(H)
		if (N % H == 0)
			Floor = H;
		else
			Floor = N % H;

		// 호수: 손님번호(N) / 층수(H) + 1
		if (N % H == 0)
			Room = N / H;
		else
			Room = (N / H) + 1;

		cout << Floor;
		cout.fill('0');
		cout.width(2);
		cout << Room;

		if (i == T - 1)
			return 0;
		else
			cout << '\n';
	}
}