#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int coin[10];
int cur = 0, cnt = 0;

int main(){
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = N - 1; i >= 0; i--){
		while (cur + coin[i] <= K){
			cur += coin[i];
			cnt++;
		}
		if (cur == K){
			cout << cnt;
			return 0;
		}
	}

	return 0;
}
