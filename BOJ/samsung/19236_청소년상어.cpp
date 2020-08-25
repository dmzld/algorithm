#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> map[4][4]; // <number of fish, direction>

pair<int, int> dir[8] = { { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 } }; // <dy, dx>
int ans = 0;

void rotateFish(int sy, int sx){ // current location of shark
	int y, x; // location of current fish

	// fish move by order
	for (int n = 1; n <= 16; n++){
		y = -1, x = -1;

		// find current order fish
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (map[i][j].first == n)
					y = i, x = j;

		// if fish 'n' is already eaten, find next fish
		if (y == -1 && x == -1)
			continue;

		// find block where fish can move until one round
		for (int i = 0; i < 8; i++){ // 8 dir
			int cDir = (map[y][x].second + i) % 8;
			int ny = y + dir[cDir].first, nx = x + dir[cDir].second;

			// out of range, shark area
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == sy&&nx == sx))
				continue;

			// move & change
			pair<int, int> tmp = map[ny][nx];
			map[ny][nx] = { map[y][x].first, cDir };
			map[y][x] = tmp;
			break;
		}
	}
	
	return;
}

void dfs(int y, int x, int d, int tot){ // location (y,x) of shark, direction of shark, sum of the fish number eaten
	pair<int, int> cmap[4][4];
	int ny = y, nx = x;

	if (ans < tot)
		ans = tot;

	// check of eaten fish
	map[y][x] = { -1, -1 };

	rotateFish(y, x);

	// save current map
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cmap[i][j] = map[i][j];
	
	// find next fish
	ny += dir[d].first, nx += dir[d].second;
	while (ny >= 0 && ny < 4 && nx >= 0 && nx < 4){
		// next dfs
		if (map[ny][nx].first != -1){
			dfs(ny, nx, map[ny][nx].second, tot + map[ny][nx].first);

			// restore current map
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					map[i][j] = cmap[i][j];
		}

		ny += dir[d].first, nx += dir[d].second;
	}

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			int a, b;
			cin >> a >> b;
			map[i][j] = { a, b - 1 };
		}
	}

	dfs(0, 0, map[0][0].second, map[0][0].first);

	cout << ans;

	return 0;
}
