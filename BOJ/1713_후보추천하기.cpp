#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct state{
	int num, recom, time;
};

bool comp(state a, state b){
		return a.num < b.num;
}

int N, M, n;
state map[20];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> n;
		int mIdx = 0;
		bool flag = false;

		for (int j = 0; j < N; j++){
			if (map[mIdx].recom > map[j].recom || 
				(map[mIdx].recom == map[j].recom && map[mIdx].time > map[j].time))
				mIdx = j;

			if (map[j].num == 0){
				map[j] = { n, 1, i };
				flag = true;
				break;
			}
			else if (map[j].num == n){
				map[j].recom++;
				flag = true;
				break;
			}
		}

		if (!flag)
			map[mIdx] = { n, 1, i };
	}

	sort(map, map + N, comp);

	for (int i = 0; i < N; i++)
		cout << map[i].num << " ";

	return 0;
}
