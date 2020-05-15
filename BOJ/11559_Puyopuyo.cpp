#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

char map[12][6];
int visited[12][6];
char buf[8];
int cnt = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void initMap(){
	for (int i = 0; i < 12; i++){
		scanf("%s", buf);
		for (int j = 0; j < 6; j++){
			map[i][j] = buf[j];
		}
	}
}

void showMap(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			printf("%c ", map[i][j]);
		}printf("\n");
	}printf("\n");
}

void initVisited(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++)
			visited[i][j] = 0;
	}
}

void fillMap(){
	for (int i = 0; i < 6; i++){
		for (int j = 11; j >= 0; j--){
			if (map[j][i] == '.'){
				int fill = j;
				for (int k = j; k >= 0; k--){
					if (map[k][i] != '.'){
						map[fill][i] = map[k][i];
						map[k][i] = '.';
						fill--;
					}
				}
			}
		}
	}
}

bool pangMap(bool isPang){
	// 탐색, 회당 cnt++
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){

			// Puyo찾기
			if (map[i][j] != '.') { // RGBPY
				char color = map[i][j];
				queue< pair<int, int> > q; // 탐색할 좌표
				queue< pair<int, int> > q2; // 터뜨릴 좌표
				initVisited();

				q.push(make_pair(i, j)); // y, x
				visited[i][j] = 1;
				q2.push(make_pair(i, j));

				// 이번 좌표 기준으로 인접,같은색 Puyo 모으기
				while (!q.empty()){
					int x = q.front().second;
					int y = q.front().first;
					q.pop();

					for (int k = 0; k < 4; k++){
						int cx = x + dx[k];
						int cy = y + dy[k];

						if (cx < 0 || cx >= 6 || cy < 0 || cy >= 12)
							continue;
						if (map[cy][cx] != color || visited[cy][cx])
							continue;

						q.push(make_pair(cy, cx));
						visited[cy][cx] = 1;
						q2.push(make_pair(cy, cx));
					}
				}
				// 터뜨리기
				if (q2.size() >= 4){
					isPang = true;
					while (!q2.empty()){
						map[q2.front().first][q2.front().second] = '.';
						q2.pop();
					}
				}
			}
		}
	}
	return isPang;
}

int func(){
	bool pang = true;

	initMap();

	while (pang){
		//showMap();
		pang = pangMap(false);
		if (pang){ // cnt++, map 채우기
			cnt++;
			fillMap();
		}
	}

	return cnt;
}

int main(){

	printf("%d", func());

	return 0;
}
