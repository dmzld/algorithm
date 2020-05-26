#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree[100001];
int ans[100001];
bool check[100001] = { false, };

void dfs(int parent){
	for (int i = 0; i < tree[parent].size(); i++){
		if (!check[tree[parent][i]]){
			check[tree[parent][i]] = true;
			ans[tree[parent][i]] = parent;
			dfs(tree[parent][i]);
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	check[1] = true;
	dfs(1); // from root to leaf
	
	for (int i = 2; i <= N; i++)
		cout << ans[i] << "\n";


	return 0;
}
