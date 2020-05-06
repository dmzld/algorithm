#include <iostream>
#include <cstring>

using namespace std;

int N, w[50], h[50], r[50];

int main(){

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> w[i] >> h[i];
	
	for (int i = 0; i < N; i++){
		r[i] = 1;
		for (int j = 0; j < N; j++){
			if (i == j) continue;

			if (w[i] < w[j] && h[i] < h[j])
				r[i]++;
		}
	}

	for (int i = 0; i < N; i++)
		cout << r[i] << " ";
	cout << "\n";

	return 0;
}
