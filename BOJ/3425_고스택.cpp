#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

struct Info{
	string str;
	long long num;
};

vector<Info> v;
string str = "";
long long num, N;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true){
		// input program
		while (true){
			cin >> str;

			if (str == "END")
				break;
			if (str == "QUIT")
				return 0;

			if (str == "NUM")
				cin >> num;
			
			v.push_back({ str, num });
		}

		int vSize = v.size();

		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> num;

			stack<long long> s;
			s.push(num);

			long long tmp;
			long long sign;
			bool avail = false;
			
			for (int j = 0; j < vSize; j++){
				string op = v[j].str;

				// operation
				if (op == "NUM"){
					tmp = v[j].num;
				}
				else if (op == "POP"){
					if (s.empty()){
						avail = true;
						break;
					}
					s.pop();
					continue; // quick continue
				}
				else if (op == "INV"){
					if (s.empty()){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();

					tmp *= -1;
				}
				else if (op == "DUP"){
					if (s.empty()){
						avail = true;
						break;
					}

					tmp = s.top();
				}
				else if (op == "SWP"){
					if (s.size() < 2){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();

					s.push(tmp);
					s.push(tmp2);

					continue; // quick contine
				}
				else if (op == "ADD"){
					if (s.size() < 2){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();
					tmp += s.top();
					s.pop();
				}
				else if (op == "SUB"){
					if (s.size() < 2){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();
					tmp = s.top() - tmp;
					s.pop();
				}
				else if (op == "MUL"){
					if (s.size() < 2){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();
					tmp *= s.top();
					s.pop();
				}
				else if (op == "DIV"){
					if (s.size() < 2 || s.top() == 0){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();

					sign = tmp * s.top();
					tmp = abs(tmp);

					tmp = s.top() / tmp;
					tmp = sign > 0 ? abs(tmp) : -abs(tmp);
					s.pop();
				}
				else if (op == "MOD"){
					if (s.size() < 2 || s.top() == 0){
						avail = true;
						break;
					}
					tmp = s.top();
					s.pop();

					sign = s.top();
					tmp = abs(tmp);

					tmp = s.top() % tmp;
					tmp = sign > 0 ? abs(tmp) : -abs(tmp);
					s.pop();
				}

				// after operation
				if (abs(tmp) > 1000000000){
					avail = true;
					break;
				}

				s.push(tmp);
			}

			// after all of operation
			if (!avail && s.size() == 1)
				cout << s.top() << "\n";
			else
				cout << "ERROR\n";
		}
		cout << "\n";

		v.clear();
	}

	return 0;
}
