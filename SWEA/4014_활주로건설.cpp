#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int	T;
int N, X, map[20][20];
int ans;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		ans = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		// row
		for (int i = 0; i < N; i++){
			bool check[20] = { false, };
			bool cont = true;

			for (int j = 0; j < N - 1; j++){
				if (abs(map[i][j] - map[i][j + 1]) > 1){
					cont = false;
					break;
				}
				else if (map[i][j] < map[i][j + 1]){
					for (int k = j - 1; k > j - X; k--){
						if (k<0 || check[k] || map[i][k] != map[i][j]){
							cont = false;
							break;
						}
					}

					if (cont)
						for (int k = j; k > j - X; k--)
							check[k] = true;
				}
				else if (map[i][j] > map[i][j + 1]){
					for (int k = (j + 1) + 1; k < (j + 1) + X; k++){
						if (k >= N || check[k] || map[i][k] != map[i][j + 1]){
							cont = false;
							break;
						}
					}

					if (cont)
						for (int k = j + 1; k < (j + 1) + X; k++)
							check[k] = true;
				}
			}

			if (cont){
				//cout << i << "\n";
				ans++;
			}
		}

		// col
		for (int j = 0; j < N; j++){
			bool check[20] = { false, };
			bool cont = true;

			for (int i = 0; i < N - 1; i++){
				if (abs(map[i][j] - map[i + 1][j]) > 1){
					cont = false;
					break;
				}
				else if (map[i][j] < map[i + 1][j]){
					for (int k = i - 1; k > i - X; k--){
						if (k<0 || check[k] || map[k][j] != map[i][j]){
							cont = false;
							break;
						}
					}

					if (cont)
						for (int k = i; k > i - X; k--)
							check[k] = true;
				}
				else if (map[i][j] > map[i + 1][j]){
					for (int k = (i + 1) + 1; k < (i + 1) + X; k++){
						if (k >= N || check[k] || map[k][j] != map[i + 1][j]){
							cont = false;
							break;
						}
					}

					if (cont)
						for (int k = i + 1; k < (i + 1) + X; k++)
							check[k] = true;
				}
			}

			if (cont){
				//cout << j << "\n";
				ans++;
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
