#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int N;
vector<char> eq;
int fres = INT_MIN;

// 괄호 안에는 연산자 하나 => 중복 괄호 X
int calculator(int num1, char op, int num2){
	int res = 0;
	switch (op){
	case '+':
		res = num1 + num2;
		break;
	case '-':
		res = num1 - num2;
		break;
	case '*':
		res = num1 * num2;
		break;
	}
	return res;
}

void sol(int cnt, int cur_res){
	int tmp = cur_res;
	if (cnt == N - 1){
		if (cur_res > fres)
			fres = cur_res;
		return;
	}
	if (cnt + 2 < N){
		cur_res = calculator(tmp, eq[cnt + 1], eq[cnt + 2] - '0');
		sol(cnt + 2, cur_res);

	}
	if (cnt + 4 < N){
		cur_res = calculator(tmp, eq[cnt + 1], calculator(eq[cnt + 2] - '0', eq[cnt + 3], eq[cnt + 4] - '0'));
		sol(cnt + 4, cur_res);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	eq.resize(N);
	for (int i = 0; i < N; i++){
		char tmp;
		cin >> tmp;
		eq[i] = tmp;
	}

	sol(0, eq[0] - '0');

	cout << fres;
}
