#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321;

int W, H;
char map[100][100];
struct Pos{
	int y;
	int x;
};
struct Val{
	int pDir;
	int cnt;
};
vector<Pos> razer;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int route[100][100];

int ans;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> W >> H;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> map[i][j];
			if (map[i][j] == 'C'){
				razer.push_back({ i, j });
			}
			route[i][j] = INF;
		}
	}

	ans = INF;
	queue<pair<Pos, Val> > q; // y, x, previous dir, curve cnt
	route[razer[0].y][razer[0].x] = 0;

	q.push({ { razer[0].y, razer[0].x }, { -1, -1 } });
	while (!q.empty()){
		int y = q.front().first.y;
		int x = q.front().first.x;
		int pdir = q.front().second.pDir;
		int cnt = q.front().second.cnt;
		q.pop();

		for (int i = 0; i < 4; i++){
			int cy = y + dy[i];
			int cx = x + dx[i];
			int ccnt;

			if (pdir == i)
				ccnt = cnt;
			else
				ccnt = cnt + 1;
			if (cy < 0 || cy >= H || cx < 0 || cx >= W)
				continue;
			
			if (map[cy][cx] == '*' || route[cy][cx] < ccnt)
				continue;

			if (cy == razer[1].y && cx == razer[1].x){ // arrive
				if (ans > ccnt)
					ans = ccnt;
				continue;
			}
			route[cy][cx] = ccnt;
			q.push({ { cy, cx }, { i, ccnt } });
		}
	}

	cout << ans;

	return 0;
}
