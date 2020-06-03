#include <iostream>
#include <cstring>

using namespace std;

int T, n, choice[100001], cnt= 0;
bool check[100001], done[100001];

void dfs(int num){
	check[num] = true;

	int nnum = choice[num]; // ** point 1

	if (check[nnum] && !done[nnum]){ // find cycle
		for (int i = choice[nnum]; i != nnum; i = choice[i]) // ** point 2
			cnt++;
		cnt++; // itself
	}
	else if (!check[nnum])
		dfs(nnum);

	done[num] = true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> choice[i];

		cnt = 0;
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));

		for (int i = 1; i <= n; i++)
			if (!done[i])
				dfs(i);

		cout << n - cnt << "\n";
	}


	return 0;
}
