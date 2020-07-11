#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N, M, K;
string light[50];
int ans = 0;

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> light[i];
	cin >> K;

	for (int i = 0; i < N; i++){
		int cnt = 0, sameR = 0;
		for (int j = 0; j < M; j++)
			if (light[i][j] == '0')
				cnt++;
		if (cnt > K || (K - cnt) % 2 == 1) continue; // can make 'bright row'

		for (int j = i; j < N; j++)
			if (light[i] == light[j]) sameR++;

		ans = max(ans, sameR);
	}
		
	cout << ans;

	return 0;
}
