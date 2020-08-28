#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int T = 1; T <= 2000; T++){
		cin >> str;

		stack<char> s1, s2;
		int ans = 0,
			l = 0, rest = 0; 

		// exit
		if (str[0] == '-')
			break;

		for (int i = 0; i < str.length(); i++){
			while (i < str.length() && str[i] == '}'){
				rest++;
				i++;
			}

      // it can be pair itself
			if (rest % 2 == 0){
				ans += rest / 2;
				rest -= (rest / 2) * 2;
			}
      // it can be pari itself except 1
			else if (rest % 2 == 1){
				ans += rest / 2 + 1;
				rest = 1;
			}
			
			
			while (i < str.length()){
				if (str[i] == '{'){
					rest++;
				}
				else if (str[i] == '}'){
					rest--;
				}

				if (rest > 0)
					i++;
				else
					break;
			}
			ans += rest / 2;
		}

		cout << T << ". " << ans << "\n";
	}

	return 0;
}
