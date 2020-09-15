#include <iostream>
#include <cstring>

using namespace std;

int T;
int D, W, K;
int map[13][20];
bool check[13];
int ans = 0;

bool verification(){
	for (int j = 0; j < W; j++){
		int cnt = 1;
		for (int i = 1; i < D; i++){
			if (map[i - 1][j] == map[i][j])
				cnt++;
			else
				cnt = 1;

			if (cnt >= K)
				break;
		}
		if (cnt < K)
			return false;
	}

	return true;
}

void dfs(int idx, int cnt){
	if (ans <= cnt)
		return;

	// 바꾸기 전 현 상태 저장
	int tmp[20];
	for (int j = 0; j < W; j++)
		tmp[j] = map[idx][j];

	// 1로 바꿨을 때
	for (int i = 0; i < W; i++)
		map[idx][i] = 1;
	if (verification()){
		if (ans > cnt)
			ans = cnt;
		// 원상복구
		for (int j = 0; j < W; j++)
			map[idx][j] = tmp[j];
		return;

	}
	else
		for (int i = idx + 1; i < D; i++){
			if (!check[i]){
				check[i] = true;
				dfs(i, cnt + 1);
				check[i] = false;
			}
		}

	if (ans <= cnt)
		return;

	// 0으로 바꿨을 떄
	for (int i = 0; i < W; i++)
		map[idx][i] = 0;
	if (verification()){
		if (ans > cnt)
			ans = cnt;
		// 원상복구
		for (int j = 0; j < W; j++)
			map[idx][j] = tmp[j];
		return;
	}
	else
		for (int i = idx + 1; i < D; i++){
			if (!check[i]){
				check[i] = true;
				dfs(i, cnt + 1);
				check[i] = false;
			}
		}

	// 원상복구
	for (int j = 0; j < W; j++)
		map[idx][j] = tmp[j];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		ans = 14;
		memset(check, false, sizeof(check));

		if (verification()){
			cout << "#" << t << " " << 0 << "\n";
			continue;
		}

		for (int i = 0; i < D; i++){
			check[i] = true;
			dfs(i, 1);
			check[i] = false;
		}


		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
