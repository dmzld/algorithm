#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, num[101], ans = 0;
bool check[101] = { false, }, done[101] = { false, };
vector<int> set;

void dfs(int n){
	check[n] = true;
	int nn = num[n];

	if (check[nn] && !done[nn]){
		for (int i = num[nn]; i != nn; i = num[i])
			set.push_back(i);
		set.push_back(nn);
	}
	else if (!check[nn])
		dfs(nn);
	
	done[n] = true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];

	for (int i = 1; i <= N; i++)
		if (!done[i])
			dfs(i);

	sort(set.begin(), set.end());
	cout << set.size()<<"\n";
	for (int i = 0; i < set.size(); i++)
		cout << set[i] << "\n";

	return 0;
}
