#include <iostream>
#include <string>

using namespace std;

int N;
string str[50];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];

	for (int i = 0; i < str[0].length(); i++){
		bool same = true;
		char tmp = str[0][i];
		
		for (int j = 1; j < N;j++)
			if (tmp != str[j][i]){
				same = false;
				break;
			}

		if (same)
			cout << tmp;
		else
			cout << "?";
	}

	return 0;
}
