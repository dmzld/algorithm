#include <iostream>

using namespace std;

int K, N, T;
char Z;
int time = 210;

int main(){

	cin >> K >> N;
	for (int i = 0; i < N; i++){
		cin >> T >> Z;

		time -= T;
		if (time <= 0)
			break;

		if (Z == 'T')
			K = (K + 1) % 9;
		if (K == 0)
			K = 1;
		
	}
	cout << K;

	return 0;
}
