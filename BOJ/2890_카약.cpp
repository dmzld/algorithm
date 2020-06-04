#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
char map[50][50];
vector<pair<int, int>> d; // <distance, team>
int ans[10];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++){
		for (int j = C - 1; j >= 0; j--){
			if (map[i][j] >= '1' && map[i][j] <= '9'){
				d.push_back({ R - j, (int)(map[i][j] - '0') });
				break;
			}
		}
	}
	

	sort(d.begin(), d.end());

	int r = 1;
	ans[d[0].second] = r;
	for (int i = 1; i < d.size(); i++){
		if (d[i - 1].first == d[i].first)
			ans[d[i].second] = r;
		else
			ans[d[i].second] = ++r;
	}

	for (int i = 1; i <= 9; i++)
		cout << ans[i] << "\n";

	return 0;
}
