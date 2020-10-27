#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, map[100][100], ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int t = 1; t <= 10; t++){
		cin >> N;
		ans = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
			

		for (int j = 0; j < N; j++){ // col
			for (int i = 0; i < N; i++){ // row
				if (map[i][j] == 1){
					for (int k = i + 1; k < N; k++){
						if (map[k][j] == 1) // 어쩌피 하나의 교착 집합
							map[k][j] = 0;
						else if (map[k][j] == 2){
							ans++;
							i = k;
							break;
						}
					}
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
