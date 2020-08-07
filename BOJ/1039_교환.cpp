#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

string N, ans = "0";
int K, M;
queue<string> q;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	M = N.length();

	if (M == 1 || (M == 2 && stoi(N) % 10 == 0)){
		cout << "-1";
		return 0;
	}

	q.push(N);
	for (int i = 0; i < K; i++){
		int qSize = q.size();
		set<string> dup;

		for (int j = 0; j < qSize; j++){
			string num = q.front();
			q.pop();

			for (int k = 0; k < M - 1; k++)
				for (int l = k + 1; l < M; l++){
					string tmp = num;
					if (k == 0 && tmp[l] == '0') continue;

					swap(tmp[k], tmp[l]);
					if (dup.find(tmp) == dup.end()){
						dup.insert(tmp);
						q.push(tmp);
					}
				}
		}
	}

	while (!q.empty()){
		if (ans < q.front())
			ans = q.front();
		q.pop();
	}

	cout << ans;

	return 0;
}
