#include <iostream>
#include <queue>

using namespace std;
int K, S[49], res[6] = { 0, };

void dfs(int idx, int cnt){ // idx == cur idx of S, cnt == # of selected num
	if (cnt >= 6){
		for (int i = 0; i < 6; i++){
			cout << res[i] << " ";
		} cout << "\n";
		
		return;
	}


	for (int i = idx; i < K; i++){
		res[cnt] = S[i];
		dfs(i + 1, cnt + 1); 
	}
	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (1){
		cin >> K;
		if (K == 0) break;

		for (int i = 0; i < K; i++)
			cin >> S[i];

		dfs(0, 0);
		cout << "\n";
	}

	return 0;
}
