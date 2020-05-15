#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int box[100][100][100];
bool check[100][100][100] = { false, };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { -1, 1, 0, 0, 0, 0 };
struct Pos{
	int z;
	int y;
	int x;
};
queue<Pos> q;
int ans = 0;
bool flag = false;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				cin >> box[i][j][k];
				if (box[i][j][k] == 1){
					q.push({ i, j, k });
					check[i][j][k] = true;
				}
				if (box[i][j][k] == 0)
					flag = true;
			}
		}
	}

	if (!flag){
		cout << 0;
		return 0;
	}

	while (!q.empty()){
		bool change = false;
		int qSize = q.size();
		
		for (int i = 0; i < qSize; i++){
			int z = q.front().z;
			int y = q.front().y;
			int x = q.front().x;
			q.pop();


			for (int j = 0; j < 6; j++){
				int cz = z + dz[j];
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cz < 0 || cz >= H || cy < 0 || cy >= N || cx < 0 || cx >= M)
					continue;
				if (check[cz][cy][cx] || box[cz][cy][cx] == 1 || box[cz][cy][cx] == -1)
					continue;

				box[cz][cy][cx] = 1;
				check[cz][cy][cx] = true;
				q.push({ cz, cy, cx });
				change = true;
			}
		}
		if (change)
			ans++;
	}

	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				if (box[i][j][k] == 0)
					flag = false;
			}
		}
	}

	if (flag)
		cout << ans;
	else
		cout << -1;

	return 0;
}
