#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
  key를 bitmask로 체크하면서 bfs
  
  ex)
  keys = { 1 } => key = 2
  keys = { 1, 6 } => key = 2 + 2^6
  
  새로운 key 추가 : OR연산 => ckey = ckey | 1 << (int)(map[y][x] - 'a') 
  문을 만났을 때 key 있는지 확인 : AND  => key & 1 << (int)(map[y][x] -'A')
*/


struct state{
	int y, x, key;
};

int N, M;
char map[50][50];
int check[50][50][64] = { false, }; // [y][x][key], key = 2진수형태로 check
pair<int, int> dir[4] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };

queue<state> q;
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == '0'){
				check[i][j][0] = true;
				q.push({ i, j, 0 });
			}
		}
	}

	while (!q.empty()){
		int qSize = q.size();

		for (int t = 0; t < qSize; t++){
			state s = q.front();
			q.pop();

			if (map[s.y][s.x] == '1'){
				cout << ans;
				return 0;
			}

			for (int i = 0; i < 4; i++){
				int ny = s.y + dir[i].first, nx = s.x + dir[i].second,
					nkey = s.key;

				if (ny < 0 || ny >= N || nx < 0 || nx >= M || check[ny][nx][nkey] || map[ny][nx] == '#')
					continue;

				if (map[ny][nx] == '.' || map[ny][nx] == '0' || map[ny][nx] == '1'){ // 빈곳
					if (!check[ny][nx][nkey]){
						check[ny][nx][nkey] = true;
						q.push({ ny, nx, nkey });
					}
				}
				else if ((map[ny][nx] >= 'A' && map[ny][nx] <= 'F')){ // 문
					if (nkey & 1 << (int)(map[ny][nx] - 'A')){ // 문에 해당하는 키가 있으면
						check[ny][nx][nkey] = true;
						q.push({ ny, nx, nkey });
					}
				}
				else if ((map[ny][nx] >= 'a' && map[ny][nx] <= 'f')){ // 열쇠
					nkey = nkey | 1 << (int)(map[ny][nx] - 'a'); // 가진 열쇠 추가
					if (!check[ny][nx][nkey]){
						check[ny][nx][nkey] = true;
						q.push({ ny, nx, nkey });
					}
				}
			}
		}
		ans++;
	}

	cout << -1;

	return 0;
}
