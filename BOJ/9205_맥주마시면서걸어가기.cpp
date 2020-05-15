#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int t, n;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++){
		vector<pair<int, int>> m; // store position
		int check[101] = { false, }; // check map for visited store (check[i] for m[i] store) 
		queue<pair<int, int>> q; // push position of store that can arrive current step
		bool happy = false;

		cin >> n;

		for (int i = 0; i < n + 2; i++){
			int x, y;
			cin >> x >> y;
			m.push_back(make_pair(x, y));
		}

		q.push(m[0]);
		check[0] = true;
		while (!q.empty()){
			int qSize = q.size();
			for (int j = 0; j < qSize; j++){

				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 1; i < n + 2; i++){
					if (!check[i] && abs(x - m[i].first) + abs(y - m[i].second) <= 1000){
						if (i == n + 1){ // arrive
							happy = true;
							break;
						}
						else{
							q.push(m[i]);
							check[i] = true;
						}
					}
				}
				if (happy)
					break;
			}
			if (happy)
				break;
		}

		if (happy)
			cout << "happy\n";
		else
			cout << "sad\n";

	}



	return 0;
}
