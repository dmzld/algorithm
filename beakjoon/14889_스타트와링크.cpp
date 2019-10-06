#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int n = 0, m = 0;
int abil[20][20];
int team[20] = { 0, };
int t1, t2;
int res = 3000;

void func(int cnt){
	if (n == N / 2 || m == N / 2){
		
		// t1 - t2 결정해서 res랑 비교
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (team[i] == team[j] && i != j){
					if (team[i] == 1){
						t1 += abil[i][j];
					}
					else {
						t2 += abil[i][j];
					}
				}
			}
		}
		/*
		cout << "\n" << "#" << "\n";
		for (int i = 0; i < N; i++) cout << team[i] << " ";
		cout << "\n";
		cout << t1 << " " << t2 << "\n";
		*/
		if (abs(t1 - t2) < res){
			res = abs(t1 - t2);
			//cout << res << "\n";
		}
		t1 = 0;
		t2 = 0;
		return;
	}

	team[cnt] = 0;
	m++;
	func(cnt + 1);
	team[cnt] = 0;
	m--;

	team[cnt] = 1;
	n++;
	func(cnt + 1);
	team[cnt] = 0;
	n--;
}

int main(){

	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> abil[i][j];
		}
	}
	
	func(0);

	cout << res;
	
	return 0;
}
