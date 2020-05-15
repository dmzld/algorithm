#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, tot = 0;
int board[15]; // board[row]=col

void func(int row){ // row == cur row
	// 검증
	for (int i = 0; i < row; i++){
		if (board[i] == board[row]) // col dup
			return;
		if (abs(i - row) == abs(board[i] - board[row])) // diagonal dup
			return;
	}
	
	if (row == N - 1){
		tot++;
		return;
	}

	// 일단 넣고 다음 func에서 검증
	for (int i = 0; i < N; i++){
		board[row + 1] = i;
		func(row + 1);
	}
}

int main(){

	cin >> N;

	for (int i = 0; i < N; i++){
		board[0] = i;
		func(0);
	}

	cout << tot;

	return 0;
}
