#include <iostream>
using namespace std;

int main(){

	int tot = 0;
	int max = 0;
	int var = 0;

	for (int i = 0; i < 4; i++){
		cin >> var;
		tot -= var;
		cin >> var;
		tot += var;
		if (max < tot)
			max = tot;
	}

	cout << max;

	return 0;
}
