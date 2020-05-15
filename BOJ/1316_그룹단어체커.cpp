#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int t = 0;
	int n = 0;

	cin >> t;

	for (int i = 0; i < t; i++){
		char s[100];
		int check[26] = { 0, };
		int g = -1; // idx
		bool w = true; // group word

		scanf("%s", s);

		for (int j = 0; s[j] != NULL; j++){
			if (g == (int)(s[j] - 'a'))
				continue;
			else{
				g = (int)(s[j] - 'a');
				check[g]++;
				if (check[g] > 1){
					w = false;
					break;
				}
			}
		}

		if (w)
			n++;
	}

	cout << n;

	return 0;
}
