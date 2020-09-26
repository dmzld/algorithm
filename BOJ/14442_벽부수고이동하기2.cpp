#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

struct state{
	int y, x, k;
};
int N, M, K, map[1001][1001];
queue<state> q;
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
bool check[1001][1001] = { false, };
int rest[1001][1001] = { 0, };
int ans;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++){
		string a;
		cin >> a;
		for (int j = 1; j <= M; j++)
			map[i][j] = (int)(a[j - 1] - '0');
	}
    
	q.push({ 1, 1, K });
	check[1][1] = true;
	rest[1][1] = K;
	ans = 1;

	while (!q.empty()){
		int qSize = q.size();

		for (int j = 0; j < qSize; j++){
			int y = q.front().y, x = q.front().x,
				k = q.front().k;
			q.pop();
            
            if (y == N && x == M){
					cout << ans;
					return 0;
				}

			for (int i = 0; i < 4; i++){
				int ny = y + dir[i].first, nx = x + dir[i].second,
					nk = k;

				if (ny<1 || ny>N || nx<1 || nx>M)
					continue;
				
				if (map[ny][nx] == 1)
					nk--;

				if (nk < 0 || (check[ny][nx] && nk <= rest[ny][nx]))
					continue;

				q.push({ ny, nx, nk });
				check[ny][nx] = true;
				rest[ny][nx] = nk;
			}
		}
        ans++;
	}


	cout << -1;

	return 0;
}
