#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c; // (2^N)X(2^N) 행렬
int cnt = 0;

void solution(int n, int y, int x){
	if (n == 2){ // start of part of recursive
		if (y == r&&x == c){
			cout << cnt;
			return;
		}
		cnt++;
		if (y == r&&x + 1 == c){
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r&&x == c){
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r&&x + 1 == c){
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}
	else{
		solution(n / 2, y, x);
		solution(n / 2, y, x + n / 2);
		solution(n / 2, y + n / 2, x);
		solution(n / 2, y + n / 2, x + n / 2);
	}
}


int main(){

	cin >> N >> r >> c;

	solution(pow(2, N), 0, 0);

	return 0;
}
