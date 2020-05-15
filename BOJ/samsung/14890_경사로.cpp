#include <iostream>
#include <cmath>

using namespace std;

int N, L;
int map[100][100];
int ans = 0;

void solution(int n){
	bool canGo = true;
	bool bridge[100] = { false, };

	// row n
	for (int i = 1; i < N; i++){ // col
		if (bridge[i])
			continue;

		int h1 = map[n][i - 1], h2 = map[n][i];
		
		if (abs(h1 - h2) > 1){
			canGo = false;
			break;
		}
		else if (h1 - h2 == 1){ // high low
			if (i + (L - 1) >= N){
				canGo = false;
				break;
			}
			else{
				for (int j = i; j < i + L; j++){
					if (map[n][j] != h2 || bridge[j]){
						canGo = false;
						break;
					}
				}
				if (canGo){
					for (int j = i; j < i + L; j++){
						bridge[j] = true;
					}
				}
			}
		}
		else if (h2 - h1 == 1){ // low high
			if (i - L < 0){
				canGo = false;
				break;
			}
			else{
				for (int j = i - 1; j > i - 1 - L ; j--){ // is it possible that construct bridge on (i - L) ~ i ?
					if (map[n][j] != h1 || bridge[j]){
						canGo = false;
						break;
					}
				}
				if (canGo)
					for (int j = i - 1; j > i - 1 - L; j--) // contruct bridge
						bridge[j] = true;
			}
		}
	}

	// validation & reinit
	if (canGo)
		ans++;
	else
		canGo = true;
	for (int i = 0; i < N; i++)
		bridge[i] = false;

	// col n
	for (int i = 1; i < N; i++){ // row
		if (bridge[i])
			continue;

		int h1 = map[i - 1][n], h2 = map[i][n];
		
		if (abs(h1 - h2) > 1){
			canGo = false;
			break;
		}
		else if (h1 - h2 == 1){
			if (i + L -1 >= N){
				canGo = false;
				break;
			}
			else{
				for (int j = i; j < i + L; j++){
					if (map[j][n] != h2 || bridge[j]){
						canGo = false;
						break;
					}
				}
				if (canGo){
					for (int j = i; j < i + L; j++){
						bridge[j] = true;
					}
				}
			}
		}
		else if (h2 - h1 == 1){
			if (i - L < 0){
				canGo = false;
				break;
			}
			else{
				for (int j = i - 1; j > i - 1 - L; j--){ // is it possible that construct bridge on (i - L) ~ i ?
					if (map[j][n] != h1 || bridge[j]){
						canGo = false;
						break;
					}
				}
				if (canGo)
					for (int j = i - 1; j > i - 1 - L; j--) // contruct bridge
						bridge[j] = true;
			}
		}
	}

	if (canGo)
		ans++;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++){
		solution(i);
	}

	cout << ans;

	return 0;
}
