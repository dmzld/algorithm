#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int T;
string s;
int num[3]; // for a,b,c

int main(){

	cin >> T;

	for (int i = 0; i < T; i++){
		memset(num, 0, sizeof(num));
		cin >> s;

		// 팰린드롬 : A A or A B A 의 형태
		// 새로운 패턴 C를 넣으면서, 이 형태가 되지 않으려면
		// A B C || A B C A || A B C A B
		for (int j = 0; j < s.length(); j++){
			if (s[j] == 'a')
				num[0]++;
			else if (s[j] == 'b')
				num[1]++;
			else if (s[j] == 'c')
				num[2]++;
		}

		if ((num[0] == num[1] && num[1] == num[2])			
			|| (num[0] == num[1] && (num[0] + 1 == num[2] || num[0] - 1 == num[2])) // A B C A or A B C A B
			|| (num[1] == num[2] && (num[1] + 1 == num[0] || num[1] - 1 == num[0])) //  ex) a, ab, abca , abcab
			|| (num[2] == num[0] && (num[2] + 1 == num[1] || num[0] - 1 == num[1])))
			cout << "#" << i + 1 << " YES\n";
		else
			cout << "#" << i + 1 << " NO\n";

	}


	return 0;
}
