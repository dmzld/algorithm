#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int INF = 987654321;

int n, k, s;
vector<int> E[401];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
	}
	
	cin >> s;
	for (int i = 0; i < s; i++){
		int a, b;
		queue<int> q1;
		queue<int> q2;
		bool c1[401] = { false, }, f1 = false;
		bool c2[401] = { false, }, f2 = false;
		cin >> a >> b;

		// validation a -> b
		c1[a] = true;
		q1.push(a);
		while (!q1.empty()){
			int qSize = q1.size();
			for (int j = 0; j < qSize; j++){
				int c = q1.front();
				q1.pop();

				for (int k = 0; k < E[c].size(); k++){
					if (E[c][k] == b){
						f1 = true;
						break;
					}
					else if (!c1[E[c][k]]){
						c1[E[c][k]] = true;
						q1.push(E[c][k]);
					}
				}
				if (f1)
					break;
			}
			if (f1)
				break;
		}

		if (!f1){
			// validation b -> a
			c2[b] = true;
			q2.push(b);
			while (!q2.empty()){
				int qSize = q2.size();
				for (int j = 0; j < qSize; j++){
					int c = q2.front();
					q2.pop();

					for (int k = 0; k < E[c].size(); k++){
						if (E[c][k] == a){
							f2 = true;
							break;
						}
						else if (!c2[E[c][k]]){
							c2[E[c][k]] = true;
							q2.push(E[c][k]);
						}
					}
					if (f2)
						break;
				}
				if (f2)
					break;
			}
		}

		if (f1 && !f2)
			cout << -1 << "\n";
		else if (!f1 && f2)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}
