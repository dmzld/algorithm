#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[100][100];
bool check[100][100];
int max_height;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int res = 0;


void dfs(int y, int x, int h){
	for (int i = 0; i < 4; i++){
		int cy = y + dy[i];
		int cx = x + dx[i];
		
		if (cy < 0 || cx < 0 || cy >= N || cx >= N)
			continue;
		if (map[cy][cx] <= h || check[cy][cx])
			continue;

		check[cy][cx] = true;
		dfs(cy, cx, h);
	}
}

void solution(int h){
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] > h && !check[i][j]){
				cnt++;
				check[i][j] = true;
				dfs(i, j, h);
			}
		}
	}
	
	if (res < cnt)
		res = cnt;
}

int main(){

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (max_height < map[i][j])
				max_height = map[i][j];
		}
	}

	for (int i = 0; i <= max_height; i++){
		memset(check, false, sizeof(check));
		solution(i);
	}

	cout << res;

	return 0;
}
