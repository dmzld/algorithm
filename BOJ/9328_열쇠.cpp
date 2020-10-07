#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int T, H, W;
char map[100][100];
bool check[100][100];
string fk;
bool key[26];
pair<int, int> dir[4] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
queue<pair<int, int>> q;

queue<pair<int, int>> startPoint(){
	queue<pair<int, int>> sq;
	char c;

	for (int i = 0; i < H; i++){
		c = map[i][0];
		if ((c >= 'A' && c <= 'Z' && !key[(int)(c - 'A')]) || c == '*')
			continue;

		if (c >= 'a' && c <= 'z')
			key[c - 'a'] = true;

		sq.push({ i, 0 });
		check[i][0] = true;
	}

	for (int i = 0; i < H; i++){
		c = map[i][W - 1];
		if ((c >= 'A' && c <= 'Z' && !key[(int)(c - 'A')]) || c == '*')
			continue;

		if (c >= 'a' && c <= 'z')
			key[c - 'a'] = true;

		sq.push({ i, W - 1 });
		check[i][W - 1] = true;
	}

	for (int i = 1; i < W - 1; i++){
		c = map[0][i];
		if ((c >= 'A' && c <= 'Z' && !key[(int)(c - 'A')]) || c == '*')
			continue;

		if (c >= 'a' && c <= 'z')
			key[c - 'a'] = true;

		sq.push({ 0, i });
		check[0][i] = true;
	}

	for (int i = 1; i < W - 1; i++){
		c = map[H - 1][i];
		if ((c >= 'A' && c <= 'Z' && !key[(int)(c - 'A')]) || c == '*')
			continue;

		if (c >= 'a' && c <= 'z')
			key[c - 'a'] = true;

		sq.push({ H - 1, i });
		check[H - 1][i] = true;
	}

	return sq;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	for (int t = 0; t < T; t++){
		int ans = 0;
		memset(key, false, sizeof(key));
		
		cin >> H >> W;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> map[i][j];
			}
		}
		cin >> fk;
		for (int i = 0; i < fk.length(); i++)
			key[fk[i] - 'a'] = true;
		

		// search
		int cnt = 0, ccnt = 1;
		while (cnt != ccnt){ // 이전에 탐색 가능했던 범위 크기 != 새로 탐색했을 때 범위 크기
			memset(check, false, sizeof(check));
			q = startPoint(); // 새로운 key 조건에서 start point 초기화, sAns 초기화
			int res = 0; // 찾은 서류 개수

			cnt = ccnt;
			ccnt = q.size();

			// bfs
			while (!q.empty()){
				int y = q.front().first, x = q.front().second;
				q.pop();

				if (map[y][x] == '$') // 서류 찾았으면 ans++
					res++;
				
				for (int i = 0; i < 4; i++){
					int ny = y + dir[i].first, nx = x + dir[i].second;

					if (ny < 0 || ny >= H || nx < 0 || nx >= W || check[ny][nx] || map[ny][nx] == '*') // 범위밖, 이미 방문, 벽
						continue;

					if ((map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') && !key[(int)(map[ny][nx] - 'A')]) // 문인데 열쇠X
						continue;

					if ((map[ny][nx] >= 'a' && map[ny][nx] <= 'z')) // 찾은열쇠저장
						key[(int)(map[ny][nx] - 'a')] = true;

					q.push({ ny, nx });
					check[ny][nx] = true;
					ccnt++;
				}
			}

			ans = max(ans, res);
		}

		cout << ans << "\n";
	}

	return 0;
}
