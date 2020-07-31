#include <iostream>
#include <string>

using namespace std;

string str;
int len = 0;
bool check[50] = { false, };

int solution(int idx){
	int res = 0;

	for (int i = idx; i < len; i++){
		if (str[i] == ')') // exit recursive
			break;
		
		if (i + 1 >= len || str[i + 1] != '(') // str[i] == char
			res++;
		else if (str[i + 1] == '('){ // str[i] == int
			res += (int)(str[i] - '0') * solution(i + 2);

			while (i < len && (str[i] != ')' || check[i]))
				i++;
			check[i] = true;
		}
	}
	return res;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	len = str.length();

	cout << solution(0);

	return 0;
}
