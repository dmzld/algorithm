#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, map[20][20];
int depthVal[11];
int ans = 0;

int maxValue(){
	int val = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			val = max(val, map[i][j]);

	return val;
}

void copyMap(int tmap[][20], int fmap[][20]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmap[i][j] = fmap[i][j];

	return;
}

bool compareMap(int tmap[][20], int fmap[][20]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (tmap[i][j] != fmap[i][j])
				return false;

	return true;
}

void move(int d){
	// 기울이는 방향쪽부터 원소 queue에 담고 합쳐지는지 확인하면서 map에 값 저장
	queue<int> q;
	if (d == 0){ // 우
		for (int i = 0; i < N; i++){
			for (int j = N - 1; j >= 0; j--)
				if (map[i][j] != 0){
					q.push(map[i][j]);
					map[i][j] = 0;
				}

			int idx = N - 1;
			while (!q.empty()){
				int tmp = q.front();
				q.pop();

				if (!q.empty() && tmp == q.front()){
					map[i][idx] = tmp * 2;
					q.pop();
				}
				else{
					map[i][idx] = tmp;
				}

				idx--;
			}
		}
	}
	else if (d == 1){ // 좌
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				if (map[i][j] != 0){
					q.push(map[i][j]);
					map[i][j] = 0;
				}

			int idx = 0;
			while (!q.empty()){
				int tmp = q.front();
				q.pop();

				if (!q.empty() && tmp == q.front()){
					map[i][idx] = tmp * 2;
					q.pop();
				}
				else{
					map[i][idx] = tmp;
				}

				idx++;
			}
		}
	}
	else if (d == 2){ // 상
		for (int j = 0; j < N; j++){
			for (int i = 0; i < N; i++)
				if (map[i][j] != 0){
					q.push(map[i][j]);
					map[i][j] = 0;
				}

			int idx = 0;
			while (!q.empty()){
				int tmp = q.front();
				q.pop();

				if (!q.empty() && tmp == q.front()){
					map[idx][j] = tmp * 2;
					q.pop();
				}
				else{
					map[idx][j] = tmp;
				}
				idx++;
			}
		}
	}
	else{ // 하
		for (int j = 0; j < N; j++){
			for (int i = N - 1; i >= 0; i--)
				if (map[i][j] != 0){
					q.push(map[i][j]);
					map[i][j] = 0;
				}

			int idx = N - 1;
			while (!q.empty()){
				int tmp = q.front();
				q.pop();

				if (!q.empty() && tmp == q.front()){
					map[idx][j] = tmp * 2;
					q.pop();
				}
				else{
					map[idx][j] = tmp;
				}
				idx--;
			}
		}
	}
	return;
}

void dfs(int cnt){
	int val = maxValue();

	// 이전에 같은 depth에서의 기대값보다 작은경우 return
	if (val <= depthVal[cnt]) return;

	// 최종단계
	if (cnt == 10){
		// 이미 전 단계에서 ans < val은 확인
		ans = val;

		for (int i = 10; i >= 1; i--){
			depthVal[i] = val;
			val /= 2;
		}
		return;
	}
	
	int tmp[20][20];
	copyMap(tmp, map);

	// 이동
	for (int i = 0; i < 4; i++){
		move(i);
		if (compareMap(tmp, map)) continue;
		dfs(cnt + 1);
		copyMap(map, tmp);
	}

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	ans = maxValue(); // init

	dfs(0);

	cout << ans;

	return 0;
}
