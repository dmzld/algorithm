#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void padovan(int i){
		
}

int main(){

	int N = 0, tmp = 0;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N; i > 0; i--){
		for (int j = 0; j < i - 1; j++){
			if (arr[j] > arr[j + 1]){
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";


	return 0;
}
