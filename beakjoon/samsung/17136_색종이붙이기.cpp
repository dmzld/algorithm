#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
int p[6] = { 0, }; // 1 ~5
vector<pair<int, int>> v;
bool check[10][10] = { false, };
int ans = 26;

bool canAttach(int y, int x, int size){
	for (int i = y; i < y + size; i++){
		for (int j = x; j < x + size; j++){
			if (i >= 10 || j >= 10)
				return false;
			if (map[i][j] == 0 || check[i][j])
				return false;
		}
	}
	return true;
}

void attach(int y, int x, int size, bool value){
	for (int i = y; i < y + size; i++){
		for (int j = x; j < x + size; j++){
			check[i][j] = value;
		}
	}
}

void solution(int idx){
	if (idx == v.size()){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (map[i][j] == 1 && !check[i][j])
					return;
			}
		}
		int res = 0;
		for (int i = 1; i <= 5; i++){
			res += p[i];
		}

		if (ans > res)
			ans = res;

		return;
	}

	int y = v[idx].first, x = v[idx].second;
	
	if (check[y][x])
		solution(idx + 1);
	
	for (int i = 5; i > 0; i--){
		if (p[i] < 5 && canAttach(y, x, i)){
			p[i]++;
			attach(y, x, i, true);
	
			solution(idx + 1);
			
			p[i]--;
			attach(y, x, i, false);
		}
	}
}

int main(){

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cin >> map[i][j];
			if (map[i][j] == 1){
				v.push_back({ i, j });
			}
		}
	}

	solution(0);

	if (ans == 26)
		cout << -1;
	else
		cout << ans;

	return 0;
}
