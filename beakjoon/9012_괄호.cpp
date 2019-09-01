#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main(){

	int K = 0;
	stack<char> stk;
	string s;
	cin >> K;

	for (int i = 0; i < K; i++){
		cin >> s;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == '('){
				//cout << "push\n";
				stk.push('(');
			}

			else if (s[j] == ')'){
				if (stk.size() > 0){
					if (stk.top() != '('){
						stk.push('n');
						break;
					}
					else{
						//cout << "pop\n";
						stk.pop();
					}
				}
				else{
					stk.push('n');
					break;
				}
			}
			else{
				stk.push('n');
				break;
			}
		}
		if (stk.size() == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		while (!stk.empty())
			stk.pop();
	}

	return 0;
}
