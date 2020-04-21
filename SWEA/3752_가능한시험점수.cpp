#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int T;
int N, S[100];
bool P[10001]; // possible score

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> S[i];

		vector<int> v;
		memset(P, false, sizeof(P));

		P[0] = true;
		v.push_back(0);

		for (int i = 0; i < N; i++){
			int vSize = v.size();
			for (int j = 0; j < vSize; j++){
				if (!P[S[i] + v[j]]){
					P[S[i] + v[j]] = true;
					v.push_back(S[i] + v[j]);
				}
			}
		}

		cout << "#" << tc << " " << v.size() << "\n";
		
	}


	return 0;
}
