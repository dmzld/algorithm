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
		
		string str;
		long long ans = 0;
		cin >> str;

		if (str.at(0) == str.at(1))
			ans = 1;
		else
			ans = 2;

		for (int i = 1; i < str.length() - 1; i++){
			int cnt = 0;
			
			if (str.at(i) == str.at(i - 1))
				cnt = 1;
			else
				cnt = 2;

			if (str.at(i + 1) != str.at(i) && str.at(i + 1) != str.at(i - 1))
				cnt++;

			ans = (ans * cnt) % 1000000007;
		}

		if (str.at(str.length() - 1) != str.at(str.length() - 2))
			ans = (ans * 2) % 1000000007;

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
