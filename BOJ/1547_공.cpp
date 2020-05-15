#include <iostream>
using namespace std;

int main(){

	int M, X, Y;
	int arr[3] = { 1, 0, 0 };
	int tmp = 0;

	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> X >> Y;
		tmp = arr[X-1];
		arr[X-1] = arr[Y-1];
		arr[Y-1] = tmp;
	}

	for (int i = 0; i < 3; i++){
		if (arr[i] == 1)
			cout << i + 1;
	}

	return 0;
}
