#include <iostream>
using namespace std;

int main(){

	int N = 0;
	int kim = 0, lim = 0;
	int odd = 0, even = 0;
	int round = 1;

	cin >> N;
	cin >> kim;
	cin >> lim;


	while (N != 1){
		
		if (abs(kim - lim) == 1){
			if (kim % 2 == 1){
				odd = kim;
				even = lim;
			}
			else if (lim % 2 == 1){
				odd = lim;
				even = kim;
			}

			if ((odd + 1) == even){
				cout << round;
			}
		}

		N = N / 2 + N % 2;

		if (kim % 2 == 0){
			kim = kim / 2;
		}
			
		else
			kim = kim / 2 + 1;


		if (lim % 2 == 0)
			lim = lim / 2;
		else
			lim = lim / 2 + 1;

		round++;
	}


	return 0;
}
