#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int arr[11];
int oper[4]; // +, -, *, /
long long res = 0;
long long max_res = -1000000001, min_res = 1000000001;

void func(int cnt){
	if (cnt == N){
		if (res > max_res)
			max_res = res;
		if (res < min_res)
			min_res = res;
		return;
	}

	for (int i = 0; i < 4; i++){
		if (oper[i] != 0){
			long long tmp = res;
			switch (i){

			case 0: // +
				oper[i]--;
				res += arr[cnt];
				func(cnt + 1);
				res = tmp;
				oper[i]++;
				break;
			case 1: // -
				oper[i]--;
				res -= arr[cnt];
				func(cnt + 1);
				res = tmp;
				oper[i]++;
				break;
			case 2: // *
				oper[i]--;
				res *= arr[cnt];
				func(cnt + 1);
				res = tmp;
				oper[i]++;
				break;
			case 3: // /
				oper[i]--;
				res /= arr[cnt];
				func(cnt + 1);
				res = tmp;
				oper[i]++;
				break;
			}
		}
	}
}

int main(){

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++){
		cin >> oper[i];
	}

	res = arr[0];
	func(1);

	cout << max_res << "\n" << min_res << "\n";
	return 0;
}
