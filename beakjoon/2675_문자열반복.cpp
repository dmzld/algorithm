#include <iostream>
#include <string>
using namespace std;

int main(){

	int n;
	int r;
	string S; // char S[100]
	
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> r;
		cin >> S;
		for (int j = 0; j < S.size(); j++){ // S[j] != NULL
			for (int k = 0; k < r; k++)
				cout << S[j];
		}
		cout << "\n";
	}

	return 0;
}
