#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, ans = 0;
vector<pair<int, int>> line, res;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}

	sort(line.begin(), line.end()); // for comparing from the top

	res.push_back(line[0]);
	for (int i = 1; i < N; i++){
		bool exchange = false;
		for (int j = 0; j < res.size(); j++){
			if ((res[j].first < line[i].first && res[j].second > line[i].second) ||
				(res[j].first > line[i].first && res[j].second < line[i].second)){ // if cross
				res[j] = line[i]; // exchange, why? line in res[j] must be have more crossing line than line[i]
				exchange = true;
				break;
			}
		}

		if (!exchange) // if no exchange, just add
			res.push_back(line[i]);
	}
  
  // it can be solved by dp (more easy)

	cout << N - res.size();
	return 0;
}
