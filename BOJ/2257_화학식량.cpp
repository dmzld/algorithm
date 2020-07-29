#include <iostream>
#include <string>

using namespace std;

string str;
int ans = 0, len = 0;
bool check[100] = { false, };

int solution(int idx){
	int res = 0;

	for (int i = idx; i < len; i++){
		if (str[i] == ')')
			break;

		int w = 0;

		if (str[i] == 'H')
			w = 1;
		else if (str[i] == 'C')
			w = 12;
		else if (str[i] == 'O')
			w = 16;
		else if (str[i] == '('){
			w = solution(i + 1);
			while (str[i] != ')' || check[i])
				i++;
			check[i] = true;
		}

		if (str[i + 1] >= '2' && str[i + 1] <= '9'){
			w *= (int)(str[i + 1] - '0');
			i++;
		}

		res += w;
	}

	return res;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	len = str.length();

	ans = solution(0);

	cout << ans;

	return 0;
}
