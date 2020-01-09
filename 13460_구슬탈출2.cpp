#include <iostream>
#include <cmath>

using namespace std;

int N, M; // . # O R B
char B[10][10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool E = false;
int res = 987654321;

void solution(int cnt, int ry, int rx, int by, int bx);
void rolling(int cnt, int ry, int rx, int by, int bx, int dx, int dy);

void rolling(int cnt, int ry, int rx, int by, int bx, int dx, int dy){
	int cry = ry, crx = rx, cby = by, cbx = bx;
	bool exitR = false, exitB = false;

	while (1){
		cry += dy;
		crx += dx;
		if (B[cry][crx] == '#'){
			cry -= dy;
			crx -= dx;
			break;
		}
		else if (B[cry][crx] == 'O'){
			exitR = true;
			break;
		}
	}
	while (1){
		cby += dy;
		cbx += dx;
		if (B[cby][cbx] == '#'){
			cby -= dy;
			cbx -= dx;
			break;
		}
		else if (B[cby][cbx] == 'O'){
			exitB = true;
			break;
		}
	}
	// R과 B가 겹쳤을 때
	if (cry == cby && crx == cbx){
		if (abs(cry - ry) > abs(cby - by)){
			cry -= dy;
		}
		else{
			cby -= dy;
		}
		if (abs(crx - rx) > abs(cbx - bx)){
			crx -= dx;
		}
		else{
			cbx -= dx;
		}
	}

	// B가 빠져나간 경우 무조건 잘못된 경우이므로 먼저 검사
	if (exitB)
		return;
	if (exitR){
		E = true;
		if (res > cnt)
			res = cnt;
		return;
	}
	solution(cnt + 1, cry, crx, cby, cbx);
}

void solution(int cnt, int ry, int rx, int by, int bx){
	if (cnt > res)
		return;
	if (cnt > 10)
		return;

	for (int i = 0; i < 4; i++){
		rolling(cnt, ry, rx, by, bx, dx[i], dy[i]);
	}
}

int main(){
	int rx, ry;
	int bx, by;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> B[i][j]; // . # O R B
			if (B[i][j] == 'R'){
				rx = j;
				ry = i;
			}
			if (B[i][j] == 'B'){
				bx = j;
				by = i;
			}
		}
	}

	solution(1, ry, rx, by, bx);

	if (E)
		cout << res;
	else
		cout << -1;
}
