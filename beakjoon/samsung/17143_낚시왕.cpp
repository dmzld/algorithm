#include <iostream>
#include <vector>

using namespace std;

int R, C, M;
struct SDZ{
	int s; // velocity
	int d; // direction
	int z; // size
};
vector<SDZ> map[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int ans = 0;

void move(){
	vector<SDZ> tmp[101][101];

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			if (map[i][j].size() > 0){
				int cy = i, cx = j;
				int s = map[i][j][0].s, d = map[i][j][0].d, z = map[i][j][0].z;
				int T = map[i][j][0].s;
				map[i][j].clear();

				if (d == 0 || d == 1) // this point reduce execution time
					T %= (2 * (R - 1));
				else
					T %= (2 * (C - 1));

				for (int t = 0; t < T; t++){
					if (d == 0 || d == 1){
						if (cy + dy[d] <= 0 || cy + dy[d] > R)
							d = 1 - d;
						cy += dy[d];
					}
					else if (d == 2 || d == 3){
						if (cx + dx[d] <= 0 || cx + dx[d] > C)
							d = 5 - d;
						cx += dx[d];
					}
				}

				if (tmp[cy][cx].size() > 0){
					if (tmp[cy][cx][0].z < z)
						tmp[cy][cx][0] = { s, d, z };
				}
				else
					tmp[cy][cx].push_back({ s, d, z });
			}
		}
	}

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			if (tmp[i][j].size() > 0)
				map[i][j] = tmp[i][j];
		}
	}
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++){
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c].push_back({ s, d - 1, z });
	}

	for (int i = 1; i <= C; i++){ // fisherman position

		// fishing
		for (int j = 1; j <= R; j++){
			if (map[j][i].size() > 0){
				ans += map[j][i][0].z;
				map[j][i].clear();
				break;
			}
		}

		// sharks move
		move();
	}

	cout << ans;

	return 0;
}
