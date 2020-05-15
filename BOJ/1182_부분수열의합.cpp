#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> E;
int res = 0;

void solution(int cnt, int cur_sum, bool least){ // least == meaning that sequence consist of 1 element at least
	if (cnt >= N){
		if (cur_sum == S && least)
			res++;
		return;
	}
	solution(cnt + 1, cur_sum + E[cnt], true);
	solution(cnt + 1, cur_sum, least);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	E.resize(N);
	for (int i = 0; i < N; i++){
		int e = 0;
		cin >> e;
		E[i] = e;
	}
	solution(0, 0, false);
	cout << res;

	return 0;
}
