#include <iostream>

using namespace std;

int N, cnt[1001];

int main()
{
	cnt[1] = 1;
	cnt[2] = 2;

	for (int i = 3; i <= 1000; ++i)
	{
		cnt[i] = (cnt[i - 1] + cnt[i - 2]) % 10007;
	}

	cin >> N;
	cout << cnt[N];

	return 0;
}
