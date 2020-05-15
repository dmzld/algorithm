#include <iostream>

using namespace std;

int N;
long long res[90];

int main(){
	cin >> N;

	res[1] = 1;
	res[2] = 1;

	for (int i = 3; i <= N; i++){
		res[i] = res[i - 2] + res[i - 1];
	}

	cout << res[N];

	return 0;
}
