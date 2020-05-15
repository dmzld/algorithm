#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[7] = { 0, }; // 1 ~ 6
pair<int, int> direction[5] = { { 0, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } }; // 1 ~ 4 동 서 북 남

void rolling(int dir){
	int tmp[7];
	switch (dir){
	case 1:
		tmp[1] = dice[4];
		tmp[2] = dice[2];
		tmp[3] = dice[1];
		tmp[4] = dice[6];
		tmp[5] = dice[5];
		tmp[6] = dice[3];
		break;
	case 2:
		tmp[1] = dice[3];
		tmp[2] = dice[2];
		tmp[3] = dice[6];
		tmp[4] = dice[1];
		tmp[5] = dice[5];
		tmp[6] = dice[4];
		break;
	case 3:
		tmp[1] = dice[5];
		tmp[2] = dice[1];
		tmp[3] = dice[3];
		tmp[4] = dice[4];
		tmp[5] = dice[6];
		tmp[6] = dice[2];
		break;
	case 4:
		tmp[1] = dice[2];
		tmp[2] = dice[6];
		tmp[3] = dice[3];
		tmp[4] = dice[4];
		tmp[5] = dice[1];
		tmp[6] = dice[5];
		break;
	}
	for (int i = 1; i <= 6; i++)
		dice[i] = tmp[i];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++){
		int dir;
		cin >> dir;

		if (y + direction[dir].first < 0 || y + direction[dir].first >= N || x + direction[dir].second < 0 || x + direction[dir].second >= M)
			continue;

		y += direction[dir].first;
		x += direction[dir].second;
		
		rolling(dir);

		if (map[y][x] == 0){
			map[y][x] = dice[6];
		}
		else {
			dice[6] = map[y][x];
			map[y][x] = 0;

		}

		cout << dice[1] << "\n";
	}

	return 0;
}
