#include <iostream>
#include <queue>

using namespace std;

int N, M, A, B, K;
bool map[501][501] = { false, };
bool check[501][501] = { false, };
pair<int, int> S, D;
queue<pair<int, int>> q;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

bool canPass(int y, int x){
	for (int i = y; i < y + A; i++){
		for (int j = x; j < x + B; j++){	
			if (i > N || j > M || map[i][j])
				return false;
		}
	}
	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++){
		int y, x;
		cin >> y >> x;
		map[y][x] = true;
	}
	cin >> S.first >> S.second >> D.first >> D.second;

	q.push({ S.first, S.second });
	check[S.first][S.second] = true;
	int cnt = 0;
	while (!q.empty()){
		cnt++;
		int qSize = q.size();

		for (int i = 0; i < qSize; i++){
			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j], cx = x + dx[j];

				if (cy <= 0 || cy > N || cx <= 0 || cx > M)
					continue;
				if (check[cy][cx] || !canPass(cy, cx))
					continue;

				if (cy == D.first && cx == D.second){ // arrive
					cout << cnt;
					return 0;
				}

				q.push({ cy, cx });
				check[cy][cx] = true;
			}
		}
	}

	cout << -1;

	return 0;
}
