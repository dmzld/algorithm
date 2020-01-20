#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int R, C;
char map[50][50];
int visited[50][50];

queue< pair<int, int> > p;
queue< pair<int, int> > w;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(){
	
	while (!p.empty()){
		int ws = w.size();
		int ps = p.size();

		// flooding
		for (int i = 0; i < ws; i++){
			int y = w.front().first;
			int x = w.front().second;
			w.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= R || cx < 0 || cx >= C)
					continue;
				if (map[cy][cx] != '.')
					continue;

				map[cy][cx] = '*';
				w.push(make_pair(cy, cx));
			}
		}

		// moving
		for (int i = 0; i < ps; i++){
			int y = p.front().first;
			int x = p.front().second;
			p.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= R || cx < 0 || cx >= C)
					continue;
				
				if (map[cy][cx] == 'D'){
					return visited[y][x] + 1;
				}
				else if (map[cy][cx] == '.' && !visited[cy][cx]){
					visited[cy][cx] = visited[y][x] + 1;
					p.push(make_pair(cy, cx));
				}

			}
		}
	}

	return -1;
}

int main(){
	int res = 0;

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
			if (map[i][j] == 'S'){
				visited[i][j] = 0;
				map[i][j] = '.';
				p.push(make_pair(i, j));
			}
			if (map[i][j] == '*'){
				w.push(make_pair(i, j));
			}
		}
	}

	res = solution();

	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res;

}
