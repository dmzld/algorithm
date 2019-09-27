#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int n, m;
	char a[3], b[3];
	char res;

	cin >> n >> m;
	for (int i = 0; i < 3; i++){
		a[i] = (char)(n % 10 + '0');
		b[i] = (char)(m % 10 + '0');
		n /= 10;
		m /= 10;
	}
	
	for (int i = 0; i < 3; i++){
		if (a[i] > b[i]){
			for (int j = 0; j < 3; j++)
				cout << a[j];
			break;
		}
		else if (a[i] < b[i]){
			for (int j = 0; j < 3; j++)
				cout << b[j];
			break;
		}
	}
	return 0;
}
