#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, W, H;
char map[1000][1000];
bool check[1000][1000];
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++){
		memset(check, false, sizeof(check));
		queue<pair<int, int>> fire;
		queue<pair<int, int>> q;
		int ans = 0;
		bool fin = false;

		cin >> W >> H;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> map[i][j];
				if (map[i][j] == '*')
					fire.push({ i, j });
				else if (map[i][j] == '@'){
					q.push({ i, j });
					check[i][j] == true;
					map[i][j] = '.';
				}
			}
		}
		while (!q.empty() && !fin){
			ans++;

			// fire spread
			int fSize = fire.size();
			for (int i = 0; i < fSize; i++){
				int y = fire.front().first, x = fire.front().second;
				fire.pop();

				for (int j = 0; j < 4; j++){
					int ny = y + dir[j].first, nx = x + dir[j].second;

					if (ny < 0 || ny >= H || nx < 0 || nx >= W || map[ny][nx] == '*' || map[ny][nx] == '#')
						continue;

					map[ny][nx] = '*';
					fire.push({ ny, nx });
				}
			}

			// move
			int qSize = q.size();
			for (int i = 0; i < qSize; i++){
				int y = q.front().first, x = q.front().second;
				q.pop();

				for (int j = 0; j < 4; j++){
					int ny = y + dir[j].first, nx = x + dir[j].second;

					if (ny < 0 || ny >= H || nx < 0 || nx >= W){
						// exit
						cout << ans << "\n";
						fin = true;
						break;
					}

					if (map[ny][nx] == '*' || map[ny][nx] == '#' || check[ny][nx])
						continue;

					q.push({ ny, nx });
					check[ny][nx] = true;
				}
				if (fin)
					break;
			}
		}

		if (!fin)
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}
