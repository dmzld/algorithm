#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

struct state{
	int x, cnt;
};

struct comp{
	bool operator()(state a, state b){
		return a.cnt > b.cnt;
	}
};

int dir[4] = { -1, 1 }; // { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans = 0;


int N, K;
int map[100001], pre[100001], d[100001];
priority_queue<state, vector<state>, comp> pq;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i <= 100000; i++)
		d[i] = INT_MAX;

	pq.push({ N, 0 });
	d[N] = 0;

	while (!pq.empty()){
		state tmp = pq.top();
		pq.pop();

		if (d[tmp.x] < tmp.cnt)
			continue;

		if (tmp.x == K){
			ans = tmp.cnt;
			break;
		}

		int nCnt = tmp.cnt + 1;
		for (int i = 0; i < 2; i++){
			int nx = tmp.x + dir[i];

			if (nx < 0 || nx > 100000 || d[nx] <= nCnt)
				continue;

			pq.push({ nx, nCnt });
			d[nx] = nCnt;
			pre[nx] = tmp.x;
		}

		int nx = tmp.x * 2;
		if (nx < 0 || nx > 100000 || d[nx] <= nCnt)
			continue;

		pq.push({ nx, nCnt });
		d[nx] = nCnt;
		pre[nx] = tmp.x;
	}
	stack<int> s;
	s.push(K);
	while (K != N){
		s.push(pre[K]);
		K = pre[K];
	}

	cout << ans << "\n";
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}


	return 0;
}
