#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int INF = 987654321;

int L, R, C; // 층, 행, 열
char B[30][30][30];
int dl[6] = { 0, 0, 0, 0, -1, 1 };
int dr[6] = { 0, 0, -1, 1, 0, 0 };
int dc[6] = { -1, 1, 0, 0, 0, 0 };

struct Pos {
	int l;
	int r;
	int c;
};

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1){
		bool check[30][30][30] = { false };
		queue<Pos> q; // per 1 step
		int cnt = 0;
		bool escape = false;

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;

		memset(check, false, sizeof(check));
		for (int i = 0; i < L; i++){
			for (int j = 0; j < R; j++){
				for (int k = 0; k < C; k++){
					cin >> B[i][j][k];
					if (B[i][j][k] == 'S'){
						q.push({ i, j, k });
						check[i][j][k] = true;
					}
				}
			}
		}

		while (!q.empty()){
			cnt++;
			int qSize = q.size(); // per a minute
			for (int i = 0; i < qSize; i++){

				// cur position
				int l = q.front().l;
				int r = q.front().r;
				int c = q.front().c;
				q.pop();

				for (int j = 0; j < 6; j++){
					int cl = l + dl[j];
					int cr = r + dr[j];
					int cc = c + dc[j];

					if (cl < 0 || cl >= L || cr < 0 || cr >= R || cc < 0 || cc >= C)
						continue;
					if (B[cl][cr][cc] == '#' || check[cl][cr][cc])
						continue;

					// first exit
					if (B[cl][cr][cc] == 'E'){
						escape = true;
						break;
					}
					else if (B[cl][cr][cc] == '.'){
						q.push({ cl, cr, cc });
						check[cl][cr][cc] = true;
					}
				}
				if (escape)
					break;
			}
			if (escape)
				break;
		}

		if (escape)
			cout << "Escaped in " << cnt << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}

	return 0;
}
