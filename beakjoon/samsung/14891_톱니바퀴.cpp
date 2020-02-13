#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int gear[4][8];
bool check[8] = { false, };
int K, ans = 0;

void rotation(int idx, int rot){
	check[idx] = true;
	int tmp[8];

	// first of all, check side gears will be rotated
	if (idx - 1 >= 0 && !check[idx - 1]){
		if (gear[idx][6] != gear[idx - 1][2])
			rotation(idx - 1, -rot);
	}
	if (idx + 1 < 4 && !check[idx + 1]){
		if (gear[idx][2] != gear[idx + 1][6])
			rotation(idx + 1, -rot);
	}

	// then, rotate current gear
	if (rot == 1){ // clock
		for (int i = 0; i < 8; i++)
			tmp[i] = gear[idx][(i + 7) % 8];
	}
	else if (rot == -1){ // counter clock
		for (int i = 0; i < 8; i++)
			tmp[i] = gear[idx][(i + 1) % 8];
	}
	for (int i = 0; i < 8; i++)
		gear[idx][i] = tmp[i];
	
	return;
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++){
		string state;
		cin >> state;
		for (int j = 0; j < state.size(); j++)
			gear[i][j] = state[j] - '0';
      
      // scanf(%1d,gear[i][j] => why this method can't get correct

	}

	cin >> K;
	for (int i = 0; i < K; i++){
		int idx, rot;
		memset(check, false, sizeof(check));
		cin >> idx >> rot;

		rotation(idx - 1, rot);
	}

	if (gear[0][0] == 1)
		ans += 1;
	if (gear[1][0] == 1)
		ans += 2;
	if (gear[2][0] == 1)
		ans += 4;
	if (gear[3][0] == 1)
		ans += 8;

	cout << ans;

	return 0;
}
