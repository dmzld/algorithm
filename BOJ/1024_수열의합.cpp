#include <iostream>
#include <vector>

using namespace std;

int N;
int L;

int main(){

	cin >> N >> L;

	// series : x+1 + x+2 + ... + x+L == L*x + L(L+1)/2  == N?
	for (int i = L; i <= 100; i++){
		int tmp = N - i * (i + 1) / 2;

		if (tmp % i == 0){
			int x = tmp/i;
			if (x + 1 >= 0){
				for (int j = x + 1; j <= x + i; j++)
					cout << j << " ";
				cout << "\n";
				return 0;
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}
