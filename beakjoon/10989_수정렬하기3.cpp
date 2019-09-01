#include <iostream>
#include <cstdio>
using namespace std;


int main(){	
	
	int N, n;
	int arr[10001] = { 0, };

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &n); 
		arr[n]++;
	}
	for (int i = 1; i <= 10000; i++){
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}
	
	return 0;
}
