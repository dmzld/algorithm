#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, N;
char map[101][101];
pair<int, int> d[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = R; i >= 1; i--)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];

	cin >> N;
	for (int i = 0; i < N; i++){
		int cr, cc, cd;
		cin >> cr;
		if (i % 2 == 0){
			cc = 1;
			while (cc <= C){
				if (map[cr][cc] == 'x'){
					map[cr][cc] = '.';
					break;
				}
				cc++;
			}
		}
		else if (i % 2 == 1){
			cc = C;
			while (cc >= 1){
				if (map[cr][cc] == 'x'){
					map[cr][cc] = '.';
					break;
				}
				cc--;
			}
		}

		// map[cr][cc] == 이번에 깨진 미네랄 위치

		if (cc<1 || cc>C) // 깨진 미네랄 없이 막대기가 날아간경우
			continue;

		for (int k = 0; k < 4; k++){ // 깨진 미네랄의 클러스터 찾아서

			int nr = cr + d[k].first, nc = cc + d[k].second;

			if (nr<1 || nr>R || nc<1 || nc>C || map[nr][nc] != 'x')
				continue;

			bool check[101][101] = { false, };
			bool fly = true;
			queue<pair<int, int>> q;
			q.push({ nr, nc });
			check[nr][nc] = true;

			while (!q.empty() && fly){ // 클러스터가 떠있는지 판별하면서 찾음
				int y = q.front().first, x = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++){
					int ny = y + d[i].first, nx = x + d[i].second;

					if (ny<1 || ny>R || nx<1 || nx>C || check[ny][nx])
						continue;

					if (map[ny][nx] == 'x'){
						if (ny == 1){ // 클러스터가 바닥과 붙어있으면 떨어뜨리는 작업 필요없음
							fly = false;
							break;
						}

						q.push({ ny, nx });
						check[ny][nx] = true;
					}
				}
			}

			if (fly){ // 클러스터가 떠있으면
				int h = 1000; // 떨어지는 높이
				for (int i = 1; i <= R; i++){
					for (int j = 1; j <= C; j++){
						if (check[i][j]){
							int nh = i - 1;
							while (nh >= 1 && map[nh][j] != 'x')
								nh--;

							if (check[nh][j]) // 같은 클러스터 미네랄과 만나는 경우라면 X
								continue;
							
							nh++;


							h = min(h, i - nh); // 클러스터 미네랄 중 가장 짧게 추락하는 것에 맞춰 추락한다
						}
					}
				}
					
				for (int i = 1; i <= R; i++)
					for (int j = 1; j <= C; j++)
						if (check[i][j]){
							map[i][j] = '.';
							map[i - h][j] = 'x';
						}

			}
		}
	}

	for (int i = R; i >= 1; i--){
		for (int j = 1; j <= C; j++){
			cout << map[i][j];
		}cout << "\n";
	}cout << "\n";

	return 0;
}
