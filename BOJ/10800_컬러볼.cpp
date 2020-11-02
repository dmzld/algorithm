#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
	int num, color, size, ans;
};

struct State{
	int pivot, pSize, cSize;
};


bool comp1(Info a, Info  b){
	return a.size < b.size;
}

bool comp2(Info a, Info b){
	return a.num < b.num;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, c, s;

	cin >> N;
	vector<Info> v(N);
	vector<State> acc(N);
	for (int i = 0; i < N; i++){
		cin >> c >> s;
		v[i] = { i, c - 1, s, 0 };
	}

	// size 순으로 정렬
	sort(v.begin(), v.end(), comp1);

	// init with [0]
	int pivot = v[0].size,
		pTot = 0,
		cTot = v[0].size;

	acc[v[0].color].cSize = v[0].size;
	acc[v[0].color].pivot = v[0].size;

	// start calculating with [1]
	for (int i = 1; i < N; i++){
		int idx = v[i].color;

		if (acc[idx].pivot < v[i].size){
			acc[idx].pivot = v[i].size;
			acc[idx].pSize = acc[idx].cSize;
		}

		if (pivot >= v[i].size){
			v[i].ans = pTot - acc[idx].pSize;
		}
		else{
			v[i].ans = cTot - acc[idx].cSize;

			acc[idx].pSize = acc[idx].cSize;

			pivot = v[i].size;
			pTot = cTot;
		}
		// 공통
		acc[idx].cSize += v[i].size;
		cTot += v[i].size;

	}

	// num 순으로 정렬
	sort(v.begin(), v.end(), comp2);

	for (int i = 0; i < N; i++)
		cout << v[i].ans << "\n";

	return 0;
}
