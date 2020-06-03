#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

int N, M;
vector<int> bigger[100], smaller[100];
int ans = 0;

void dfs(int num){
	int b = 0, s = 0;
	queue<int> q;
	bool check[100] = { false, };

	q.push(num);
	while (!q.empty()){
		int cm = q.front();
		q.pop();

		for (int i = 0; i < bigger[cm].size(); i++){
			if (!check[bigger[cm][i]]){
				check[bigger[cm][i]] = true;
				q.push(bigger[cm][i]);
				b++;
			}
		}
	}

	memset(check, false, sizeof(check));

	q.push(num); 
	while (!q.empty()){
		int cm = q.front();
		q.pop();

		for (int i = 0; i < smaller[cm].size(); i++){
			if (!check[smaller[cm][i]]){
				check[smaller[cm][i]] = true;
				q.push(smaller[cm][i]);
				s++;
			}
		}
	}
	if (b > N / 2 || s > N / 2)
		ans++;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		bigger[a].push_back(b);
		smaller[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		dfs(i);

	cout << ans;

	return 0;
}
