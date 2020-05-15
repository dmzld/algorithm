#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> H, C; // location of house, chicken
vector<bool> R; // remained chicken
int res = 99999999;

void solution(int cur, int cnt){
	if (cnt == M){
		int city_distance = 0;
		for (int i = 0; i < H.size(); i++){ // for one house
			int min_distance = 99999999;
			for (int j = 0; j < R.size(); j++){
				if (R[j]){ // get min distance with remained chicken
					int distance = abs(H[i].first - C[j].first) + abs(H[i].second - C[j].second);
					if (min_distance > distance)
						min_distance = distance;
				}
			}
			city_distance += min_distance; // add min chicken distance for one house to city_distance 
		}
		if (res > city_distance)
			res = city_distance;
		
		return;
	}
	if (cur >= R.size())
		return;
	R[cur] = true;
	solution(cur + 1, cnt + 1);
	R[cur] = false;
	solution(cur + 1, cnt);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				H.push_back(make_pair(i, j));
			else if (tmp == 2)
				C.push_back(make_pair(i, j));
		}
	} R.resize(C.size(), false);

	solution(0, 0);

	cout << res;

	return 0;
}
