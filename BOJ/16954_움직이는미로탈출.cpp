#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct pos{
	int y, x;
};

char map[8][8];
queue<pos> q;
pos dir[8] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> map[i][j];
	
	q.push({ 7, 0 });
	while (!q.empty()){
		bool check[8][8] = { false, };
		int qSize = q.size();

		for (int i = 0; i < qSize; i++){
			int y = q.front().y, x = q.front().x;
			q.pop();

			if (map[y][x] == '#')
				continue;

			q.push({ y, x });
			check[y][x] = true;

			for (int i = 0; i < 8; i++){
				int ny = y + dir[i].y, nx = x + dir[i].x;

				if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8 || check[ny][nx] || map[ny][nx] == '#')
					continue;

				if (ny == 0 && nx == 7){
					cout << 1;
					return 0;
				}

				q.push({ ny, nx });
				check[ny][nx] = true;
			}
		}

		for (int i = 7; i > 0; i--)
			for (int j = 0; j < 8; j++)
				map[i][j] = map[i - 1][j];
		for (int j = 0; j < 8; j++)
			map[0][j] = '.';
	}

	cout << "0";
	return 0;
}
