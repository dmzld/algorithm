#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int TC;

int main(){

	cin >> TC;
	cin.ignore(); // point :  To use getline(cin, str) after cin, clear buffer because '\n' is remained in buffer 

	for (int tc = 1; tc <= TC; tc++){
		string str;
		int idx = 0;
		char ans[3];

		getline(cin, str);

		ans[idx++] = str.at(0) - 32;
		for (int i = 1; i < str.length(); i++){
			if (str.at(i) == ' '){
				ans[idx++] = str.at(i + 1) - 32;
			}

			if (idx >= 3)
				break;
		}

		cout << "#" << tc << " ";
		for (int i = 0; i < 3; i++)
			cout << ans[i];
		cout << "\n";
	}

	return 0;
}
