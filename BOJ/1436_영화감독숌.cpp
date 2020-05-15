#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void up(int i, int *arr){
	if (arr[i] == 9){
		arr[i] = 0;
		up(i - 1, arr);
	}
	else
		arr[i]++;
}

//vector< vector<int> > e(C + 1, vector<int>(C + 1, 0));
int main(){

	int N = 0, p = 0;
	int num[10] = { 0, };

	for (int i = 7; i < 10; i++)
		num[i] = 6;
	
	cin >> N;
	
	while (1){
		for (int i = 0; i < 9 - 2 + 1; i++){
			if (num[i] == 6 && num[i + 1] == 6 && num[i + 2] == 6){
				N--;
				break;
			}
		}
		if (N == 0)
			break;
		else
			up(9, num);
	}
	if (num[0] != 0)
		cout << num[0];
	for (int i = 1; i < 10; i++){
		if (num[i - 1] != 0 || num[i] != 0)
			cout << num[i];
	}

	return 0;
}
