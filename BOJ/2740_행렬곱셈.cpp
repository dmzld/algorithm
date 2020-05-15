#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N, M,K;
	
	cin >> N >> M;
	vector<vector<int> > m(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> m[i][j];
		}
	}

	cin >> M >> K;
	vector<vector<int> > m2(M, vector<int>(K, 0));
	for (int i = 0; i < M; i++){
		for (int j = 0; j < K; j++){
			cin >> m2[i][j];
		}
	}

	vector<vector<int> > m3(N, vector<int>(K, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			for (int k = 0; k < M; k++)
				m3[i][j] += m[i][k] * m2[k][j];
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			cout << m3[i][j] << " ";
		}cout << "\n";
	}
}
