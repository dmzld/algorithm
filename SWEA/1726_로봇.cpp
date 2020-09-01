#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct state{
	int y, x, dir, cnt;
};

int M, N, map[101][101];
state src, dest;
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } }; // e w s n
int dirCost[4][4] = { { 0, 2, 1, 1 }, { 2, 0, 1, 1 }, { 1, 1, 0, 2 }, { 1, 1, 2, 0 } }; // cost to chage dir i to j
pair<int, int> cntmap[101][101]; // <cnt, dir>

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++){
			cntmap[i][j] = { -1, 0 };
			cin >> map[i][j];
		}
	cin >> src.y >> src.x >> src.dir;
	cin >> dest.y >> dest.x >> dest.dir;
	src.cnt = 0, dest.cnt = 0;
	cntmap[src.y][src.x] = { 0, src.dir };

	// for sync
	src.dir--;
	dest.dir--;

	if (src.y == dest.y && src.x == dest.x){
		cout << dirCost[src.dir][dest.dir];
		return 0;
	}

	queue<state> q;
	q.push(src);

	while (!q.empty()){
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().y, x = q.front().x,
				d = q.front().dir, cnt = q.front().cnt;
			q.pop();

			for (int j = 0; j < 4; j++){ // dir
				for (int k = 1; k <= 3; k++){ // range
					int ny = y + dir[j].first*k,
						nx = x + dir[j].second*k,
						ncnt = cnt + 1 + dirCost[d][j];

					if (ny < 1 || ny > M || nx < 1 || nx > N || map[ny][nx] == 1)
						break;

					if (ny == dest.y && nx == dest.x)
						ncnt += dirCost[j][dest.dir];

					if (cntmap[ny][nx].first == -1 || cntmap[ny][nx].first > ncnt){
						cntmap[ny][nx] = { ncnt, j };
						q.push({ ny, nx, j, ncnt });
					}
				}
			}
		}
	}


	cout << cntmap[dest.y][dest.x].first;

	return 0;
}
