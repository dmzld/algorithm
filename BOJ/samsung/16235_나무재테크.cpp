#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int map[11][11] = { 0, }, A[11][11]; // 남은 양분, 매 해 추가되는 양분
vector<int> tree[11][11];
int ans = 0;

void ss(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (tree[i][j].size()>0)
				sort(tree[i][j].begin(), tree[i][j].end()); // 나이 오름차순으로 정렬
		}
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (tree[i][j].size() > 0){ // 나무가 있으면
				int nut = 0;
				for (int k = 0; k < tree[i][j].size(); k++){
					if (map[i][j] < tree[i][j][k]){ // 양분이 적으면
						nut += tree[i][j][k] / 2;
						tree[i][j].erase(tree[i][j].begin() + k);
						k--; // vector의 원소가 지워지면 뒤에 것이 땡겨오므로 그에 맞게 idx 유지
					}
					else{ // 양분이 충분하면
						map[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
				}
				map[i][j] += nut; // 죽어서 양분이 된다
			}
		}
	}
}

void fall(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			for (int k = 0; k < tree[i][j].size(); k++){
				if (tree[i][j][k] % 5 == 0){
					// 번식
					for (int p = i - 1; p <= i + 1; p++){
						for (int q = j - 1; q <= j + 1; q++){
							if (p > 0 && p <= N && q > 0 && q <= N && (p != i || q != j))
								tree[p][q].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			map[i][j] += A[i][j];
		}
	}
}

int main(){

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++){
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	

	for (int i = 0; i < K; i++){
		// 봄 : 어린순서대로 나이만큼 양분흡수 후 나이++, 흡수 못하면 죽음
		// 여름 : 죽은나무의 나이/2 만큼 양분으로 변환
		ss();
		// 가을 : 나이가 5의 배수인 나무가 인접한 8개 칸에 번식,
		fall();
		// 겨울 :  A[i][j]만큼 양분 추가
		winter();
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (tree[i][j].size() > 0)
				ans += tree[i][j].size();

	cout << ans;

	return 0;
}
