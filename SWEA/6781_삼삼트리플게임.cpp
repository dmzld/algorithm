#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	
	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		int cnt = 0;
		string cn, cc;
		int card[3][10] = { 0, };

		cin >> cn >> cc;

		for (int i = 0; i < 9; i++){
			if (cc[i] == 'R'){
				card[0][cn[i] - '0']++;
			}
			else if (cc[i] == 'G'){
				card[1][cn[i] - '0']++;
			}
			else if (cc[i] == 'B'){
				card[2][cn[i] - '0']++;
			}
		}

		// in same color
		for (int i = 0; i < 3; i++){
			// continued num
			for (int j = 1; j <= 7; j++){
				if (card[i][j] > 0 && card[i][j + 1] > 0 && card[i][j + 2] > 0){
					cnt++;
					card[i][j]--;
					card[i][j + 1]--;
					card[i][j + 2]--;
					j--; // point : there is possibility that same condition sets are remain
				}
			}
			// same num
			for (int j = 1; j <= 9; j++){
				if (card[i][j] >= 3){
					cnt++;
					card[i][j] -= 3;
					j--; // point : there is possibility that same condition sets are remain
				}
			}
		}
		

		if (cnt >= 3)
			cout << "#" << tc << " Win\n";
		else
			cout << "#" << tc << " Continue\n";

	}

	return 0;
}
