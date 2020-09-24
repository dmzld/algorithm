#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>

using namespace std;

struct info{
	int d; // distance
	int hy, hx; // pos of man
	int ly, lx; // pos of seat
};
struct comp{
	bool operator()(info a, info b){
		return a.d > b.d;
	}
};

struct state{
	int d; // distance
	int cnt; // d만큼 떨어져있는 사람의 수
};

int R, C;
const int MAX = 200001;
char map[101][101];
vector<pair<int, int>> v; // empty seat
priority_queue<info, vector<info>, comp> pq;
state seat[101][101]; // map[i][j]에 있는 seat 상태
bool check[101][101] = { false, }; // map[i][j]에 있는 사람이 앉을 자리를 정했는지
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++){
			cin >> map[i][j];
			if (map[i][j] == 'L')
				v.push_back({ i, j });
		}

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			if (map[i][j] == 'X'){
				for (int k = 0; k < v.size(); k++){
					int d = pow(abs(i - v[k].first), 2) + pow(abs(j - v[k].second), 2);
					pq.push({ d, i, j, v[k].first, v[k].second });
				}
			}
		}
	}

	while (!pq.empty()){
		info tmp = pq.top();
		pq.pop();

		// 이미 앉을 곳을 정한 사람이면 
		if (check[tmp.hy][tmp.hx])
			continue;

		/*
		d를 기준으로한 pq이기 때문에
		seat[tmp.ly][tmp.lx].d != 0 && seat[tmp.ly][tmp.lx].d > tmp.d 인 경우는 없다
		*/
		if (!seat[tmp.ly][tmp.lx].d){ // 공석인 경우
			seat[tmp.ly][tmp.lx] = { tmp.d, 1 };
			check[tmp.hy][tmp.hx] = true;
		}
		else if (seat[tmp.ly][tmp.lx].d == tmp.d){ // 거리가 같은 경우
			seat[tmp.ly][tmp.lx].cnt++;
			check[tmp.hy][tmp.hx] = true;
		}
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (seat[i][j].cnt > 1)
				ans++;

	cout << ans;

	return 0;
}
