#include <iostream>
#include <vector>

using namespace std;

int r, c, k;
int map[101][101] = { 0, };
int R = 3, C = 3;
bool flag = false;
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> map[i][j];

	while (1){
		if (map[r][c] == k){
			flag = true;
			break;
		}
		else if (ans > 100)
			break;
		ans++;

		if (R >= C){
			// r
			for (int i = 1; i <= R; i++){
				int v[101] = { 0, };
				int max = 0, cC = 1;
				for (int j = 1; j <= C; j++){
					v[map[i][j]]++;
					if (max < v[map[i][j]])
						max = v[map[i][j]];
				}

				for (int j = 1; j <= max; j++){ // count of #
					for (int k = 1; k <= 100; k++){ // #
						if (v[k] == j){
							map[i][cC++] = k;
							map[i][cC++] = v[k];
						}
					}
				}

				if (C <= cC - 1)
					C = cC - 1;
				else{
					for (int j = cC; j <= C; j++)
						map[i][j] = 0;
				}
			}
		}
		else{
			// c
			for (int j = 1; j <= C; j++){
				int v[101] = { 0, };
				int max = 0, cR = 1;
				for (int i = 1; i <= R; i++){
					v[map[i][j]]++;
					if (max < v[map[i][j]])
						max = v[map[i][j]];
				}

				for (int i = 1; i <= max; i++){ // count of #
					for (int k = 1; k <= 100; k++){ // #
						if (v[k] == i){
							map[cR++][j] = k;
							map[cR++][j] = v[k];
						}
					}
				}

				if (R <= cR - 1)
					R = cR - 1;
				else{
					for (int i = cR; i <= R; i++)
						map[i][j] = 0;
				}
			}
		}
	}

	if (flag)
		cout << ans;
	else
		cout << -1;


	return 0;
}
