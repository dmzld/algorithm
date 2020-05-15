#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string N;
int num[10] = { 0, };
int res = 0; 

// for descend
bool cmp(char a, char b){
	if (a > b)
		return true;
	return false;
}

int main(){
	
	getline(cin, N);
	for (int i = 0; i < N.length(); i++)
		num[N[i] - '0']++;
	
	for (int i = 0; i < 10; i++){
		res += (i * num[i]);
	}

	if (res % 3 == 0 && num[0] > 0){
		sort(N.begin(), N.end(), cmp);
		cout << N;
	}
	else
		cout << -1;

	return 0;
}
