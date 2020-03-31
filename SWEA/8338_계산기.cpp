#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;

	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		int N, tmp, res = 0;
		cin >> N >> res;
		for (int i = 0; i < N - 1; i++){
			cin >> tmp;
			res = (res + tmp > res*tmp) ? (res + tmp) : (res * tmp);
		}

		cout << "#" << tc << " " << res << "\n";
	}

	return 0;
}
