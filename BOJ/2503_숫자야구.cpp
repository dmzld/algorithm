#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<string, pair<int, int>>> v;
vector<int> query;
long long ans = 0;

bool pass(){
	for (int i = 0; i < v.size(); i++){
		int cstk = 0, cball = 0;
		// strike
		for (int j = 0; j < 3; j++){
			if (query[j] == (int)(v[i].first[j] - '0'))
				cstk++;
		}
		// ball
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				if (j != k && query[j] == (int)(v[i].first[k] - '0'))
					cball++;
			}
		}

		if (cstk != v[i].second.first || cball != v[i].second.second)
			return false;
	}
	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		string num;
		int stk, ball;
		cin >> num >> stk >> ball;
		v.push_back({ num, { stk, ball } });
	}

	for (int i = 1; i <= 9; i++){
		query.push_back(i);
		for (int j = 1; j <= 9; j++){
			if (i != j){
				query.push_back(j);
				for (int k = 1; k <= 9; k++){
					if (i != k && j != k){
						query.push_back(k);
						
						if (pass())
							ans++;

						query.pop_back();
					}
				}
				query.pop_back();
			}
			
		}
		query.pop_back();
	}

	cout << ans;

	return 0;
}
