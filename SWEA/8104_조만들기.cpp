#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){

	int T = 0, N = 0, K = 0;
	
	cin >> T; // 전체 = N * K


	for (int l = 0; l < T; l++){ // testcase
		
		cin >> N >> K;
		vector<int> team(K, 0);
		
		for (int j = 0; j < N; j++){ // row
			if (j % 2 == 0){
				for (int k = 0; k < K; k++){ //ascend
					team[k] += j*K + 1 + k;
				}
			}
			else{
				for (int k = K - 1; k >= 0; k--){ //descend
					team[k] += j*K + 1 + K-1-k;
				}
			}
		}

		cout << "#" << l + 1;
		for (int j = 0; j < K; j++)
			cout << " " << team[j];
		cout << "\n";
	}

	

	return 0;
}
