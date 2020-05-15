#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rope[100000];
int res = 0;

int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope, rope + N);

	for (int i = 0; i < N; i++){
		if (res < rope[i] * (N - i))
			res = rope[i] * (N - i);
	}

	cout << res;

	return 0;
}
