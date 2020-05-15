#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int N, L, R;
int A[50][50];
bool check[50][50] = { false, };
pair<int, int> dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int p = 0;
vector<pair<int, int>> n;
int ans = 0;

void makeUnion(int y, int x){
	for (int i = 0; i < 4; i++){
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (check[ny][nx] || abs(A[y][x] - A[ny][nx]) < L || abs(A[y][x] - A[ny][nx]) > R)
			continue;

		p += A[ny][nx];
		n.push_back({ ny, nx });
		check[ny][nx] = true;
		makeUnion(ny, nx);
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	while (1){
		int num = 0; // # of union
		memset(check, false, sizeof(check));
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (!check[i][j]){
					num++;

					n.push_back({ i, j });
					check[i][j] = true;
					p += A[i][j];
					makeUnion(i, j);					
					
					if (n.size() > 1)
						for (int k = 0; k < n.size(); k++) // move
							A[n[k].first][n[k].second] = p / n.size();
					
						
					p = 0; // reinit
					n.clear();
				}
			}
		}

		if (num == N*N)
			break;
		else
			ans++;
	}

	cout << ans;

	return 0;
}
