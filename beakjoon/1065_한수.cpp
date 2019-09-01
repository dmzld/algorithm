#include <iostream>
using namespace std;


int main(){

	int num = 0, res = 0;
	cin >> num;
	
	for (int i = 0; i <= num; i++){
		int num = i;
		int diff = (num /10) % 10 - num % 10;
		
		while (num){
			if ((num / 10) % 10 - num % 10 == diff){
				num = num / 10;
				if (num < 10){
					res++;
					break;
				}
			}
			else
				break;

		}
	}
	
	cout << res;

	return 0;
}
