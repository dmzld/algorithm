#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, num[1000000];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i <= N; i++)
		num[i] = (num[i - 1] + num[i - 2]) % 15746;

	cout << num[N];

	return 0;
}
