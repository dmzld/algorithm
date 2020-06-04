#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
int cnt = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> str){ // until eof (\n)
		if (str == "<br>"){
			cout << "\n";
		}
		else if (str == "<hr>"){
			if (cnt != 0) cout << "\n";
			for (int i = 0; i < 80; i++)
				cout << '-';
			cout << "\n";
		}
		else{ // words
			if (cnt + str.length() < 80)
				cout << str << " ";
			else{
				cnt = str.length();
				cout << "\n" << str << " ";
			}
		}
	}

	return 0;
}
