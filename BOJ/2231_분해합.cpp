#include <iostream>
using namespace std;


int main(){

	int N = 0, M = 0;
	cin >> N;

	for (int i = 1; i <= 1000000; i++){
		int num = i; // 잠재적 M
		int sum = i; // N과 비교할 변수
		
		while (num){
			sum += num % 10;
			num = num / 10;
		}

		if (sum == N){
			M = i;
			break;
		}
	}

	if (M > 0)
		cout << M;
	else
		cout << 0;


	return 0;
}
