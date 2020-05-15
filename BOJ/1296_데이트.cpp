#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	

	string me;
	int N;
	string her;
	int L = 0, O = 0, V = 0, E = 0;
	int max = -1;
	string choose;


	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> me >> N;

	for (int j = 0; j < me.length(); j++){
		if (me.at(j) == 'L')L++;
		if (me.at(j) == 'O')O++;
		if (me.at(j) == 'V')V++;
		if (me.at(j) == 'E')E++;

	}

	for (int i = 0; i < N; i++){
		int cL = L, cO = O, cV = V, cE = E;
		int res;
		
		cin >> her;
		
		for (int j = 0; j < her.length(); j++){
			if (her.at(j) == 'L')cL++;
			if (her.at(j) == 'O')cO++;
			if (her.at(j) == 'V')cV++;
			if (her.at(j) == 'E')cE++;
		}

		res = ((cL + cO)*(cL + cV)*(cL + cE)*(cO + cV)*(cO + cE)*(cV + cE)) % 100;
		
		if (max == res){
			max = res;
			if (choose > her)
				choose = her;
		}
		else if (max < res){
			max = res;
			choose = her;
		}
	}


	cout << choose;

	return 0;
}
