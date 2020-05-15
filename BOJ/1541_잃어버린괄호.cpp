#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string eq, tmp;
bool block = false;
int ans = 0;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> eq;
	for (int i = 0; i <= eq.length(); i++){ // **point for last operand
		if (eq[i] == '+' || eq[i] == '-' || eq[i] == NULL){
			if (block)
				ans -= stoi(tmp);
			else
				ans += stoi(tmp);
			tmp = "";

			if (eq[i] == '-') // '-'로 묶어주면 결과가 최소 => 첫 '-'가 나오면 뒤에는 모두 뺄셈 가능
				block = true;
		}
		else
			tmp += eq[i]; // using feature of string with stoi()
	}
	
	cout << ans;
	
	return 0;
}
