#include <iostream>
#include <vector>
using namespace std;


//vector< vector<int> > e(C + 1, vector<int>(C + 1, 0));
int main(){

	int M = 0, N = 0;
	int fn = 0, fm = 0;
	int Bc = 0, Wc = 0, cur = 0, res = 64; // 8*8=64

	cin >> N >> M; 
	vector< vector<char> > c(N, vector<char>(M, 'N'));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> c[i][j];
		}
	}
	
	while (1){
	
		Bc = 0;
		Wc = 0;
		
		// 00 = B
		for (int i = fn; i < fn + 8; i++){
			for (int j = fm; j < fm + 8; j++){

				if (((i + j) % 2) == 0 && c[i][j] == 'W') Bc++;
				else if (((i + j) % 2) == 1 && c[i][j] == 'B') Bc++;

			}
		}


		// 00 = W
		for (int i = fn; i < fn + 8; i++){
			for (int j = fm; j < fm + 8; j++){
				if (((i + j) % 2) == 0 && c[i][j] == 'B') Wc++;
				else if (((i + j) % 2) == 1 && c[i][j] == 'W') Wc++;
			}
		}

		(Bc > Wc) ? cur = Wc : cur = Bc;

		if (cur < res) res = cur;

		//첫주소 증가
		if (fm == M - 8){
			if (fn == N - 8) break;
			fm = 0;
			fn++;
		}
		else{
			fm++;
		}
	}	
	
	cout << res;
		
	return 0;
}
