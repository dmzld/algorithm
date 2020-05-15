#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void padovan(int i){
		
}

int main(){

	int N = 0, M = 0;
	int sum = 0, res = 0;
	cin >> N >> M;
	vector<int> card(N, 0);

	for (int i = 0; i < N; i++){
		cin >> card[i];
	}

	for (int i = 0; i < N - 2; i++){
		for (int j = i + 1; j < N - 1; j++){
			for (int k = j + 1; k < N; k++){
				//cout << i << j << k << "\n";
				sum = card[i] + card[j] + card[k];
				if (sum > M)
					continue;
				if (abs(res - M) > abs(sum - M))
					res = sum;
			}
		}
	}
	cout << res;
	return 0;
}
