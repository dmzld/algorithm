#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char map[501][501];
bool check[501][501][4]; // income dir
pair<int, int> p;
int dy[4] = { -1, 0, 1, 0 }; // 북 동 남 서
int dx[4] = { 0, 1, 0, -1 };
char aDir;
int ans = 0;

void save(int d){
	switch (d){
	case 0:
		aDir = 'U';
		break;
	case 1:
		aDir = 'R';
		break;
	case 2:
		aDir = 'D';
		break;
	case 3:
		aDir = 'L';
		break;
	}
	return;
}

void solution(int d){
	memset(check, false, sizeof(check));
	int dir = d;
	int y = p.first, x = p.second;
	int t = 0;

	while (1){
		t++;
		y += dy[dir], x += dx[dir];

		if (y <= 0 || y > N || x <= 0 || x > M || map[y][x] == 'C'){ // signal is eliminated
			if (ans < t){
				ans = t;
				save(d);
			}
			return;
		}

		if (check[y][x][dir]){ // infinite loop
			save(dir);
			cout << aDir << "\nVoyager\n";
			exit(0);
		}

		check[y][x][dir] = true;

		if (map[y][x] == '/'){
			if (dir % 2 == 0)
				dir++;
			else
				dir--;
		}
		else if (map[y][x] == '\\'){
			dir = 3 - dir;
		}
		else if (map[y][x] == '.'){
			// nothing
		}

	}
}

int main(){

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M;j++)
			cin >> map[i][j];
	cin >> p.first >> p.second;

	for (int i = 0; i < 4; i++){
		solution(i);
	}

	cout << aDir << "\n" << ans << "\n";

	return 0;
}
