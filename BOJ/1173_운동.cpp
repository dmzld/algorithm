#include <iostream>

using namespace std;

int N, m, M, T, R; // 운동하는 시간, 첫 맥박, 최대 맥박, 운동 시 오르는 맥박, 휴식 시 떨어지는 맥박
int beat = 0, cnt = 0, ans = 0;

int main(){

	cin >> N >> m >> M >> T >> R;
	
	// can't training
	if (m + T > M){
		cout << -1;
		return 0;
	}
	
	beat = m;
	while (cnt < N){
		ans++;
		if (beat + T <= M){
			cnt++;
			beat += T;
		}
		else{
			beat -= R;
			if (beat < m)
				beat = m;
		}
	}

	cout << ans;

	return 0;
}
