#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct state{
	int y, x;
	int cnt;
};

struct compare{
	bool operator()(state a, state b){
		return a.cnt > b.cnt;
	}
};

int N;
string map[50];
bool check[50][50][50 * 50] = { false, }; // for check visiting map[i][j] with [cnt]
priority_queue<state, vector<state>, compare> pq;
pair<int, int> d[4] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
			cin >> map[i];

	pq.push({ 0, 0, 0 });
	check[0][0][0] = true;
	

	while (!pq.empty()){
		int y = pq.top().y, x = pq.top().x,
			c = pq.top().cnt;
		pq.pop();

		if (y == N - 1 && x == N - 1){
			cout << c;
			return 0;
		}

		for (int i = 0; i < 4; i++){
			int ny = y + d[i].first, nx = x + d[i].second,
				nc = c;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (map[ny][nx] == '0')
				nc++;
			if (check[ny][nx][nc])
				continue;

			pq.push({ ny, nx, nc });
			check[ny][nx][nc] = true;
		}
	}

	return 0;
}
