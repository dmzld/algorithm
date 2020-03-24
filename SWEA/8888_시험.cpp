#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int TC, N, T, P;
int res[2000][2000], point[2000];
struct S{
	int tot;
	int cnt;
	int num;
};

bool cmp(S a, S b){
	if (a.tot == b.tot){
		if (a.cnt == b.cnt){
			return a.num < b.num;
		}
		return a.cnt > b.cnt;
	}
	return a.tot > b.tot;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++){
		cin >> N >> T >> P;

		memset(point, 0, 4 * T);
		vector<S> v(N);

		for (int i = 0; i < N; i++){
			for (int j = 0; j < T; j++){
				cin >> res[i][j];
				if (res[i][j] == 0) point[j]++;
			}
		}

		for (int i = 0; i < N; i++){
			v[i].num = i;
			for (int j = 0; j < T; j++){
				if (res[i][j] == 1){
					v[i].tot += point[j];
					v[i].cnt++;
				}
			}
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < N; i++){
			if (v[i].num == P - 1){
				cout << "#" << tc << " " << v[i].tot << " " << i + 1 << "\n";
			}
		}
	}

	return 0;
}
