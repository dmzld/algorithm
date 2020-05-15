#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N, S[21][21] = { 0, }, team[21];
int ans = 987654321;

void solution(int A, int B, int n){
	if (n > N){ // every people have team
		int gap = 0; // gap between 2 teams

		for (int i = 1; i <= N; i++){ // i player and
			int t = team[i], tot = 0;
			for (int j = 1; j <= N; j++){ // j player
				if (team[j] == t) // are same team
					tot += S[i][j]; // then add S[i][j] ( cf) S[i][i] = 0 )
			}
			if (t == 1)
				gap += tot;
			else
				gap -= tot;
		}
		ans = min(ans, abs(gap));
		return;
	}

	if (A < N / 2){
		team[n] = 1;
		solution(A + 1, B, n + 1);
	}
	if (B < N / 2){
		team[n] = 2;
		solution(A, B + 1, n + 1);
	}
}

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> S[i][j];

	solution(0, 0, 1); // # of player of team A, # of player of team B, selected player

	cout << ans;

	return 0;
}
