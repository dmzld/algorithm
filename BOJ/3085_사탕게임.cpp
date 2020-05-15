#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 0;
char board[50][50];
int res = 0;

void solution(int y, int x){
	int max = 0;
	int sum = 0;
	char color;

	// row
	color = board[y][0];
	sum = 1;
	for (int i = 1; i < N; i++){
		if (color == board[y][i])
			sum++;
		else{ // color != board[y][i]
			color = board[y][i];
			sum = 1;
		}

		if (max < sum)
			max = sum;
	}
	// column
	color = board[0][x];
	sum = 1;
	for (int i = 1; i < N; i++){
		if (color == board[i][x])
			sum++;
		else{ // color != board[y][i]
			color = board[i][x];
			sum = 1;
		}

		if (max < sum)
			max = sum;
	}

	if (res < max)
		res = max;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			// change with side
			if (j + 1 < N){
				swap(board[i][j], board[i][j + 1]);
				solution(i, j);
				solution(i, j + 1);
				swap(board[i][j], board[i][j + 1]);
			}
			// change with below
			if (i + 1 < N){
				swap(board[i][j], board[i + 1][j]);
				solution(i, j);
				solution(i + 1, j);
				swap(board[i][j], board[i + 1][j]);
			}
		}
	}

	cout << res;

	return 0;
}
