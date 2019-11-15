#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

int N;
vector<int> pp;
vector< vector<bool> > adj;
vector<int> d[3];
int res = 987654321;

bool isConnect(int num){
	if (d[num].size() == 0)
		return false;

	if (d[num].size() == 1)
		return true;

	bool fcon = false;
	for (int i = 0; i < d[num].size(); i++){
		fcon = true;
		bool check[11] = { false, };
		queue<int> con;
		con.push(d[num][i]);
		while (!con.empty()){
			int city = con.front();
			con.pop();
			for (int j = 0; j < d[num].size(); j++){
				if (adj[city][d[num][j]] == 1 && !check[d[num][j]]){
					check[d[num][j]] = true;
					con.push(d[num][j]);
				}
			}
		}
		for (int j = 0; j < d[num].size(); j++){
			if (check[d[num][j]] == false){
				fcon = false;
				break;
			}
		}
		if (!fcon) return false;
	}
	return fcon;
}

void sol(int cnt){
	if (cnt == N + 1){
		if (isConnect(1) && isConnect(2)){
			int p1 = 0, p2 = 0;
			for (int i = 0; i < d[1].size(); i++){
				p1 += pp[d[1][i]];
			}
			for (int i = 0; i < d[2].size(); i++){
				p2 += pp[d[2][i]];
			}
			if (res>abs(p1 - p2))
				res = abs(p1 - p2);
		}
	}
	else{
		d[1].push_back(cnt);
		sol(cnt + 1);
		d[1].pop_back();

		d[2].push_back(cnt);
		sol(cnt + 1);
		d[2].pop_back();
	}
}

void init(){
	cin >> N;

	pp.resize(N + 1, 0);
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++)
		adj[i].resize(N + 1, false);

	for (int i = 1; i <= N; i++){
		int tmp;
		cin >> tmp;
		pp[i] = tmp;
	}

	for (int i = 1; i <= N; i++){
		int tmp;
		cin >> tmp;
		for (int j = 1; j <= tmp; j++){
			int c;
			cin >> c;
			adj[i][c] = true;
			adj[c][i] = true;
		}
	}
}


int main(){
	init();

	d[1].push_back(1);
	sol(2);
	d[1].pop_back();

	d[2].push_back(1);
	sol(2);
	d[2].pop_back();

	if (res == 987654321)
		cout << -1;
	else
		cout << res;

	return 0;
}
