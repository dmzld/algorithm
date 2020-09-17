#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct state {
	int y, x, d, m;
};

int T;
int R, C;
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
char map[20][20];
bool check[20][20][4][16]; // for dup state check [y][x][dir][m]

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> map[i][j];

		memset(check, false, sizeof(check));
		bool end = false;

		queue<state> q;
		q.push({ 0, 0, 0, 0 });
		check[0][0][0][0] = true;
		
		
		while (!q.empty() && !end){
			int y = q.front().y, x = q.front().x,
				cDir = q.front().d, cM = q.front().m;
			char val = map[y][x];
			q.pop();

			if (val == '<'){
				cDir = 1;
			}
			else if (val == '>'){
				cDir = 0;
			}
			else if (val == '^'){
				cDir = 3;
			}
			else if (val == 'v'){
				cDir = 2;
			}
			else if (val == '_'){
				if (cM == 0)
					cDir = 0;
				else
					cDir = 1;
			}
			else if (val == '|'){
				if (cM == 0)
					cDir = 2;
				else
					cDir = 3;
			}
			else if (val == '?'){
				for (int i = 0; i < 4; i++){
					int ny = y + dir[i].first, nx = x + dir[i].second;
					
					if (ny < 0)
						ny = R - 1;
					else if (ny >= R)
						ny = 0;
					else if (nx < 0)
						nx = C - 1;
					else if (nx >= C)
						nx = 0;

					if (!check[ny][nx][i][cM]){
						check[ny][nx][i][cM] = true;
						q.push({ ny, nx, i, cM });
					}
				}
				continue;
			}
			else if (val == '.'){
				// do not anything
			}
			else if (val == '@'){
				end = true;
				break;
			}
			else if (val == '+'){
				cM++;
				if (cM > 15) cM = 0;
			}
			else if (val == '-'){
				cM--;
				if (cM < 0) cM = 15;
			}
			else if (val >= '0' && val <= '9')
				cM = (int)(map[y][x] - '0');


			int ny = y + dir[cDir].first, nx = x + dir[cDir].second;
			if (ny < 0)
				ny = R - 1;
			else if (ny >= R)
				ny = 0;
			else if (nx < 0)
				nx = C - 1;
			else if (nx >= C)
				nx = 0;

			if (!check[ny][nx][cDir][cM]){
				check[ny][nx][cDir][cM] = true;
				q.push({ ny, nx, cDir, cM });
			}
		}

		if (end)
			cout << "#" << t << " YES" << "\n";
		else
			cout << "#" << t << " NO" << "\n";

	}


	return 0;
}
