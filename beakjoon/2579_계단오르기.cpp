#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	int res;

	cin >> N;
	vector<int> s(N + 1, 0); // 0 : 시작  /  1~N : 계단
	vector<vector<int> > m(N + 1, vector<int>(4, 0)); // (x,o,o) (o,x,o) (o,o,x) (x,o,x)

	for (int i = 1; i < N + 1; i++){
		cin >> s[i];
	}
	for (int i = 0; i < 4; i++)
		m[0][i] = 0;

	for (int i = 1; i < N + 1; i++){ // i번째 계단에서의 합
		//현재 계단 밟을 때 (i-1, i-2, i)
		m[i][0] = s[i] + m[i - 1][1]; // x o o
		m[i][1] = ((m[i - 1][2]>m[i - 1][3]) ? s[i] + m[i - 1][2] : s[i] + m[i - 1][3]); // o x o
		//현재 계단 안 밟을 때
		m[i][2] = m[i - 1][0]; // o o x
		m[i][3] = m[i - 1][1]; // x o x
	}

	/*
	for (int i = 0; i < N + 1; i++){
		cout << s[i]<<"\n";
	}

	for (int i = 0; i < N + 1; i++){
		for (int j = 0; j < 4; j++)
			cout << m[i][j] << " ";
		cout << "\n";
	}
	*/
	
	cout << ((m[N][0] > m[N][1]) ? m[N][0] : m[N][1]);
	return 0;
}
