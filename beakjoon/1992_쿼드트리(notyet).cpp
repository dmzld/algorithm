#include <iostream>
#include <cstring>
using namespace std;

int data[64][64];

void zip(int n, int sx, int sy){
	int color = data[sx][sy];

	for (int i = sx; i < sx + n; i++){
		for (int j = sy; j < sy + n; j++){
			if (data[i][j] != color){
				cout << "(";
				zip(n / 2, sx, sy);
				zip(n / 2, sx, sy + n / 2);
				zip(n / 2, sx + n / 2, sy);
				zip(n / 2, sx + n / 2, sy + n / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << color;
}

int main(){

	int N;

	cin >> N;

	fflush(stdin);
	for (int i = 0; i < N; i++){
		fflush(stdin);
		for (int j = 0; j < N; j++){
			char a;
			scanf("%c", &a);
			data[i][j] = (int)(a - '0');
		}
	}

	zip(N, 0, 0);

	return 0;
}
