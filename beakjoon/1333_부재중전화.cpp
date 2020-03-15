#include <iostream>

using namespace std;

int N, L, D;
int t = 0, ans = 0;

int main(){

	cin >> N >> L >> D;

	for (int i = 0; i < N; i++){
		t += L;
		for (int j = 0; j < 5; j++){
			if (t%D == 0){
				cout << t;
				return 0;
			}
			t++;
		}
	}

	while (1){
		if (t%D == 0){
			cout << t;
			return 0;
		}
		t++;
	}

	return 0;
}
