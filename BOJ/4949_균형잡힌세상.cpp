#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main(){

	string s;
	string dot = ".";

	while (1){
		stack<char> stk;
		getline(cin,s);
		if (s.compare(dot) == 0)
			break;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == '(')
				stk.push('(');
			else if (s[j] == '[')
				stk.push('[');

			else if (s[j] == ')'){
				if (stk.size() > 0){
					if (stk.top() != '('){
						stk.push('n');
						break;
					}
					else
						stk.pop();
				}
				else{
					stk.push('n');
					break;
				}
			}
			else if (s[j] == ']'){
				if (stk.size() > 0){
					if (stk.top() != '['){
						stk.push('n');
						break;
					}
					else
						stk.pop();
				}
				else{
					stk.push('n');
					break;
				}
			}// () []

			else if (s[j]=='.'){
				break;
			}
		}
		if (stk.size() == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
		
	return 0;
}
