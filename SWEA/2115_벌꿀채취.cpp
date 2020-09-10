#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>

using namespace std;

struct Pos{
	int y, x;
};

int	T;
int N, M, C, map[10][10];
int ans;

void harvest(int ay, int ax, int by, int bx){
	int AC[6][31] = { 0, }, BC[6][31] = { 0, }; // *C[i][j] : i번째까지의 꿀들로 한계 채취량 j가지고 가능한 최대 채취량 (Knapsack)

	for (int i = 1; i <= M; i++){
		for (int j = 0; j <= C; j++){
			int w = map[ay][ax + i - 1];
			if (j >= w)
				AC[i][j] = max(AC[i - 1][j], AC[i - 1][j - w] + w*w);
			else
				AC[i][j] = AC[i - 1][j];
		}
	}

	for (int i = 1; i <= M; i++){
		for (int j = 0; j <= C; j++){
			int w = map[by][bx + i - 1];
			if (j >= w)
				BC[i][j] = max(BC[i - 1][j], BC[i - 1][j - w] + w*w);
			else
				BC[i][j] = BC[i - 1][j];
		}
	}

	ans = max(ans, AC[M][C] + BC[M][C]);

}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		ans = 0;

		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		// A : i,j
		for (int i = 0; i < N; i++){
			for (int j = 0; j <= N - M; j++){

				// B : p,q
				// 남은 한 줄
				for (int q = j + M; q <= N - M; q++){
					harvest(i, j, i, q);
				}

				// 나머지 영역
				for (int p = i + 1; p < N; p++){
					for (int q = 0; q <= N - M; q++){
						harvest(i, j, p, q);
					}
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
