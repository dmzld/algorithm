#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int N, K;
int M[101] = { 0, }, O[101]; // multitap, order
int res = 0, ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= K; i++){
		cin >> O[i];
	}

	if (N >= K) // if multitap hole > order
		cout << 0;
	else{
		for (int i = 1; i <= K; i++){ // O

			// find dup pluged
			bool dup = false;
			for (int j = 1; j <= N; j++){
				if (M[j] == O[i]){
					dup = true;
					break;
				}
			}
			if (dup)
				continue;

			// find empty hole
			int emptyIdx = 0;
			for (int j = 1; j <= N; j++){
				if (!M[j]){ // not pluged
					emptyIdx = j;
					break;
				}
			}
			if (emptyIdx){
				M[emptyIdx] = O[i];
				continue;
			}
			// find pluged device that will be pluged again lastest or not be used
			else{ 
				int orderCnt = -1, plugedIdx = 0;
				for (int j = 1; j <= N; j++){ // M
					int cnt = 0;
					for (int k = i + 1; k <= K; k++){ // rest O
						if (M[j] == O[k])
							break;
						cnt++;
					}

					if (orderCnt < cnt){
						orderCnt = cnt;
						plugedIdx = j;
					}
				}

				M[plugedIdx] = O[i];
				ans++;
			}
		}
		cout << ans;
	}


	return 0;
}
