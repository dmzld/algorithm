#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct pos{
	int y, x;
};

int	T;
int N, map[100][100];
vector<pos> WH[11];
pos dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
bool check[100][100][4] = { false, };
int ans;

int changeDir(int d, int b){
	int nd;
	switch (b){ // 블럭에 따라
	case 1:
		if (d == 0)
			nd = 1;
		else if (d == 1)
			nd = 3;
		else if (d == 2)
			nd = 0;
		else if (d == 3)
			nd = 2;
		break;
	case 2:
		if (d == 0)
			nd = 1;
		else if (d == 1)
			nd = 2;
		else if (d == 2)
			nd = 3;
		else if (d == 3)
			nd = 0;
		break;
	case 3:
		if (d == 0)
			nd = 2;
		else if (d == 1)
			nd = 0;
		else if (d == 2)
			nd = 3;
		else if (d == 3)
			nd = 1;
		break;
	case 4:
		if (d == 0)
			nd = 3;
		else if (d == 1)
			nd = 0;
		else if (d == 2)
			nd = 1;
		else if (d == 3)
			nd = 2;
		break;
	}

	return nd;
}

void dfs(int y, int x, int d){
	int cnt = 0;
	//check[y][x][d] = true;
	int ny = y + dir[d].y, nx = x + dir[d].x, nd = d; // 시작 위치 + 시작 방향 한칸부터
	
	while (1){
		// 게임이 종료되지 않는 상태에서 범위 안에서 0이 아닐 때까지 이동
		while (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] == 0 && (ny != y || nx != x) && map[ny][nx] != -1){
			//check[ny][nx][nd] = true;
			ny += dir[nd].y, nx += dir[nd].x;
		}

		// 범위 밖에거나 블럭5이면 반대 방향으로, 점수++
		if (ny < 0 || ny >= N|| nx < 0 || nx >= N || map[ny][nx] == 5){
			cnt++;
			if (nd % 2 == 0)
				nd += 1;
			else
				nd -= 1;
			ny += dir[nd].y, nx += dir[nd].x;
		}
		// 블랙홀이거나 시작위치로 돌아왔을 경우 게임 끝
		else if (map[ny][nx] == -1 || (ny == y && nx == x)){
			//cout << y << "," << x << " : " << cnt << "\n";
			ans = max(ans, cnt);
			return;
		}
		// 블럭1~4인 경우 조건에 맞춰 방향 전환, 점수++
		else if (map[ny][nx] >= 1 && map[ny][nx] <= 4){
			cnt++;
			nd = changeDir(nd, map[ny][nx]);
			ny += dir[nd].y, nx += dir[nd].x;
		}
		// 웜홀일 경우 짝꿍 웜홀로 이동 및 같은 방향으로 한칸 전진
		else if (map[ny][nx] >= 6 && map[ny][nx] <= 10){
			for (int i = 0; i < 2; i++){
				if (WH[map[ny][nx]][i].y != ny || WH[map[ny][nx]][i].x != nx){
					int ty = ny, tx = nx;
					ny = WH[map[ty][tx]][i].y + dir[nd].y;
					nx = WH[map[ty][tx]][i].x + dir[nd].x;
					break;
				}
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		// 초기화
		for (int i = 6; i <= 10; i++)
			WH[i].clear();
		ans = 0;

		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10)
					WH[map[i][j]].push_back({ i, j });
			}
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				for (int k = 0; k < 4; k++){
					if (map[i][j] == 0){ // 같은 위치, 방향 중복 탐색 제거
						dfs(i, j, k);
					}
				}
			}

		cout << "#" << t << " " << ans << "\n";

	}
	

	return 0;
}
