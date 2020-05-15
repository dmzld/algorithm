#include <iostream>
#include <string>

using namespace std;

int main(){

	string var; // only alphabet & _
	bool J = true, C = true;
	string res = "";

	cin >> var;

	// exeception
	// 1. 대문자로 시작
	// 2. _로 시작
	// 3. _로 끝
	if ((var.at(0) >= 'A' && var.at(0) <= 'Z') || var.at(0) == '_' || var.at(var.length() - 1) == '_'){
		cout << "Error!";
		return 0;
	}
	// 4. 연속 _
	for (int i = 1; i < var.length(); i++){
		if (var.at(i - 1) == '_' && var.at(i) == '_'){
			cout << "Error!";
			return 0;
		}
	}

	// Java?
	for (int i = 1; i < var.length(); i++){
		if (var.at(i) == '_'){
			J = false;
			break;
		}
	}
	if (J){ // 대문자가 최소 1개 있어야함
		J = false;
		for (int i = 1; i < var.length(); i++){
			if (var.at(i) >= 'A' && var.at(i) <= 'Z'){
				J = true;
				break;
			}
		}
	}
	// C++?
	if (C){
		for (int i = 1; i < var.length(); i++){
			if (var.at(i) >= 'A' && var.at(i) <= 'Z'){
				C = false;
				break;
			}
		}
	}

	//result
	if (J&&!C){
		for (int i = 0; i < var.length(); i++){
			if (var.at(i) >= 'A' && var.at(i) <= 'Z'){
				res += '_';
				res += (char)(var.at(i) + 32);
			}
			else
				res += var.at(i);
		}
		cout << res;
	}
	else if (!J&&C){
		for (int i = 0; i < var.length(); i++){
			if (var.at(i) == '_'){
				i++;
				res += (char)(var.at(i) - 32);
			}
			else
				res += var.at(i);
		}
		cout << res;
	}
	else
		cout << "Error!";


	return 0;
}
