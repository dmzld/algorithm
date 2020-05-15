#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main(){

	int K = 0, var = 0, size = 0;
	stack<int> s;
	cin >> K;

	for (int i = 0; i < K; i++){
		cin >> var;
		if (var == 0){
			if (s.size() != 0)
				s.pop();
		}
		else{
			s.push(var);
		}
	}
	var = 0;
	size = s.size();

	for (int i = 0; i < size; i++){
		//cout << "var : " << var << "top" << s.top() << "\n";
		var += s.top();
		s.pop();
	}
	cout << var;

	return 0;
}
