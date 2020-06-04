#include <iostream>
#include <string>

using namespace std;

int N, K1, K2, order;
string ch[100];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> ch[i];
		if (ch[i] == "KBS1")
			K1 = i;
		if (ch[i] == "KBS2")
			K2 = i;
	}

	for (int i = 0; i < K1; i++)
		cout << 1;
	for (int i = 0; i < K1; i++)
		cout << 4;

	order = K1 < K2 ? 0 : 1;
	for (int i = 0; i < K2 + order; i++)
		cout << 1;

	order = K1 < K2 ? -1 : 0;
	for (int i = 0; i < K2 + order; i++)
		cout << 4;

	return 0;
}
