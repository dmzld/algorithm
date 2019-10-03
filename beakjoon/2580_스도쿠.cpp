#include <iostream>
#include <vector>
#include <cmath>
//#include <utility>

using namespace std;

int board[9][9];

pair<int, int> z[81]; // x,y of zeros
int idx = 0;

bool check_row(int cnt, int num){ // num == inserted number
	for (int i = 0; i < 9; i++){
		if (num == board[z[cnt].first][i]){
			return false;
		}
	}
	return true;
}

bool check_col(int cnt, int num){
	for (int i = 0; i < 9; i++){
		if (num == board[i][z[cnt].second]){
			return false;
		}
	}
	return true;
}

bool check_rec(int cnt, int num){
	//upper bound
	int x = (z[cnt].first / 3 + 1) * 3;
	int y = (z[cnt].second / 3 + 1) * 3;
	
	for (int i = x - 3; i < x; i++){
		for (int j = y - 3; j < y; j++){
			if (num == board[i][j]){
				return false;
			}
		}
	}
	return true;
}

void func(int cnt){
	if (cnt == idx){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++){
		if (check_col(cnt, i) && check_row(cnt, i) && check_rec(cnt, i)){
			board[z[cnt].first][z[cnt].second] = i;
			func(++cnt);
			cnt--;
			board[z[cnt].first][z[cnt].second] = 0;
		}
	}
}

int main(){

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> board[i][j];
			if (board[i][j] == 0)
				z[idx++] = make_pair(i, j);
		}
	}

	func(0);

	return 0;
}
