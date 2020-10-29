#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int H, W, map[500], ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> H >> W;
	for (int i = 0; i < W; i++)
		cin >> map[i];

	for (int i = 1; i < W - 1; i++){
		int rh = map[i - 1], lh = map[i + 1], fh;

		for (int j = i - 1; j >= 0; j--){
			rh = max(rh, map[j]);
		}
		for (int j = i + 1; j < W; j++){
			lh = max(lh, map[j]);
		}

		fh = min(rh, lh);

		if (fh > map[i])
			ans += fh - map[i];
	}

	cout << ans;

	return 0;
}
