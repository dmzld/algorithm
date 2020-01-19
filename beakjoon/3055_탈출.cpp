#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;


int R, S;
char map[50][50]; // . * X D S
bool visited[50][50];
queue<pair<int,int> > flooded;
queue<pair<int,int> > pos;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int res = 0;


void solution(){
	int cnt = 1;

	while (!pos.empty()){
		int fSize = flooded.size();
		int pSize = pos.size();
		
		// flooding
		for (int j = 0; j < fSize; j++){
			int y = flooded.front().first;
			int x = flooded.front().second;
			flooded.pop();

			for (int i = 0; i < 4; i++){
				int cy = y + dy[i];
				int cx = x + dx[i];

				if (cy < 0 || cy >= R || cx < 0 || cx >= S)
					continue;
				if (map[cy][cx] != '.')
					continue;

				map[cy][cx] = '*';
				flooded.push(make_pair(cy, cx));
			}
		}

		// move
		for (int j = 0; j < pSize; j++){
			int y = pos.front().first;
			int x = pos.front().second;
			pos.pop();

			for (int i = 0; i < 4; i++){
				int cy = y + dy[i];
				int cx = x + dx[i];

				if (cy < 0 || cy >= R || cx < 0 || cx >= S)
					continue;

				// arrive
				if (map[cy][cx] == 'D'){
					res = cnt;
					return;
				}
				// move to next position
				if (map[cy][cx] == '.' && !visited[cy][cx])
					visited[cy][cx] = true;
					pos.push(make_pair(cy, cx));
			}
		}
	
		cnt++;
	}
	
}

int main(){

	cin >> R >> S;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < S; j++){
			cin >> map[i][j];
			if (map[i][j] == 'S'){
				pos.push(make_pair(i, j));
				map[i][j] = '.';
			}
			if (map[i][j] == '*')
				flooded.push(make_pair(i, j));
		}
	}

	solution();

	if (res)
		cout << res;
	else
		cout << "KAKTUS";

	return 0;
}
