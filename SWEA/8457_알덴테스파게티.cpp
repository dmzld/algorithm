#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(){

	int TC;

	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		int N, B, E, T, ans = 0;

		cin >> N >> B >> E;
		for (int i = 0; i < N; i++){
			int tmp = 0;
			cin >> T;
			tmp = T;

			while (tmp <= B + E){
				if (tmp >= B - E && tmp <= B + E){
					ans++;
					break;
				}
				else{
					tmp += T;
				}
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
