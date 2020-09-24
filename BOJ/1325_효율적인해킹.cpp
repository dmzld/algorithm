#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>


using namespace std;

int N, M, ans = 0;
vector<int> v[10001];
vector<int> res;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++){
		int cnt = 0;
		bool check[10001] = { false, };
		queue<int> q;
		q.push(i);
		check[i] = true;

		while (!q.empty()){
			int n = q.front();
			q.pop();
			for (int j = 0; j < v[n].size(); j++){
				if (!check[v[n][j]]){
					cnt++;
					q.push(v[n][j]);
					check[v[n][j]] = true;
				}
			}
		}

		if (cnt > ans){
			ans = cnt;
			res.clear();
			res.push_back(i);
		}
		else if (cnt == ans)
			res.push_back(i);
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	return 0;
}
