#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> s;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> str;

	if (str == "P"){
		cout << "PPAP\n";
		return 0;
	}

	for (int i = 0; i < str.length(); i++){
		char cc = str[i];

		if (cc == 'P')
			s.push(cc);
		else if (cc == 'A'){
			if (s.empty() || s.top() != 'P' || str[i + 1] != 'P'){
				cout << "NP\n";
				return 0;
			}
			else{
				s.pop();
				i++;
				if (s.empty()){
					cout << "NP\n";
					return 0;
				}
			}
		}
	}

	if (s.size() == 1 && s.top() == 'P')
		cout << "PPAP\n";
	else
		cout << "NP\n";

	return 0;
}
