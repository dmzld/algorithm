#include <iostream>
#include <queue>

using namespace std;

int N;
int map[20][20];
int S = 2, sy, sx, eat = 0; // shark size, position
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int ans = 0;

bool findFish(){ // bfs

	int cnt = 0; // distance from shark to edible fish
	bool check[20][20] = { false, };
	int fy = 20, fx = 20; // position of nearest edible fish
	bool find = false;
	queue<pair<int, int>> q;
	
	q.push({ sy, sx }); // from shark position
	check[sy][sx] = true;
	
	while (!q.empty()){ // find edible fish
		cnt++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= N || cx < 0 || cx >= N)
					continue;
				if (check[cy][cx] || map[cy][cx] > S) // already visited or bigger than shark
					continue;

				if (map[cy][cx] < S && map[cy][cx] > 0 && map[cy][cx] <= 6){ // if find edible fish
					find = true;
					// if same distance, uppermost & leftmost	
					if (fy > cy || (fy == cy && fx > cx))
						fy = cy, fx = cx;
				}
				else if (map[cy][cx] == S || map[cy][cx] == 0){ // just go through (can't eat)
					q.push({ cy, cx });
					check[cy][cx] = true;
				}
			}
		}
		if (find){
			map[sy][sx] = 0; //move
			map[fy][fx] = 9;
			sy = fy, sx = fx;

			eat++; //eat
			if (eat == S){
				eat = 0;
				S++;
			}

			ans += cnt; // time++
			return true;
		}
	}

	return false; // if couldn't eat
}

int main(){

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 9){
				sy = i;
				sx = j;
			}
		}

	while (1){
		if (!findFish())
			break;
	}


	cout << ans;

	return 0;
}
