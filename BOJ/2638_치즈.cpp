#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, map[100][100];
pair<int, int> d[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans = 0;

bool allMelted(){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 1)
				return false;
		}
	}

	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	while (!allMelted()){
		bool check[100][100] = { false, };
		queue<pair<int, int>> m;
		queue<pair<int, int>> q;
		q.push({ 0, 0 });

		while (!q.empty()){
			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++){
				int ny = y + d[i].first, nx = x + d[i].second;
				
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
					continue;

				if (map[ny][nx] == 0){
					q.push({ ny, nx });
					check[ny][nx] = true;
				}
				else if (map[ny][nx] == 1)
					m.push({ ny, nx });
					
			}
		}


		while (!m.empty()){
			int y = m.front().first, x = m.front().second;
			int cnt = 0;
			m.pop();

			for (int i = 0; i < 4; i++){
				int ny = y + d[i].first, nx = x + d[i].second;
        // 빈 공간이면서 외부 공간인 경우
				if (map[ny][nx] == 0 && check[ny][nx])
					cnt++;
			}
			
			if (cnt>=2)
				map[y][x] = 0;
		}

		ans++;
	}

	cout << ans << "\n";

	return 0;
}
