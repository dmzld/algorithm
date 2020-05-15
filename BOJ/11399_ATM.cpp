#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int res = 0;

int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++)
			res += arr[j];
	}

	cout << res;

	return 0;
}
