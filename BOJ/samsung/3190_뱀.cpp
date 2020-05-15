#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
bool apple[101][101]; // 1 ~ 100
bool body[101][101];
char O[10001];
pair<int, int> direction[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int main(){

	cin >> N >> K;
	for (int i = 0; i < K; i++){
		int y, x;
		cin >> y >> x;
		apple[y][x] = true;
	}

	cin >> L;
	for (int i = 0; i < L; i++){
		int t;
		char d;
		cin >> t >> d;
		O[t] = d;
	}

	int cDir = 0; // is idx of direction
	queue<pair<int, int>> pos; // for head, tail
	pos.push({ 1, 1 }); // first position
	body[1][1] = true;

	int i = 0;
	while(1){
		i++;
		// head to next position
		int ny = pos.back().first + direction[cDir].first;
		int nx = pos.back().second + direction[cDir].second;

		if (ny <= 0 || ny > N || nx <= 0 || nx > N){ // out of range ( 1 ~ N )
			cout << i;
			return 0;
		}
		if (body[ny][nx]){ // meet own body
			cout << i;
			return 0;
		}

		if (apple[ny][nx]){ // eat apple, not shorten
			apple[ny][nx] = false;
		}
		else{ // no apple, shorten
			body[pos.front().first][pos.front().second] = false;
			pos.pop();
		}
		pos.push({ ny, nx }); // add head's position
		body[ny][nx] = true;



		// after particular time, change dir
		if (i <= 10000){
			if (O[i] == 'D'){ // right
				cDir = (cDir + 1) % 4;
			}
			else if (O[i] == 'L'){ // left
				cDir = (cDir + 3) % 4;
			}
		}

	}

	return 0;
}
