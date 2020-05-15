#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
long long fibo[91];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= N; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[N];

	return 0;
}
