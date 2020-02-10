#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int T;
long long L;

int main(){

  // stream 처리 안하면 시간 초과
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++){

		cin >> L; //  L >= 3, odd

		cout << "#" << i + 1 << " " << (L / 2) * (L / 2) << "\n";

	}

	// aba 1
	// ababa aba bab aba ababa 3 + 1
	// abababa aba bab aba bab aba ababa babab ababa abababa 5 + 3 + 1

	return 0;
}
