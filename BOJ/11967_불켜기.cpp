#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> v[101][101]; // room<int,int> can be lighted int room[i][j]
bool beCheck[101][101] = { false, }, checked[101][101] = { false, }, light[101][101] = { false, }; // beCheck -> check, if light
pair<int, int> dir[4] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
int ans = 1;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int x, y, a, b;
		cin >> y >> x >> b >> a;
		v[y][x].push_back({ b, a });
	}

	// 시작점은 1,1
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	checked[1][1] = true;
	light[1][1] = true;

	while (!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();

		// 들어갈 가능성이 있는 방 위치 저장
		for (int i = 0; i < 4; i++){
			int ny = y + dir[i].first, nx = x + dir[i].second;
			if (ny > 0 && ny <= N && nx > 0 && nx <= N){
				if (!checked[ny][nx] && !beCheck[ny][nx]){ // 새로운 방이면 저장
					beCheck[ny][nx] = true;

					if (light[ny][nx]){ // 불이 이미 켜져 있으면 바로 들어간다
						q.push({ ny, nx });
						beCheck[ny][nx] = false;
						checked[ny][nx] = true;
					}
				}
			}
		}

		// 현재 위치에서 불 킨다
		for (int i = 0; i < v[y][x].size(); i++){
			int ny = v[y][x][i].first, nx = v[y][x][i].second;

			// 처음 불 키는 거면
			if (!light[ny][nx]){
				ans++;
				light[ny][nx] = true;
			}

			// 들어갈 수 있는 방이면
			if (!checked[ny][nx] && beCheck[ny][nx]){
				q.push({ ny, nx });
				beCheck[ny][nx] = false;
				checked[ny][nx] = true;
			}
		}
	}

	cout << ans;

	return 0;
}
