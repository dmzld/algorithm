#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T;
int D, M, TM, Y;
int plan[12];
int cnt, ans;

void init(){
	cin >> D >> M >> TM >> Y;
	for (int i = 0; i < 12; i++)
		cin >> plan[i];
	ans = 0;
}

void dfs(int m, int tot){
	if (ans < tot)
		return;

	if (m >= 12){
		ans = min(ans, tot);
		return;
	}

	// 하루
	dfs(m + 1, tot + D * plan[m]);
	// 한달
	dfs(m + 1, tot + M);
	// 세달
	dfs(m + 3, tot + TM);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		init();

		for (int i = 0; i < 12; i++)
			ans += plan[i];
		if (ans == 0){
			cout << "#" << t << " " << ans << "\n";
			continue;
		}
		else
			ans = Y; // 일년

		dfs(0, 0);

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
