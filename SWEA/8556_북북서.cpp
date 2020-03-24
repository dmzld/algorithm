#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

bool check[10];

int TC;
string str;
int n, w;
stack<char> s;

int main(){

	cin >> TC;

	for (int tc = 1; tc <= TC; tc++){

		cin >> str;
		n = 0, w = 0;

		for (int i = 0; i < str.length(); i++){
			if (str.at(i) == 'w'){
				s.push('w');
				i += 3;
			}
			else if (str.at(i) == 'n'){
				s.push('n');
				i += 4;
			}
		}

		int n = s.size() - 1; // maximun n
		int m = 0;

		// first
		if (s.top() == 'w') m = 90 * pow(2, n);
		else if (s.top() == 'n') m = 0;
		s.pop();

		// next west/north
		// 90 + (90/2^1) - (90/2^2) + (90/2^3)
		// 90 * 2^3 + (90/2^1) * 2^3 - (90/2^2) * 2^3 + (90/2^3) * 2^3
		// -----------------------------------------------------------
		// 2^3

		int cnt = n - 1;
		while (!s.empty()){
			if (s.top() == 'w') m += 90 * pow(2, cnt--);
			else if (s.top() == 'n') m -= 90 * pow(2, cnt--);
			s.pop();
		}

		// m == 2^n일때의 분자 상태
		while (m % 2 == 0 && m > 1 && n > 0){
			m /= 2;
			n--;
		}


		if (n == 0)
			cout << "#" << tc << " " << m << "\n";
		else
			cout << "#" << tc << " " << m << "/" << pow(2, n) << "\n";

	}

	return 0;
}
