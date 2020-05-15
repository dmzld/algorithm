#include <iostream>
using namespace std;

int main(){

	int T, N, M;
	char ary[11][11] = { 0, };
	char ary2[11][11] = { 0, };
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cin >> ary[i][j];
			}
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				ary2[i][j] = ary[i][M - j - 1];
			}
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cout << ary2[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0;
}
