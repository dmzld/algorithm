#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T, N, K;
int dia[10001];

int main(){

	cin >> T;

	for (int i = 0; i < T; i++){
		int sum = 0;
		int res = 0;
		memset(dia, 0, sizeof(dia));

		cin >> N >> K;
		for (int j = 0; j < N; j++){
			int tmp;
			cin >> tmp;
			dia[tmp]++;
		}
		
		for (int j = 1; j <= K + 1; j++)
			sum += dia[j];
		res = sum; // == dia[1] + ... + dia[K+1]

		for (int j = K + 2; j <= 10000; j++){
			sum -= dia[j - (K + 1)];
			if (dia[j] > 0){
				sum += dia[j];
				if (res < sum)
					res = sum;
			}
		}
	

		cout << "#" << i + 1 << " " << res << "\n";
	}


	return 0;
}
