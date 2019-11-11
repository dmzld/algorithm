#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
vector< vector<int> > arr;
vector< vector<int> > rots; // r, c, s
bool check[6] = { false, };
int min_res = INT_MAX;

int getValue(){
	int cur_res = INT_MAX;
	for (int i = 0; i < N; i++){
		int row_value = 0;
		for (int j = 0; j < M; j++){
			row_value += arr[i][j];
		}
		if (cur_res > row_value)
			cur_res = row_value;
	}
	return cur_res;
}

void rotation(int rot){
	// rots[rot][0~2]
	int cR = rots[rot][0];
	int cC = rots[rot][1];
	int cS = rots[rot][2];

	for (int i = 1; i <= cS; i++){
		int tmp = arr[cR - i][cC - i]; // 맨 왼쪽 위 원소
		for (int j = cR - i + 1; j <= cR + i; j++){
			arr[j - 1][cC - i] = arr[j][cC - i];
		}
		for (int j = cC - i + 1; j <= cC + i; j++){
			arr[cR + i][j - 1] = arr[cR + i][j];
		}
		for (int j = cR + i - 1; j >= cR - i; j--){
			arr[j + 1][cC + i] = arr[j][cC + i];
		}
		for (int j = cC + i - 1; j >= cC - i; j--){ // j > cC 해도됨
			arr[cR - i][j + 1] = arr[cR - i][j];
		}
		arr[cR - i][cC - i + 1] = tmp;
	}
}

void select(int cnt){
	if (cnt == K){
		int curValue = getValue();
		if (min_res > curValue)
			min_res = curValue;
	}
	else {
		vector< vector<int> > tmpArr = arr;
		for (int i = 0; i < K; i++){
			if (check[i] == false){
				check[i] = true;
				rotation(i); // apply ith rots func to arr
				select(cnt + 1); // select next rots func
				arr = tmpArr;
				check[i] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	arr.resize(N);
	for (int i = 0; i < N; i++)
		arr[i].resize(M);
	rots.resize(K);
	for (int i = 0; i < K; i++)
		rots[i].resize(3);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	for (int i = 0; i < K; i++){
		for (int j = 0; j < 3; j++){
			int tmp;
			cin >> tmp;
			rots[i][j] = tmp;
		}
		rots[i][0]--;
		rots[i][1]--;
	}

	vector< vector<int> > tmpArr = arr;
	for (int i = 0; i < K; i++){
		check[i] = true;
		rotation(i);
		select(1);
		check[i] = false;
		arr = tmpArr;
	}
	
	cout << min_res;

	return 0;
}
