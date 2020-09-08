#include <iostream>
#include <algorithm>

using namespace std;

int N, M, map[50][50];
int res = 0, ans = 0;

void square(int y, int x){
	int len = min(N - y, M - x);
	for (int i = 1; i < len; i++)
		if (map[y][x] == map[y + i][x]
			&& map[y + i][x] == map[y][x + i]
			&& map[y][x + i] == map[y + i][x + i])
			ans = max(ans, (i + 1)*(i + 1));
}

int main(){

	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	//cin >> N >> M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);
	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			square(i, j);

	cout << ans;

	return 0;
}
