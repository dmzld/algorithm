#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, map[100][100];
pair<int, int> d[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans = 0, cnt = 0;

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
		q.push({ 0, 0 }); // 테두리 부분은 무조건 치즈가 없음 => bfs로 치즈의 엣지를 탐색

		while (!q.empty()){
			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++){
				int ny = y + d[i].first, nx = x + d[i].second;
				
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
					continue;

				if (map[ny][nx] == 0) // 치즈가 없으면 다음에 탐색
					q.push({ ny, nx });
				else if (map[ny][nx] == 1) // 치즈면 엣지부분이므로 삭제하기 위해 저장
					m.push({ ny, nx });

				check[ny][nx] = true;
			}
		}

		cnt = m.size(); // 남은 치즈 개수 저장
		while (!m.empty()){ // 치즈의 엣지 삭제
			int y = m.front().first, x = m.front().second;
			m.pop();
			map[y][x] = 0;
		}

		ans++;
	}

	cout << ans << "\n" << cnt << "\n";

	return 0;
}
