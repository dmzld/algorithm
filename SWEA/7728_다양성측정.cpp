#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){

	int T = 0, X = 0, d = 0;
	int arr[10] = { 0, };
	cin >> T;

	for (int i = 0; i < T; i++){
		cin >> X;
		
		int r = 0;
		while (X != 0){
			r = X % 10;
			X /= 10;
			if (arr[r]==0)
				arr[r] = 1;
		}
		for (int j = 0; j < 10; j++){
			if (arr[j] == 1)
				d++;
			arr[j] = 0;
		}

		cout << "#" << i+1 << " " << d << "\n";
		d = 0;			
	}



	return 0;
}
