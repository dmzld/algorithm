#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T;
int N, K; // <= 10^4, <= 10^3
int cam[10000], dis[10001]; // input, distance between camera
bool check[1000001];
int ans;

bool cmp(int a, int b){
	return a > b;
}

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++){

		cin >> N >> K;
		memset(check, false, sizeof(check));
		ans = 0;

		for (int i = 0; i < N; i++){
			cin >> cam[i];
		}
		sort(cam, cam + N);
		
		int cnt = 0; // # of range of road
		for (int i = 0; i < N - 1; i++){
			if (cam[i + 1] != cam[i]){
				dis[cnt++] = cam[i + 1] - cam[i];
			}
		}

		sort(dis, dis + cnt);

		if (cnt > K){
			for (int i = 0; i < cnt - (K - 1); i++) // no needs for surveillance as many as the K - 1 longest 
				ans += dis[i];
		}

		cout << "#" << tc << " " << ans << "\n";
		
	}


	return 0;
}
