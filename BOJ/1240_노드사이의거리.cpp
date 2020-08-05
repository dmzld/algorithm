#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int,int>> tree[1001]; // tree[n1] = { n2, dis}

int solution(int src, int dest){
	bool check[1001] = { false, };
	queue<pair<int, int>> q;

	check[src] = true;
	q.push({ src, 0 });
	while (!q.empty()){
		int cn = q.front().first, res = q.front().second;
		q.pop();

		for (int i = 0; i < tree[cn].size(); i++){
			if (!check[tree[cn][i].first]){
				if (tree[cn][i].first == dest)
					return res + tree[cn][i].second;

				check[tree[cn][i].first] = true;
				q.push({ tree[cn][i].first, res + tree[cn][i].second });
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++){
		int n1, n2, dis;
		cin >> n1 >> n2 >> dis;

		tree[n1].push_back({ n2, dis });
		tree[n2].push_back({ n1, dis });
	}
	for (int i = 0; i < M; i++){
		int n1, n2;
		cin >> n1 >> n2;

		cout << solution(n1, n2) << "\n";
	}

		
	return 0;
}
