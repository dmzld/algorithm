#include <iostream>
#include <cstring>
using namespace std;

int paper[2187][2187];
int u = 0, z = 0, o = 0; // under zero over

void cut(int n, int sx, int sy){
	int color = paper[sx][sy];

	for (int i = sx; i < sx + n; i++){
		for (int j = sy; j < sy + n; j++){
			if (paper[i][j] != color){
				cut(n / 3, sx, sy);
				cut(n / 3, sx, sy + n / 3);
				cut(n / 3, sx, sy + 2 * n / 3);

				cut(n / 3, sx + n / 3, sy);
				cut(n / 3, sx + n / 3, sy + n / 3);
				cut(n / 3, sx + n / 3, sy + 2 * n / 3);

				cut(n / 3, sx + 2 * n / 3, sy);
				cut(n / 3, sx + 2 * n / 3, sy + n / 3);
				cut(n / 3, sx + 2 * n / 3, sy + 2 * n / 3);
				return;
			}
		}
	}

//	cout << sx << sy << "plus\n";
	if (color == -1)
		u++;
	else if (color == 0)
		z++;
	else // color == 1
		o++;
}

int main(){

	int N;

	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &paper[i][j]);
		}
	}	

	cut(N, 0, 0);

	cout << u << "\n" << z << "\n" << o << "\n";

	return 0;
}
