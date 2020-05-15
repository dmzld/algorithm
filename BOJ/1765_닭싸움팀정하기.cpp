#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> F[1001];
vector<int> E[1001];
bool check[1001] = { false, };
int ans = 0;

void dfs(int idx){
	check[idx] = true;
	for (int i = 0; i < F[idx].size(); i++){ // idx's friends
		if (!check[F[idx][i]]){
			for (int j = 0; j < F[F[idx][i]].size(); j++){
				dfs(F[idx][i]);
			}
		}
	}
	for (int j = 0; j < E[idx].size(); j++){ // idx's enemies
		for (int k = 0; k < E[E[idx][j]].size(); k++){ // idx's enemies' enemies == idx's friends
			if (!check[E[E[idx][j]][k]]){
				dfs(E[E[idx][j]][k]);
			}
		}
	}
}

int main(){

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		char FE;
		int a, b;
		cin >> FE >> a >> b;
		if (FE == 'F'){
			F[a].push_back(b);
			F[b].push_back(a);
		}
		else if (FE == 'E'){
			E[a].push_back(b);
			E[b].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++){
		if (!check[i]){
			dfs(i);
			ans++;
		}
	}
	
	cout << ans;

	return 0;
}
