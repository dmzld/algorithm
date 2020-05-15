#include <iostream>
using namespace std;

/*
int fibo(int num){

	return (num == 1 || num == 0) ? num : fibo(num - 1) + fibo(num - 2);
}
*/

int main(){

	int n, res;
	int arr[3] = { 0, 1, 1 };

	cin >> n;
	if (n == 0 || n == 1)
		res = n;
	else{
		for (int i = 2; i <= n; i++){
			arr[i % 3] = arr[(i+1) % 3] + arr[(i+2) % 3];
			res = arr[i % 3];
		}
	}
	

	cout << res;


	return 0;
}
