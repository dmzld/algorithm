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
	int a, b, c;
};

struct comp{
	bool operator()(state a, state b){
		return a.c > b.c;
	}
};

int dir[4] = { -1, 1 }; // { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans = 0;

int N, M, a, b, c;
priority_queue<state, vector<state>, comp> pq;
vector<state> res;
int p[1001];

int find(int n){
	while (n != p[n])
		n = p[n];
	return n;
}

bool uni(state s){
	int ca = find(s.a), cb = find(s.b);
	
	if (ca == cb)
		return false;

	p[max(ca, cb)] = min(ca, cb);

	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;

	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	while (!pq.empty() && res.size() < N){
		state tmp = pq.top();
		pq.pop();

		if (uni(tmp)){
			res.push_back(tmp);
		}
	}

	while (!res.empty()){
		ans += res.back().c;
		res.pop_back();
	}

	cout << ans;

	return 0;
}
