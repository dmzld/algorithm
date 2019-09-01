#include <iostream>
using namespace std;

int main() {
	int input[9];
	int sum = 0;

	for (int i = 0; i < 9; i++){
		cin >> input[i];
	}
	
	for (int i = 0; i < 9; i++){
		int tmp = i;
		for (int j = i + 1; j < 9; j++){
			if (input[tmp] > input[j])
				tmp = j;
		}
		swap(input[i], input[tmp]);
	}

	for (int i = 0; i < 8; i++){
		for (int j = i + 1; j < 9; j++){
			
			for (int k = 0; k < 9; k++){
				if (k != i && k != j) {
					sum += input[k];
				}					
			}
			if (sum == 100){
				for (int l = 0; l < 9; l++){
					if (l != i&&l != j)
					cout << input[l] << "\n";
				}
				return 0;
			}				
			sum = 0;
		}
	}
	return 0;
}
