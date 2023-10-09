#include <bits/stdc++.h>
using namespace std;

string password;
bool haveVowel;
int cnt;

bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> password;

		if (password == "end")
			break;

		bool flag = true;
		haveVowel = false;
		cnt = 0;

		for (int i = 0; i < password.size(); i++)
		{
			// 모음일 경우
			if (isVowel(password[i]))
			{
				// 모음이 하나라도 있음 -> true
				haveVowel = true;

				if (i - 1 >= 0)
				{
					// 이전 알파벳도 모음인 경우
					if (isVowel(password[i - 1]))
					{
						// 이전 알파벳과 같지 않은 경우
						if (password[i] != password[i - 1])
						{
							cnt = 0;

							// 다음 알파벳 살펴봄
							if (i + 1 <= password.size()-1)
							{
								// 다음 알파벳도 모음인 경우 부적합
								if (isVowel(password[i + 1]))
									flag = false;
							}
						}
						// 이전 알파벳과 같은 경우
						else
						{
							cnt++;
							// ee나 oo인 경우 적합
							if (password[i] == 'e' && password[i - 1] == 'e'
								|| password[i] == 'o' && password[i - 1] == 'o')
								flag = true;
							else // 그외 부적합
								flag = false;

						}
				
					}
				}
			}

			// 자음인 경우
			else
			{
				if (i - 1 >= 0)
				{
					// 이전 알파벳도 자음인 경우
					if (!isVowel(password[i - 1]))
					{
						// 이전 알파벳과 같은 경우
						if (password[i] == password[i - 1])
						{
							flag = false;
						}
						else
						{
							// 다음 알파벳 살펴봄
							if (i + 1 <= password.size() - 1)
							{
								// 다음 알파벳도 자음인 경우 부적합
								if (!isVowel(password[i + 1]))
									flag = false;
							}
							else
								flag = true;
						}
					}
					else
						cnt = 0;
				}
			}

			if (!flag) break;
		}


		if (flag && haveVowel && cnt <=1)
			cout << "<" << password << "> is acceptable." << '\n';
		else
			cout << "<" << password << "> is not acceptable." << '\n';
	}

}