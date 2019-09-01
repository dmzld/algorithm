#include <iostream>
using namespace std;

int main(){

	int poll = 64;
	int num = 0;
	int X = 0;

	cin >> X;

	while (X){
		if (X % 2 == 1)
			num++;
		X /= 2;
	}

	cout << num;
	return 0;
}
