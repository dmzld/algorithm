#include <iostream>

using namespace std;

int main(){
	int fn; // finger number
	long long fc; // finger count
	long long num = 0;

	cin >> fn >> fc;

  // 1 cycle => 1~5~2 : 8
	if (fn == 1 || fn == 5)
		num = fc * 8 + fn - 1;
	else{ // fn == 2,3,4
		num = (fc / 2) * 8;

		if ((fc % 2) == 0)
			num += (fn - 1);
		else if ((fc % 2) == 1)
			num += 8 - (fn - 1);
	}

	cout << num;
}
