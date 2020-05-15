#include <iostream>
#include <algorithm>

using namespace std;

int num[5], multiple[5];
int ans = 0;

int main(){

	for (int i = 0; i < 5; i++){
		cin >> num[i];
		multiple[i] = num[i];
	}

	while (ans == 0){
		int cnt = 0;
		int minIdx = 0;

		for (int i = 1; i < 5; i++){
			if (multiple[minIdx] > multiple[i])
				minIdx = i;
		}

		for (int i = 0; i < 5; i++){
			if (multiple[minIdx] % num[i] == 0)
				cnt++;
		}

		if (cnt >= 3)
			ans = multiple[minIdx];
		else{
			multiple[minIdx] += num[minIdx];
		}
	}

	cout << ans;

	return 0;
}
