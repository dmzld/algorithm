#include <iostream>
#include <cmath>

using namespace std;

int N;
int res = 0;

void shift(int b[][20], int dir, int cnt);
void solution(int b[][20], int cnt);


void shift(int b[][20], int dir, int cnt){ // 0 : up, 1 : right, 2 : down, 3 : left
	int cb[20][20];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cb[i][j] = b[i][j];
		}
	}
	// MOVE UP
	if (dir == 0){
		// Add if same & adjust
		for (int j = 0; j < N; j++){ // column
			for (int i = 0; i < N; i++){ // row
				if (cb[i][j] != 0 && i < N - 1){
					int pos = i++;
					while (i < N - 1 && cb[i][j] == 0)
						i++;
					if (cb[i][j] != 0 && cb[pos][j] == cb[i][j]){
						cb[pos][j] *= 2;
						cb[i][j] = 0;
					}
					else // this point is add finally
						i--;
				}
			}
		}
		// Pull elements
		for (int j = 0; j < N; j++){
			int pos = 0;
			for (int i = 0; i < N; i++){
				if (cb[i][j] != 0){
					if (pos != i){
						cb[pos++][j] = cb[i][j];
						cb[i][j] = 0;
					}
					else
						pos++;
				}
			}
		}
	}
	// MOVE RIGHT
	else if (dir == 1){
		// Add if same & adjust
		for (int i = 0; i < N; i++){ // column
			for (int j = N - 1; j >= 0; j--){ // row
				if (cb[i][j] != 0 && j > 0){ 
					int pos = j--;
					while (j > 0 && cb[i][j] == 0)
						j--;
					if (cb[i][j] != 0 && cb[i][pos] == cb[i][j]){
						cb[i][pos] *= 2;
						cb[i][j] = 0;
					}
					else
						j++;
				}
			}
		}
		// Pull elements
		for (int i = 0; i < N; i++){
			int pos = N - 1;
			for (int j = N - 1; j >= 0; j--){
				if (cb[i][j] != 0){
					if (pos != j){
						cb[i][pos--] = cb[i][j];
						cb[i][j] = 0;
					}
					else
						pos--;
				}
			}
		}
	}
	// MOVE DOWN
	else if (dir == 2){
		// Add if same & adjust
		for (int j = 0; j < N; j++){ // column
			for (int i = N - 1; i >= 0; i--){ // row
				if (cb[i][j] != 0 && i > 0){
					int pos = i--;
					while (i > 0 && cb[i][j] == 0)
						i--;
					if (cb[i][j] != 0 && cb[pos][j] == cb[i][j]){
						cb[pos][j] *= 2;
						cb[i][j] = 0;
					}
					else
						i++;
				}
			}
		}
		// Pull elements
		for (int j = 0; j < N; j++){
			int pos = N - 1;
			for (int i = N - 1; i >= 0; i--){
				if (cb[i][j] != 0){
					if (pos != i){
						cb[pos--][j] = cb[i][j];
						cb[i][j] = 0;
					}
					else
						pos--;
				}
			}
		}
	}
	// MOVE LEFT
	else if (dir == 3){
		// Add if same & adjust
		for (int i = 0; i < N; i++){ // row
			for (int j = 0; j < N; j++){ // column
				if (cb[i][j] != 0 && j < N - 1){
					int pos = j++;
					while (j < N - 1 && cb[i][j] == 0)
						j++;
					if (cb[i][j] != 0 && cb[i][pos] == cb[i][j]){
						cb[i][pos] *= 2;
						cb[i][j] = 0;
					}
					else
						j--;
				}
			}
		}
		// Pull elements
		for (int i = 0; i < N; i++){
			int pos = 0;
			for (int j = 0; j < N; j++){
				if (cb[i][j] != 0){
					if (pos != j){
						cb[i][pos++] = cb[i][j];
						cb[i][j] = 0;
					}
					else
						pos++;
				}
			}
		}
	}
	
	/*
	cout << cnt << "th, dir = " << dir << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << b[i][j] << " ";
		}cout << "\n";
	}cout << "\n\n";
	*/

	solution(cb, cnt + 1);
}

void solution(int b[][20], int cnt){

	if (cnt > 5){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (res < b[i][j])
					res = b[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++){
		shift(b, i, cnt);
	}
}

int main(){
	int board[20][20];
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	solution(board, 1);

	cout << res;
}
