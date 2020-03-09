#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
string L;
stack<char> s;
stack<char> s2;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++){
		cin >> L;
		
		for (int j = 0; j < L.length(); j++){
			
			char tmp = L.at(j);
			
			switch (tmp){
			case '-': // back space
				if (!s.empty())
					s.pop();
				break;
			case '<': // left
				if (!s.empty()){
					s2.push(s.top());
					s.pop();
				}
				break;
			case '>': // right
				if (!s2.empty()){
					s.push(s2.top());
					s2.pop();
				}
				break;
			default: // syntax
				s.push(tmp);
			}
		}

		// stack => reverse
		while (!s.empty()){
			s2.push(s.top());
			s.pop();
		}
		while (!s2.empty()){
			cout << s2.top();
			s2.pop();
		} cout << "\n";
	}
	
	return 0;
}
