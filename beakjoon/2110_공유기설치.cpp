#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, ans = 0;
vector<int> pos;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> C;
	pos.resize(N);
	for (int i = 0; i < N; i++)
		cin >> pos[i];

	sort(pos.begin(), pos.end());

	int s = 1, e = pos[N - 1] - pos[0];
	
	while (s <= e){
		int pre = 0, // last position of installation
			cnt = 1, // installable 
			d = (s + e) / 2; // distance(interval)

		for (int i = 1; i < N; i++){
			if (pos[i] - pos[pre] >= d){ // if installable
				cnt++;
				pre = i;
			}
		}

		if (cnt < C){
			e = d - 1; // reduce distance
		}
		else{
			if (ans < d)
				ans = d;
			s = d + 1; // increase distance
		}

	}

	cout << ans;

	return 0;
}
