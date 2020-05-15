#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int N, K, map[13][13];
vector<int> v[13][13];
bool check[11][13][13] = { false, };
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
struct State{
	int r;
	int c;
	int dir;
};
State h[11];
int ans = 0;

bool isOver(){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			if (v[i][j].size()>=4)
				return true;
		}
	return false;
}

int getPos(int num, int r, int c){
	for (int i = 0; i < v[r][c].size(); i++)
		if (v[r][c][i] == num)
			return i;
}

void moveHorse(int num, int r, int c, int d, int pos){
	int nr = r + dir[d].first, // next r, c
		nc = c + dir[d].second;

	// cout << r << c << " to " << nr << nc << "\n";

	// out of range OR blue
	if (nr<1 || nr>N || nc<1 || nc>N || map[nr][nc] == 2){

		h[num].dir += (d % 2 == 0 )? 1 : -1; // reverse h[num].dir
		nr = r + dir[h[num].dir].first; // update next r,c
		nc = c + dir[h[num].dir].second;

		// check color of next block one more
    // ** it can be 3 color, too !!
		if (nr<1 || nr>N || nc<1 || nc>N || map[nr][nc] == 2)
			return;
		else if (map[nr][nc] == 1){
			for (int i = v[r][c].size() - 1; i >= pos; i--){
				h[v[r][c][i]].r = nr, h[v[r][c][i]].c = nc;
				v[nr][nc].push_back(v[r][c][i]);
			}
			v[r][c].erase(v[r][c].begin() + pos, v[r][c].end());
		}
		else if (map[nr][nc] == 0){
			for (int i = pos; i < v[r][c].size(); i++){
				h[v[r][c][i]].r = nr, h[v[r][c][i]].c = nc;
				v[nr][nc].push_back(v[r][c][i]);
			}
			v[r][c].erase(v[r][c].begin() + pos, v[r][c].end());
		}
	}

	// red
	else if (map[nr][nc] == 1){
		for (int i = v[r][c].size() - 1; i >= pos; i--){ // stack reversely
			h[v[r][c][i]].r = nr, h[v[r][c][i]].c = nc;
			v[nr][nc].push_back(v[r][c][i]);
		}
		v[r][c].erase(v[r][c].begin() + pos, v[r][c].end());
	}

	// white
	else if (map[nr][nc] == 0){
		for (int i = pos; i < v[r][c].size(); i++){ // stack
			h[v[r][c][i]].r = nr, h[v[r][c][i]].c = nc;
			v[nr][nc].push_back(v[r][c][i]);
		}
		v[r][c].erase(v[r][c].begin() + pos, v[r][c].end());
	}
}

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j]; // 0 : white, 1 : red, 2 : blue

	for (int i = 1; i <= K; i++){
		int r, c, d;
		cin >> r >> c >> d;
		h[i] = { r, c, d - 1 };
		v[r][c].push_back(i);
	}

	while (ans <= 1000){
		if (isOver())
			break;
		ans++;

		for (int i = 1; i <= K; i++){ // each horse
			moveHorse(i, h[i].r, h[i].c, h[i].dir, getPos(i, h[i].r, h[i].c)); // num, r, c, dir, pos of stack
			if (isOver())
				break;
		}
	}

	if (ans > 1000)
		cout << -1;
	else
		cout << ans;

	return 0;
}
