#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long M;
vector<long long> W, sum;

long long find(int idx){
	for (long long h = W[idx]; h < W[idx + 1]; h++){
		if ((sum[N] - sum[idx]) - (N - idx)*h < M){
			return h - 1;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	W.resize(N + 1, 0); // length of 'i'th wood
	sum.resize(N + 1, 0); // sum of length of wood

	for (int i = 1; i <= N; i++)
		cin >> W[i];
	sort(W.begin(), W.end());

	for (int i = 1; i <= N; i++)
		sum[i] = W[i] + sum[i - 1];
	
	for (int i = N - 1; i >= 0; i--){
		if ((sum[N] - sum[i]) - (N- i)*W[i] >= M){ // tot len of cut wood >= M
			cout << find(i);
			break;
		}
	}
  
  // try to solve using binary search


	return 0;
}
