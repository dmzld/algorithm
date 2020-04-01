#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	
	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		int N, ans;
		string X; // X is big, so use string
		long res = 0;

		cin >> N >> X;
		for (int i = 0; i < X.length(); i++)
			res += X.at(i) - '0';

		ans = res % (N - 1);
		cout << "#" << tc << " " << ans << "\n";
		
	}

	return 0;
}
