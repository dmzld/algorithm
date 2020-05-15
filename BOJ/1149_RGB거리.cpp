#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	int res;

	cin >> N;
	vector<vector<int> > h(N, vector<int>(3, 0));
	vector<vector<int> > m(N, vector<int>(3, 0)); // i번째 집이 r/g/b 일때 최소값

	for (int i = 0; i < N; i++){
		for (int j = 0; j < 3; j++){
			cin >> h[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		m[0][i] = h[0][i];


	for (int i = 1; i < N; i++){
		for (int j = 0; j < 3; j++){ // j == r/g/b

			m[i][j] = (m[i - 1][(j + 1) % 3] < m[i - 1][(j + 2) % 3]) ? (h[i][j] + m[i - 1][(j + 1) % 3]) : (h[i][j] + m[i - 1][(j + 2) % 3]); // 같으면?
			
		}
	}

	res = m[N - 1][0];
	for (int i = 1; i < 3; i++)
		res = (res < m[N - 1][i]) ? res : m[N - 1][i];

	cout << res;

	return 0;
}
